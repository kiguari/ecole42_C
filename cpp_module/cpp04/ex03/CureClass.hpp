/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:32:23 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/07 15:16:48 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURECLASS_HPP
# define CURECLASS_HPP

#include "AMateriaClass.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure( std::string const &new_type);
    Cure( const Cure &new_cure);
    Cure &operator= (const Cure &new_cure);
    AMateria* clone() const;
    void use(ICharacter& target);
    ~Cure(); 
};

#endif