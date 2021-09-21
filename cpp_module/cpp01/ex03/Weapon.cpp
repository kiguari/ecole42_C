/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:29 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:12:07 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    this->arms = "nonamerz_gun";
}

Weapon::Weapon(std::string const type)
{
    this->arms = type;
}

void Weapon::setType(std::string type)
{
    arms = type;
}

std::string &Weapon::getType()
{
    return(arms);
}

Weapon::~Weapon()
{}
