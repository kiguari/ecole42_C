/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:12:19 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 17:26:28 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon      *human_a_wepon;
        std::string human_a_name;

    public:
        HumanA();
        HumanA(std::string name, Weapon &weapon) : human_a_wepon(&weapon), human_a_name(name)
        {}
        
        void attack();
        
        ~HumanA();
};

#endif