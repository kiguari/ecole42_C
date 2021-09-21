/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:25 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:08:37 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon      *human_b_wepon;
        std::string human_b_name;
    
    public:
        HumanB();
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
        
        ~HumanB();
};

#endif