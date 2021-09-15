/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:19:51 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/03 17:27:02 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const Fixed &fix)
{
    std::cout << "Copy constructor called" << std::endl;
    // this->number = fix.getRawBits(); / для Assignation operator called // <-- This line may be missing depending on your implementation
    *this = fix;
}

Fixed &Fixed::operator= ( const Fixed &fix)
{
    std::cout << "Assignation operator called" << std::endl;
    this->number = fix.getRawBits();
    return (*this);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->number);
}

void    Fixed::setRawBits( int  const raw )
{
    // std::cout << "";
    this->number = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}