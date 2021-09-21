/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:40:51 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/21 15:30:18 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap( const std::string nom);
    FragTrap( const FragTrap &new_frag);
    FragTrap &operator= (const FragTrap &new_frag);
    void hightFivesGuys(void);
    void attac(std::string const & target);
    ~FragTrap();
};

#endif