/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:21:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 11:35:13 by eshakita         ###   ########.fr       */
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
