/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:51:47 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 10:19:44 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IceClass.hpp"

Ice::Ice()
{
    this->Amateria_type = "ice";
}

Ice::Ice( std::string const &new_type)
{
    // this->Amateria_type = "Ice";
    if(new_type == "ice")
        this->Amateria_type = new_type;
    else
        this->Amateria_type = "ice";
}

Ice::Ice( const Ice &new_ice)
{
    // this->Amateria_type = "Ice";
    *this = new_ice;
}

Ice &Ice::operator= (const Ice &new_ice)
{
    // this->Amateria_type = new_Ice.Amateria_type;
    this->Amateria_type = new_ice.getType();
    return(*this);
}

AMateria* Ice::clone() const
{
    AMateria *clone = new Ice();
    return(clone);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at  " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {}