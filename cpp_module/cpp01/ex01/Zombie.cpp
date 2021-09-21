/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:21:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:02:36 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::annunziu()
{
	std::cout << nome_zombi << index << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::get_name(std::string name, int i)
{
	nome_zombi = name;
	index = i;
}

Zombie::Zombie()
{
	this->nome_zombi = "nonamerz";
	this->index = 0;
}

Zombie::Zombie(const std::string name)
{
	this->nome_zombi = name;
	this->index = 0;
}

Zombie::~Zombie()
{
	std::cout << nome_zombi << index << " is dead - destructor go" << std::endl;
}
