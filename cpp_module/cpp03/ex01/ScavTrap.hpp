/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:33:17 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 15:27:25 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
модификатор наследования установлю public
что бы все модификаторы доступа в родительском классе
остались без изменения
*/

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap( const std::string nom);
    ScavTrap( const ScavTrap &new_scav);
    ScavTrap &operator= (const ScavTrap &new_scav);
    void attac(std::string const & target);
    void guardGate();
    ~ScavTrap();
};

#endif