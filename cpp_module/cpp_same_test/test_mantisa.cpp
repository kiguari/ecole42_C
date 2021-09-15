#include <iostream>
#include <string>

int main()
{
    float a = 3.44445;
    a = a * (1 << 8);
    std::cout << a << std::endl;
    a = a / (1 << 8);
    std::cout << a << std::endl;
    return(0);
}