/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:21:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 10:51:40 by eshakita         ###   ########.fr       */
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
