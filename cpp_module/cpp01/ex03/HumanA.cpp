/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:16 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:13:50 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{
    this->human_a_name = "default_humanA_name";
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
    this->human_a_wepon = &weapon;
    this->human_a_name = name;
}

void HumanA::attack()
{
    std::cout << human_a_name << " attacks with his " << human_a_wepon->getType() << std::endl;
}

HumanA::~HumanA()
{}
