/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:40:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 10:47:57 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void destructor_check_from_function()
{
    Zombie day_z;
    day_z.get_name("2 Derel");
    day_z.annunziu();
}

int main()
{
    Zombie day_y("1 Rick");
    day_y.annunziu();
        
    destructor_check_from_function();

    Zombie *day_zz;
    day_zz = newZombie("3 Mishon");
    day_zz->annunziu();
    delete day_zz;

    randomChump("4 Shon");

    return(0);    
}