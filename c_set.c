#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    size_t* m_Set;
    size_t  m_Size;
    size_t  m_Val;
} Set;

void InitializeSet (Set* input)
{   
    input->m_Size = 0;
    input->m_Val = 30;
    input->m_Set = malloc (input->m_Val * sizeof(size_t));
}

void AddToSet (Set* input, size_t element)
{
    size_t i = 0;
    for (; i < input->m_Size; i++)
    {
        if (input->m_Set[i] == element)
            return;
    }
    input->m_Set[input->m_Size++] = element;

    if (input->m_Size == input->m_Val)
    {
        input->m_Val += 30;
        input->m_Set = realloc (input->m_Set, sizeof(size_t) * (input->m_Val));
    }    
}

void FreeSet (Set* input)
{
    free (input->m_Set);
}

int CompSet (const void* e1, const void* e2)
{
    return *((size_t*)e1) - *((size_t*)e2);
}

int main (int argc, char **argv)
{
    srand(time(NULL));
    Set set;
    InitializeSet(&set);
    
    for (int i = 0; i < 30; ++i)
        AddToSet( &set, (rand() % 15 + 1) );

    qsort(set.m_Set, set.m_Size, sizeof(size_t), CompSet);

    printf("Size: %ld\n", set.m_Size);
    for (int i = 0; i < set.m_Size; ++i)
        printf("%ld  ", set.m_Set[i]);

    printf("\n\n");
    FreeSet (&set);
    return 0;
}