/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:32 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:08:08 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string arms;

public:
    Weapon();
    Weapon(std::string const type);
    void setType(std::string type);
    std::string &getType();
    ~Weapon();   
};

#endif