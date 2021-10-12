/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:55:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/06 16:51:57 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogClass.hpp"

Dog::Dog()
{
    this->type = "default dog";
    std::cout << "DogClass default constructor called" << std::endl;
    this->Dog_brain = NULL;
}

Dog::Dog( std::string str )
{
    std::cout << "DogClass value constructor called" << std::endl;
    if(str == "default dog")
        this->type = str + "g";
    else
        this->type = str;
    this->Dog_brain = new Brain("dog idea");
}

Dog::Dog( const Dog &new_dog )
{
    std::cout << "DogClass value constructor = called its deep" << std::endl;
    *this = new_dog;
}

Dog &Dog::operator= ( const Dog &new_dog )
{
    std::cout << "DogClass Assignation operator called its deep" << std::endl;
    this->type = new_dog.getType();
    if(new_dog.type != "default dog")
    {
        this->Dog_brain = new Brain();
        for(int i = 0; i < 100; i++)
        {
            this->Dog_brain->idea_seter(i, new_dog.Dog_brain->idea_geter(i));
        }
    }
    else
        this->Dog_brain = NULL;
    this->type = new_dog.type;
    return(*this);
}

void Dog::makeSound() const
{
    if(Dog_brain)
        std::cout << "DogClass " << this->getType() << " sing a song - gaaaaafff gaaaaafff" << this->Dog_brain->idea_geter(0) << " " << this << std::endl;
    else
        std::cout << "DogClass " << this->getType() << " sing a song - gaaaaafff gaaaaafff" << "i dont have brain" << " " << this << std::endl;
}

Dog::~Dog()
{
    std::cout << "DogClass default destructor called" << std::endl;
    if(this->type != "default dog")
        delete Dog_brain;
}
