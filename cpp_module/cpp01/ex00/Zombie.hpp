/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:25:44 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 10:56:20 by eshakita         ###   ########.fr       */
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

public:
    Zombie();
	Zombie(const std::string& name);
    ~Zombie();
    void get_name(std::string name);
    void annunziu();
};

Zombie	*newZombie(std::string name );
void	randomChump(std::string name );
void	destructor_check_from_function();

#endif