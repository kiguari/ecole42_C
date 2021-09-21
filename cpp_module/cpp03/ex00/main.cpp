/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:31:39 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 09:56:13 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap first("Neo");
    ClapTrap second("Smith");
    ClapTrap third;
    ClapTrap fourth = second;
    third = first;
    first.attac(second.name_geter());
    first.takeDamage(10);
    first.beRepaired(10);
    second.attac(first.name_geter());
    second.takeDamage(10);
    return 0;
}
