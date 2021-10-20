/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:28:11 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/20 16:04:12 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string Name;
    // int attack;

public:
    DiamondTrap();
    DiamondTrap( const std::string nom);
    DiamondTrap( const DiamondTrap &new_diamond);
    DiamondTrap &operator= (const DiamondTrap &new_scav);
    std::string get_name_diamon() const;
    void attac(std::string const & target);
    // int get_attac_diamond() const;
    void whoAmI() const;
    ~DiamondTrap();
};

#endif