/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:11:53 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{}

void HumanB::attack()
{
    if(human_b_wepon)
        std::cout << human_b_name << " attacks with his " << human_b_wepon->getType() << std::endl;
    else
        std::cout << human_b_name << " no weapon! " << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
    human_b_wepon = &new_weapon;
}

HumanB::~HumanB()
{
    this->human_b_name = "default_name";
}

HumanB::HumanB(std::string name)
{
    this->human_b_name = name;
}