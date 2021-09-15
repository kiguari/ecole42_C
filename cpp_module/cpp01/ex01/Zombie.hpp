/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:25:44 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/01 11:36:29 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    private:
    std::string nome_zombi;
    int index;
    public:
    Zombie(): nome_zombi("nonamerz"), index(0)
    {}
	Zombie(const std::string& name) : nome_zombi(name)
	{}
    ~Zombie()
    {std::cout << nome_zombi << index << " is dead - destructor go" << std::endl;}
    void get_name(std::string name, int i);
    void annunziu();
};

Zombie	*zombieHorde( int N, std::string name );

#endif