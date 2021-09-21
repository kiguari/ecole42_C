/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:14:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/16 14:32:28 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactClass.hpp"

cont::cont()
{
	this->index = 0;
}

void cont::indexx(int count)
{
	index = count + 1;
}

void cont::add_cont()
{
	std::cout << "first name: ";
	std::cin >> first_name;
	std::cout << "last name: ";
	std::cin >> last_name;
	std::cout << "nickname: ";
	std::cin >> nickname;
	std::cout << "phone number: ";
	std::cin >> phone_number;
	std::cout << "darkest secret: ";
	std::cin >> darknest_secret;
}

void cont::cout_cont()
{
	std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phone_number << std::endl;
	std::cout << "darkest secret: " << darknest_secret << std::endl;
}

void cont::cout_cont_search()
{
	std::cout << "|";
	std::cout << std::setw(10) << index;
	std::cout << "|";
	cont::make_table_line(first_name);
	cont::make_table_line(last_name);
	cont::make_table_line(nickname);
}

void cont::make_table_line(std::string line)
{
	std::string tmp;
	if(line.length() > 10)
	{
		int i = 0;
		while(i < 9)
		{
			tmp += line[i];
			i++;
		}
		tmp += ".";
		std::cout << std::setw(10) << tmp;
	}
	else
		std::cout << std::setw(10) << line;
	std::cout << "|";
}

cont::~cont()
{}