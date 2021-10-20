/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:00:57 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/20 18:03:44 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*

*/

int main( void ) 
{
    std::vector<int> arr_i;
    for(int i = 0; i < 10; i++)
        arr_i.push_back(i);
    // try
    // {
    //     easyFind(arr_i, 3);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    if(!easyFind(arr_i, 1))
        std::cout << "Value not find" << std::endl;
    else
        std::cout << "easyfind - find value " << std::endl;
    
    if(!easyFind(arr_i, 10))
        std::cout << "Value not find" << std::endl;
    else
        std::cout << "easyfind - find value " << std::endl;

    std::vector<std::string> arr_str;
    for(int i = 0; i < 10; i++)
    {
        arr_str.push_back("first");
    }
    // try
    // {
    //     easyFind(arr_str, "fds");
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    if(!easyFind(arr_str, "first"))
        std::cout << "Value not find" << std::endl;
    else
        std::cout << "easyfind - find value " << std::endl;
    
    if(!easyFind(arr_str, "gjfkdghjkfd"))
        std::cout << "Value not find" << std::endl;
    else
        std::cout << "easyfind - find value " << std::endl;
        
}
