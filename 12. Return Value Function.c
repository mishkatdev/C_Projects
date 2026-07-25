#include <stdio.h>

int square(int n)
{
    return n*n;
}

int main()
{
    int result = square(5);

    printf("%d", result);

    return 0;
}