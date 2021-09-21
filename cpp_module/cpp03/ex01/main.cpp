/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:31:39 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 15:28:44 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap first("Neo");
    ClapTrap second("Smith");
    // ClapTrap third;
    // ClapTrap fourth = second;
    // third = first;
    // std::cout << "---------------------------------" << std::endl;
    first.attac(second.name_geter());
    // second.takeDamage(10);
    // second.attac(first.name_geter());
    // first.takeDamage(10);
    // first.beRepaired(10);
    // std::cout << "---------------------------------" << std::endl;

    ScavTrap a;
    ScavTrap b("GOOF");
    
    // ScavTrap c;
    // ScavTrap d("ROOF");
    // ScavTrap f = b;
    // c = d;
    // std::cout << "---------------------------------" << std::endl;
    // b.guardGate();
    b.attac(a.name_geter());
    // c.takeDamage(10);
    // c.beRepaired(10);
    // std::cout << "---------------------------------" << std::endl;

    // ClapTrap *test;
    // test = new ScavTrap();
    // delete test;
    
    // ScavTrap test1("test1");
    // test1.attac("test2");

    return 0;
}
