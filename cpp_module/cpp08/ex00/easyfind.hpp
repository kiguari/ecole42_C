/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:45 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/20 17:59:09 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

class NotFind : public std::exception
{
    public:
        const char* what() const throw() {return("Value not find");}
};

template <typename T, typename T2> // 
bool easyFind(T array, T2 value) //
{
    for(typename T::iterator i = array.begin(); i != array.end(); ++i)
    {
        if(*i == value)
        {
            // std::cout << "easyfind - find value " << value << std::endl;
            return true;
        }
    }
    // throw NotFind();
    return(false);
}

#endif