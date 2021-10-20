/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:31:39 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/20 16:04:23 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ScavTrap.hpp"
// #include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    // ClapTrap first("Neo");
    // ClapTrap second("Smith");
    // ClapTrap third;
    // ClapTrap fourth = second;
    // third = first;
    // first.attac(second.name_geter());
    // first.takeDamage(10);
    // first.beRepaired(10);
    // second.attac(first.name_geter());
    // second.takeDamage(10);

    // ScavTrap five;
    // ScavTrap six("GOOF");
    // ScavTrap seven;
    // ScavTrap eith("ROOF");
    // ScavTrap nine = six;
    // seven = eith;
    // six.guardGate();
    // six.attac(seven.name_geter());
    // seven.takeDamage(10);
    // seven.beRepaired(10);

    // FragTrap pp;
    // FragTrap gg("ROOCk");
    // FragTrap cc;
    // FragTrap hh("WATER");
    // FragTrap bb = gg;
    // cc = hh;

    // cc.name_geter();
    // cc.takeDamage(10);
    // cc.attac(hh.name_geter());
    // cc.beRepaired(10);
    // cc.hightFivesGuys();
    
    // DiamondTrap monstr("monstr");
    // DiamondTrap qwe;
    // DiamondTrap www = monstr;
    // DiamondTrap eee("eee");
    // DiamondTrap sss;

    
    // sss = eee;
    // monstr.get_attac_diamond();
    // std::cout << monstr.get_attac_diamond() << std::endl;
    // qwe.guardGate();
    // qwe.beRepaired(10);
    // qwe.hightFivesGuys();
    // std::cout << sss.get_name_diamon() << std::endl;
    // monstr.whoAmI();
    // qwe.whoAmI();
    // www.whoAmI();
    // eee.whoAmI();
    // sss.whoAmI();

    // void DiamondTrap::attack(const std::string &target) {
    // this->ScavTrap::attack(target);
    // DiamondTrap test1("test1");
    
    // ClapTrap *test;
    // test = new DiamondTrap();
    // delete test;
    
    DiamondTrap test2("test1");
    // std::cout << test2.name_geter() << std::endl;
    // std::cout << test2.get_name_diamon() << std::endl;
    test2.attac("dfg");
    test2.whoAmI();
    test2.guardGate();
    return 0;
}
