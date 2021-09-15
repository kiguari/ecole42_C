/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:31:39 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/07 18:25:39 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    ScavTrap a;
    ScavTrap b("GOOF");
    ScavTrap c;
    ScavTrap d("ROOF");
    ScavTrap f = b;
    c = d;
    b.guardGate();
    b.attac(c.name_geter());
    c.takeDamage(10);
    c.beRepaired(10);

    FragTrap pp;
    FragTrap gg("ROOCk");
    FragTrap cc;
    FragTrap hh("WATER");
    FragTrap bb = gg;
    cc = hh;

    cc.name_geter();
    cc.takeDamage(10);
    cc.attac(hh.name_geter());
    cc.beRepaired(10);
    cc.hightFivesGuys();
    
    return 0;
}
