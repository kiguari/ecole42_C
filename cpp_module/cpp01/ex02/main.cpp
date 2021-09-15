/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:54:01 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 13:05:51 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string line = "HI THIS IS BRAIN";
    std::string *stringPTR = &line;
    std::string stringREF = line;
    
    std::cout << "string line   adress - " << &line << std::endl;
    std::cout << "stringPTR     adress - " << stringPTR << std::endl;
    std::cout << "stringREF     adress - " << &stringREF << std::endl;
    
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
    
    return (0);
}