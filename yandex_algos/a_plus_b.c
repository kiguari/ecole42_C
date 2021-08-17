#include <unistd.h>
#include <stdio.h>

int main()
{
    size_t a;
    size_t d;
    size_t c;
    scanf("%zu %zu", &a, &d);
    c = a + d;
    printf("%zu", c);
    return(0);
}
