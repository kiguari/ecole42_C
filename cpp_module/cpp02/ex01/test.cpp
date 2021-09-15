#include <iomanip>
#include <iostream>
#include <cmath>

int main()
{
    float a = 3.91232323;
    int c;
    c = 1 << 8;
    c = a * (1 << 8);
    c = c >> 8;
    // c = roundf(a * (1 << 8));
    // c = c >> 8;
    // a = a * (3 << 8);
    std::cout << a << std::endl;
    std::cout << c << std::endl;
    int b = 5;
    b = b << 8;
    b = b >> 8;
    std::cout << b << std::endl;
    return(0);
}