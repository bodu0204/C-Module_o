#include "debug.h"
#include <limits.h>
void f(size_t i, int *b);

int main (void)
{
    int b;
    for (size_t i = 0; i < SIZE_T_MAX - 2; i++)
    {
        f(i, &b);
    }
}

void f(size_t i, int *b)
{
    int a[i];

    a[i + 1024] = 42;
    *b = a[i + 1024];
}


/* 
6125368464
6125352060

 */