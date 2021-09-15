/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:55:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:24:43 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogClass.hpp"

Dog::Dog()
{
    this->Animal::type = "default dog";
    std::cout << "DogClass default constructor called" << std::endl;
}

Dog::Dog( std::string str )
{
    std::cout << "DogClass value constructor called" << std::endl;
    this->type = str;
}

Dog::Dog( const Dog &new_dog )
{
    std::cout << "DogClass value constructor = called" << std::endl;
    *this = new_dog;
}

Dog &Dog::operator= ( const Dog &new_dog )
{
    std::cout << "DogClass Assignation operator called" << std::endl;
    this->type = new_dog.getType();
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << "DogClass " << this->getType() << " sing a song - gaaaaafff gaaaaafff" << std::endl;
}

Dog::~Dog()
{
    std::cout << "DogClass default destructor called" << std::endl;
}
