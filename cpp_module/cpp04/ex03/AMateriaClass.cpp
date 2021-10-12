/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:08:00 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 09:57:29 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateriaClass.hpp"

AMateria::AMateria()
{
    // std::cout << "AmateriaClass default constructor called" << std::endl;
    this->Amateria_type = "default";
}

AMateria::AMateria( std::string const & type)
{
    this->Amateria_type = type;
}

AMateria::AMateria( const AMateria &new_amateria)
{
    *this = new_amateria;
}

AMateria &AMateria::operator=( const AMateria &new_amateria)
{
    this->Amateria_type = new_amateria.getType();
    return(*this);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

std::string const &AMateria::getType() const
{
    return(this->Amateria_type);
}