/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:21:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 10:51:56 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::annunziu()
{
	std::cout << nome_zombi << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::get_name(std::string name)
{
	nome_zombi = name;
}

Zombie::Zombie()
{
	this->nome_zombi = "nonamerz";
}

Zombie::Zombie(const std::string& name)
{
	this->nome_zombi = name;
}

Zombie::~Zombie()
{
	std::cout << nome_zombi << " is dead - destructor go" << std::endl;
}
