/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:54:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:32 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnimalClass.hpp"

Animal::Animal()
{
    this->type = "default";
    std::cout << "AnimalClass default constructor called" << std::endl;
}

Animal::Animal( std::string str )
{
    std::cout << "AnimalClass value constructor called" << std::endl;
    this->type = str;
}

Animal::Animal( const Animal &new_animal )
{
    std::cout << "AnimalClass value constructor = called" << std::endl;
    *this = new_animal;
}

Animal &Animal::operator= ( const Animal &new_animal )
{
    std::cout << "AnimalClass Assignation operator called" << std::endl;
    this->type = new_animal.getType();
    return(*this);
}

std::string Animal::getType() const
{
    return(this->type);   
}

void Animal::makeSound() const
{
    std::cout << "AnimalClass makeSound default" << std::endl;
}

Animal::~Animal()
{
    std::cout << "AnimalClass default destructor called" << std::endl;
}