#include <stdio.h>
#include <string.h>
#include <conio.h>

#define Size(x,T) (sizeof(x)/sizeof(T))

#define Swap(x,y,T) {T var; var = y; y = x; x = var;}
 
#define Inverse(x, T) {int k = (int)(Size(x,T)-1) ;       \
for(int i = 0; i < k/2; ++i) {Swap(x[i], x[k-i-1],T)} }   \

int main(int argc, char const *argv[])
{
    char name[] = "1 2 3 4 5 6";
    printf("%s", name);
    printf("\n%d", Size(name,char)-1);
    Inverse(name, char);
    printf("\n%s", name);
    getch();
    return 0;
}