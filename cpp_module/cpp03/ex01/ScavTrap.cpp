/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:19:00 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 15:27:48 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
/*
При создании объекта класса ScavTrap который является наследником класса ClapTrap 
при вызове конструктора, мы можем переопределить так же вызов какой именно конструктор 
будет вызываться для ClapTrap.

Если этого не делать, то всегда будет вызываться дефолтный конструктор, 
что по сути в данном проекте мне не мешает, так как имею доступ ко всем полям 
родительского класса и могу задать им значения из конструктора наследника, ScavTrap.
*/
ScavTrap::ScavTrap() //: ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    // this->ClapTrap::Name = "no_namerz";
    this->Name = "no_namerz";
    this->Hitpoint = 100;
    this->Energy_points = 50;
    this->Attac_damage = 20;
    // std::cout << this->Name << std::endl;
}

ScavTrap::ScavTrap( const std::string nom) //: ClapTrap(nom)
{
    std::cout << "ScavTrap value constructor called" << std::endl;
    this->Name = nom;
    this->Hitpoint = 100;
    this->Energy_points = 50;
    this->Attac_damage = 20;
    // std::cout << this->Name << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &new_scav) //: ClapTrap(new_scav)
{
    std::cout << "ScavTrap Value constructor = called" << std::endl;
    *this = new_scav;
}

ScavTrap &ScavTrap::operator= ( const ScavTrap &new_name ) //: ClapTrap(new_name)
{
    std::cout << "Assignation operator called" << std::endl;
    this->Name = new_name.name_geter();
    this->Hitpoint = new_name.int_value_geter(1);
    this->Energy_points = new_name.int_value_geter(2);
    this->Attac_damage = new_name.int_value_geter(3);
    return (*this);
}

void ScavTrap::attac(std::string const & target)
{
    std::cout << "ScavTrap " << this->Name << " attack " << target << ", causing " << this->Attac_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " have enterred in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}