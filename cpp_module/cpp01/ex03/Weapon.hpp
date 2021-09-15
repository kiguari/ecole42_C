/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:32 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 17:26:14 by eshakita         ###   ########.fr       */
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
        Weapon(): arms("nonamerz")
        {}
        Weapon(std::string const &type) : arms(type)
        {}
        
        void setType(std::string type);
        std::string &getType();
        
        ~Weapon();   
};

#endif