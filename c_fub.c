#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define INLINE inline __attribute__((__always_inline__))

typedef struct m_Matrix {
    size_t *data;
    size_t  size;
} Matrix;

INLINE size_t Point(size_t x, size_t y, size_t N)
{
    return x + (y * N);
}

char *Result (Matrix input)
{
    size_t val = (4 * input.size * input.size) + 2;
    size_t pos = 0;
    char *res = malloc (val * sizeof (char));
    for (size_t i = 0; i < input.size; ++i)
    {
        for (size_t j = 0; j < input.size; ++j)
        {
            pos += sprintf(res + pos, "%d ", input.data[Point(i,j,input.size)]);
        }
        pos += sprintf(res + pos, "\n");
    }
    res[pos] = '\0';
    return res;
}

void FillMatrix (Matrix input)
{
    srand(time(NULL));
    for (size_t i = 0; i < input.size; i++)
    {
        for (size_t j = 0; j < input.size; j++)
            input.data[Point(i,j,input.size)] = rand() % 10;
    }
}

void InitializeMatrix (Matrix* input, size_t val)
{
    input->size = val;
    input->data = malloc(input->size * input->size * sizeof(size_t));
}

int main (int argc, char* argv[])
{
    Matrix m1;
    size_t val = (size_t) atoi(argv[1]);
    if (val > 1)
    {
        InitializeMatrix (&m1, val);
        FillMatrix(m1);
        char *text = Result(m1);
        printf ("Result\n\n%s\n", text);
        free(m1.data);
        free(text);
    }
    return 0;
}