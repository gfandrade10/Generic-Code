#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dynamic arrar def.
typedef struct MyVector {
    void   *m_Data;
    size_t  m_Size;
} MyVector;

//allocate memory for vector
#ifndef ALLOC_VECTOR
    #define ALLOC_VECTOR(VECTOR, TYPE, SIZE) do {               \
            VECTOR.m_Size = SIZE;                               \
            VECTOR.m_Data = malloc(sizeof(TYPE)*SIZE);          \
        } while(0);
#endif

//free memory of vector
#ifndef VEC_Free
    #define VEC_Free(Data) free(Data.m_Data);
#endif

//expand array allocated size
#ifndef VECTOR_EXPAND
    #define VECTOR_EXPAND(DATA, INC_SIZE, TYPE) do {                                         \
        TYPE* new_ptr;                                                                       \
        new_ptr = realloc(DATA.m_Data, (DATA.m_Size + INC_SIZE)*sizeof(TYPE));               \
        if (new_ptr != NULL)                                                                 \
           { DATA.m_Data = new_ptr; DATA.m_Size += INC_SIZE; }                               \
        else                                                                                 \
            { free (new_ptr); return EXIT_FAILURE; }                                         \
        } while(0); 
#endif
//end of definitions

//testing functions
void FillVector(MyVector *Vec)
{
    for(size_t i = 0; i < Vec->m_Size; i++)
        ((size_t*)Vec->m_Data)[i] = i+1;
}

size_t SumOfVector(MyVector *Vec)
{
    size_t sum = 0;
    for(size_t i = 0; i < Vec->m_Size; i++)
        sum += ((size_t*)Vec->m_Data)[i];
    return sum;
}

void PrintVector(MyVector *Vec)
{
    for(size_t i = 0; i < Vec->m_Size; ++i)
        printf("%d\t", ((size_t*)Vec->m_Data)[i]);
    printf("\n");
}
//end of testing f's

int main(int argc, char **argv)
{
    size_t n = atol(argv[1]);
    MyVector Data1;
    ALLOC_VECTOR(Data1, size_t, n);
    VECTOR_EXPAND(Data1, 2, size_t);
    FillVector(&Data1);
    size_t Sum = SumOfVector(&Data1);
    PrintVector(&Data1);
    printf("%d\n\n",Sum);
    VEC_Free(Data1);
    return 0;
}