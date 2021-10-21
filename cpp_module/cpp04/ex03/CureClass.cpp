/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:47:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/21 16:24:33 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CureClass.hpp"

Cure::Cure()
{
    this->Amateria_type = "cure";
}

Cure::Cure( std::string const &new_type)
{
    if(new_type == "cure")
        this->Amateria_type = new_type;
    else
        this->Amateria_type = "cure";
}

Cure::Cure( const Cure &new_cure)
{
    // if(new_cure.getType() == "Cure")
        // this->Amateria_type = new_cure.Amateria_type;
    // else
    //     this->Amateria_type = "Cure";
    *this = new_cure;
}

Cure &Cure::operator= (const Cure &new_cure)
{
    // this->Amateria_type = "Cure";
    // this->Amateria_type = new_cure.Amateria_type;
    this->Amateria_type = new_cure.getType();
    return(*this);
}

AMateria* Cure::clone() const
{
    AMateria *clone = new Cure;
    return(clone);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {}