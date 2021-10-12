/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:40:10 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 10:19:53 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICECLASS_HPP
# define ICECLASS_HPP

#include "AMateriaClass.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice( std::string const &new_type);
    Ice( const Ice &new_ice);
    Ice &operator= (const Ice &new_ice);
    AMateria* clone() const;
    void use(ICharacter& target);
    ~Ice(); 
};

#endif