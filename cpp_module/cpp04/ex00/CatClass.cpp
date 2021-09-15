/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:51:17 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:35:37 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass.hpp"

Cat::Cat() : Animal()
{
    this->type = "default cat";
    std::cout << "CatClass default constructor called" << std::endl;
}

Cat::Cat( std::string str)
{
    std::cout << "CatClass value constructor called" << std::endl;
    this->type = str;
}

Cat::Cat( const Cat &new_cat )
{
    std::cout << "CatClass value constructor = called" << std::endl;
    *this = new_cat;
}

Cat &Cat::operator= ( const Cat &new_cat )
{
    std::cout << "CatClass Assignation operator called" << std::endl;
    this->type = new_cat.getType();
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "CatClass " << this->getType() << " sing a song - meeeeeyyy meeeeeeyyy" << std::endl;
}

Cat::~Cat()
{
    std::cout << "CatClass default destructor called" << std::endl;
}
