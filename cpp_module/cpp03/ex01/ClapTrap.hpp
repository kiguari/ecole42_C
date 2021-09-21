/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:45:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 15:27:16 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
// # include <iomanip>
#include <string>
// #include "ScavTrap.hpp"

class ClapTrap
{
    /*
    могу сделать данное поле private, 
    но тогда при обращении к этим полям из класса наслденика,
    мне прийдется обращаться к ним через гетеры и сетере. 
    Если же установлю модификатор доступа - protected,
    то буду иметь к ним доступ из класса наследника.
    */
   
protected: 
    std::string Name;
    unsigned int Hitpoint;
    int Energy_points;
    int Attac_damage;
        
public:
    ClapTrap();
    ClapTrap( const std::string nome);
    ClapTrap( const ClapTrap &new_name );
    ClapTrap   &operator= (const ClapTrap &new_name);
    virtual void attac(std::string const & target);
    void takeDamage(unsigned int amounth);
    void beRepaired(unsigned int amounth);
    std::string name_geter() const;
    int int_value_geter(int code) const;
    /*
    Деструктор родительского класса нужно сделать виртуальным
    что бы при таком кейсе:
    ClapTrap *test;
    test = new ScavTrap();
    delete test;
    вызывался деструткор и родителя и дочки
    */
    virtual ~ClapTrap();
};

#endif