/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:16 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 17:26:59 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{}

void HumanA::attack()
{
    std::cout << human_a_name << " attacks with his " << human_a_wepon->getType() << std::endl;
}

HumanA::~HumanA()
{}
