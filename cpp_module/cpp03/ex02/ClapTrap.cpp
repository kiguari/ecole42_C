/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:45:31 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 13:20:52 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    Name = "no_namerz";
    Hitpoint = 10;
    Energy_points = 10;
    Attac_damage = 0;
}

ClapTrap::ClapTrap( const std::string nome)
{
    std::cout << "ClapTrap Value constructor called" << std::endl;
    Name = nome;
    Hitpoint = 10;
    Energy_points = 10;
    Attac_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &new_name)
{
    std::cout << "ClapTrap Value constructor = called" << std::endl;
    *this = new_name;
}

ClapTrap &ClapTrap::operator= ( const ClapTrap &new_name )
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    this->Name = new_name.name_geter();
    this->Hitpoint = new_name.int_value_geter(1);
    this->Energy_points = new_name.int_value_geter(2);
    this->Attac_damage = new_name.int_value_geter(3);
    return (*this);
}

void ClapTrap::attac(std::string const & target)
{
    std::cout << "ClapTrap " << this->Name << " attack " << target << ", causing " << this->Attac_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amounth )
{
    // std::cout << "ClapTrap " << this->Name << " take damage " << std::endl;
    if(amounth == 0)
        std::cout << "ClapTrap " << this->Name << " armor - is not pierced" << std::endl;
    else if(this->Hitpoint <= 0)
        std::cout << "ClapTrap " << this->Name << " is dead " << std::endl;
    else if(amounth >= this->Hitpoint)
    {
        this->Hitpoint = 0;
        std::cout << "ClapTrap " << this->Name << " is dead " << std::endl;
    }
    else if(amounth < Hitpoint)
    {
        this->Hitpoint -= amounth;
        std::cout << "ClapTrap " << this->Name << " take damage " << std::endl;
    }
}

std::string ClapTrap::name_geter() const
{
    return(this->Name);
}

int ClapTrap::int_value_geter(int code) const
{
    if(code == 1)
        return(Hitpoint);
    else if(code == 2)
        return(Energy_points);
    else if(code == 3)
        return(Attac_damage);
    else
        return(Hitpoint);
}

void ClapTrap::beRepaired(unsigned int amounth)
{
    // std::cout << "ClapTrap " << this->Name << " be Repair" << std::endl;
    if(Hitpoint <= 0)
        std::cout << "ClapTrap " << this->Name << " is dead " << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->Name << " be Repair" << std::endl;
        this->Hitpoint += amounth;
    }  
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}