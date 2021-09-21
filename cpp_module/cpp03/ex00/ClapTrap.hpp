/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:45:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 12:32:55 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string Name;
    unsigned int Hitpoint;
    int Energy_points;
    int Attac_damage;

public:
    ClapTrap();
    ClapTrap( const std::string nome);
    ClapTrap( const ClapTrap &new_name );
    ClapTrap   &operator= (const ClapTrap &new_name);
    void attac(std::string const & target);
    void takeDamage(unsigned int amounth);
    void beRepaired(unsigned int amounth);
    std::string name_geter() const;
    int int_value_geter(int code) const;
    ~ClapTrap();
};

#endif