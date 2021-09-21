/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:16:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/16 14:36:24 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhonebookClass.hpp"

phonebook::phonebook()
{
	this->count = 0; 
	this->last_cont = 0;
}

void phonebook::add_to_phonebook()
{
	if(count == 8)
		count = 0;
	cont[count].add_cont();
	cont[count].indexx(count);
	count++;
	if(last_cont != 8)
		last_cont++;
}

void phonebook::add_cout_cont()
{
	cont[count - 1].cout_cont();
}

void phonebook::ft_search()
{
	std::string j;
	int k = 0;
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "|-------------------------------------------|\n";
	int i = 0;
	while(i < last_cont)
	{
		cont[i].cout_cont_search();
		std::cout << "\n";
		i++;
	}
	std::cout << "|-------------------------------------------|\n";
	std::cout << "choose index: ";
	std::cin >> j;
	if(j != "1" && j != "2" && j != "3" && j != "4" && j != "5" && j != "6" && j != "7" && j != "8")
	{
		std::cout << "error: wrong index walue" << std::endl;
		return;
	}
	k = std::atoi(j.c_str());
	if(k > last_cont)
	{
		std::cout << "error: wrong index walue" << std::endl;
		return;
	}
	cont[k - 1].cout_cont(); 
}

phonebook::~phonebook()
{}
