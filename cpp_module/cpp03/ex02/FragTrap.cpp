/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:40:54 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 15:30:46 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() //: ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->Name = "no_namerz";
    this->Hitpoint = 100;
    this->Energy_points = 100;
    this->Attac_damage = 30;
    // std::cout << this->Name << std::endl;
}

FragTrap::FragTrap( const std::string nom) //: ClapTrap(nom)
{
    std::cout << "FragTrap value constructor called" << std::endl;
    this->Name = nom;
    this->Hitpoint = 100;
    this->Energy_points = 100;
    this->Attac_damage = 30;
    // std::cout << this->Name << std::endl;
}

FragTrap::FragTrap( const FragTrap &new_frag) //: ClapTrap(new_frag)
{
    std::cout << "FragTrap value constructor = called" << std::endl;
    *this = new_frag;
}

FragTrap &FragTrap::operator= ( const FragTrap &new_name ) //: ClapTrap(new_name)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    this->Name = new_name.name_geter();
    this->Hitpoint = new_name.int_value_geter(1);
    this->Energy_points = new_name.int_value_geter(2);
    this->Attac_damage = new_name.int_value_geter(3);
    return (*this);
}

void FragTrap::attac(std::string const & target)
{
    std::cout << "FragTrap " << this->Name << " attack " << target << ", causing " << this->Attac_damage << " points of damage!" << std::endl;
}

void FragTrap::hightFivesGuys(void)
{
    std::string in;
    int i = 1;
    while(i <= 5)
    {
        std::cout << "FragTrap " << this->Name << " input " << i << " request: ";
        std::cin >> in;
        std::cout << "FragTrap hightFivesGuys " << i << ": " << in << std::endl;
        i++;
    }
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}