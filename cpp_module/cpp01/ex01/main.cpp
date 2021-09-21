/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:40:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:20:49 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies;
    int N;
    int i = 0;
    
    std::cout << "zomdiHorde: ";
    std::cin >> N;
    std::cout << "zombiHorde attack!" << std::endl;

    zombies = zombieHorde(N, "zombi - ");
    
    while(i < N)
    {zombies[i].annunziu();i++;}
    delete [] zombies;

    return(0);    
}