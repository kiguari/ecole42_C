/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:51:17 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/06 16:50:55 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass.hpp"

Cat::Cat() : Animal()
{
    this->type = "default cat";
    std::cout << "CatClass default constructor called" << std::endl;
    this->Cat_brain = NULL;
}

Cat::Cat( std::string str)
{
    std::cout << "CatClass value constructor called" << std::endl;
    if(str == "default cat")
        this->type = str + "t";
    else
        this->type = str;
    this->Cat_brain = new Brain("cat idea");
}

Cat::Cat( const Cat &new_cat )
{
    std::cout << "CatClass value constructor = called its deep" << std::endl;
    *this = new_cat;
    // if(new_cat.type != "default cat") 
    //     this->Cat_brain = new Brain("idea");
    // else
    //     this->Cat_brain = NULL;
    // this->type = new_cat.type;
}

Cat &Cat::operator= ( const Cat &new_cat )
{
    std::cout << "CatClass Assignation operator called its deep" << std::endl;
    this->type = new_cat.getType();
    if(new_cat.type != "default cat") 
    {
        this->Cat_brain = new Brain();
        for(int i = 0; i < 100; i++)
        {
            this->Cat_brain->idea_seter(i, new_cat.Cat_brain->idea_geter(i));
        }
    }
    else
        this->Cat_brain = NULL;
    this->type = new_cat.type;
    return(*this);
}

void Cat::makeSound() const
{
    if(Cat_brain)
        std::cout << "CatClass " << this->getType() << " sing a song - meeeeeyyy meeeeeeyyy " << this->Cat_brain->idea_geter(0) << " " << this << std::endl;
    else
        std::cout << "CatClass " << this->getType() << " sing a song - meeeeeyyy meeeeeeyyy " << "i dont have brain" << " " << this << std::endl;
}

Cat::~Cat()
{
    std::cout << "CatClass default destructor called" << std::endl;
    if(this->type != "default cat")
        delete Cat_brain;
}
