/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:59:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/31 13:32:00 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_class.hpp"

int main()
{
    cont cont;
    phonebook pb;
    std::string command;
    
    std::cout << "Hello in phonebook" << std::endl;
    std::cout << "Pleas use passible command: ADD, SEARCH, EXIT" << std::endl;
    while(1)
    {
        std::cout << "phonebook: ";
        std::cin >> command;
        if(std::cin.eof())
            break;
        if(command == "ADD")
            pb.add_to_phonebook();
        else if(command == "SEARCH")
            pb.ft_search();
        else if(command == "EXIT")
            return(0);
        else
            std::cout << "error: wrong command" << std::endl;
    }
    return (0);
}