#include <unistd.h>
#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int x;
    int i;
    scanf("%d %d %d", &a, &b, &c);
    if(c < 0)
    {
        printf("NO SOLUTION");
        return(0);
    }
    c = c * c - b;
    if(c == 0 && a == 0)
    {
        printf("MANY SOLUTIONS");
        return(0);
    }
    if (a == 0)
    {
        printf("NO SOLUTION");
        return(0);
    }
    i = c % a;
    if(i)
    {
        printf("NO SOLUTION");
        return(0);
    }
    x = c / a;
    printf("%d", x);
    return(0);
}