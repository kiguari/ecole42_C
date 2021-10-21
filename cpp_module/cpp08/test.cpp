#include <iostream>
#include <vector>

int     main()
{
    std::vector<int> v;
    for(int i = 0; i < 5; i++)
        v.push_back(i + 2);
    // for(int i = 0; i < 5; i++)
    //     v.
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        std::cout << *i << ' ';
    std::vector<int> c(4, 8);
    return(0);
}