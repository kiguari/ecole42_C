/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:33:17 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 15:30:22 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap( const std::string nom);
    ScavTrap( const ScavTrap &new_scav);
    ScavTrap &operator= (const ScavTrap &new_scav);
    void guardGate();
    void attac(std::string const & target);
    ~ScavTrap();
};

#endif