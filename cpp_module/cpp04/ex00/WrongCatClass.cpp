/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCatClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:12:41 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:36:49 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCatClass.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "wrong cat default";
    std::cout << "CatClass default constructor called" << std::endl;
}

WrongCat::WrongCat( std::string str )
{
    std::cout << "WrongCatClass value constructor called" << std::endl;
    this->type = str;
}

WrongCat::WrongCat( const WrongCat &new_cat )
{
    std::cout << "WrongCatClass value constructor = called" << std::endl;
    *this = new_cat;
}

WrongCat &WrongCat::operator= ( const WrongCat &new_cat )
{
    std::cout << "WrongCatClass Assignation operator called" << std::endl;
    this->type = new_cat.getType();
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCatClass default destructor called" << std::endl;
}