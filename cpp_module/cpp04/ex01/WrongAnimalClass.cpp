/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimalClass.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:10:19 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:47:05 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimalClass.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "wrong_animal_default";
    std::cout << "WrongAnimalClass default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string str )
{
    std::cout << "WrongAnimalClass value constructor called" << std::endl;
    this->type = str;
}

WrongAnimal::WrongAnimal( const WrongAnimal &new_wrong_animal )
{
    std::cout << "WrongAnimalClass value constructor = called" << std::endl;
    *this = new_wrong_animal;
}

WrongAnimal &WrongAnimal::operator= ( const WrongAnimal &new_wrong_animal )
{
    std::cout << "WrongAnimalClass Assignation operator called" << std::endl;
    this->type = new_wrong_animal.getType();
    return(*this);
}

std::string WrongAnimal::getType() const
{
    return(this->type);   
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimalClass makeSound default" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimalClass default destructor called" << std::endl;
}