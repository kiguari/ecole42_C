/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:27:42 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 14:43:33 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() //: ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->Name = "default_name" ;
    this->ClapTrap::Name = this->Name + "_clap_name";
    this->Hitpoint = this->FragTrap::Hitpoint;
    this->Energy_points = this->ScavTrap::Energy_points;
    this->Attac_damage = this->FragTrap::Attac_damage;
    // this->attack = this->ScavTrap::Attac_damage;
    // std::cout << this->Name << std::endl;
    // std::cout << this->ClapTrap::Name << std::endl;
}

DiamondTrap::DiamondTrap( std::string name) //: ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap value operator called" << std::endl;
    this->Name = name;
    this->ClapTrap::Name = name + "_clap_name";
    this->Hitpoint = this->FragTrap::Hitpoint;
    this->Energy_points = this->ScavTrap::Energy_points;
    this->Attac_damage = this->FragTrap::Attac_damage;
    // this->attack = this->ScavTrap::Attac_damage;
}

DiamondTrap::DiamondTrap( const DiamondTrap &new_diamond)
{
    std::cout << "DiamondTrap Value constructor = called" << std::endl;
    *this = new_diamond;
}

DiamondTrap &DiamondTrap::operator= ( const DiamondTrap &new_diamond )
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
    this->Name = new_diamond.get_name_diamon();
    this->ClapTrap::Name = Name + "_clap_name";
    // this->attack = new_diamond.get_attac_diamond();
    this->Hitpoint = this->FragTrap::Hitpoint;
    this->Energy_points = this->ScavTrap::Energy_points;
    this->Attac_damage = this->FragTrap::Attac_damage;
    return (*this);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap name = " << this->Name << "\tClapTrap name = " << this->ClapTrap::Name << std::endl;
}

std::string DiamondTrap::get_name_diamon() const
{
    return(this->Name);
}

void DiamondTrap::attac(std::string const & target)
{
    this->ScavTrap::attac(target);
    // std::cout << "DiamondTrap " << this->Name << " attack " << target << ", causing " << this->Attac_damage << " points of damage!" << std::endl;
}

// int DiamondTrap::get_attac_diamond() const
// {
//     return(this->attack);
// }

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}