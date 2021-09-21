/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:19:51 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/20 14:45:36 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::Fixed(const Fixed &fix)
{
    std::cout << "Copy constructor called" << std::endl;
    this->number = fix.getRawBits(); // для Assignation operator called // <-- This line may be missing depending on your implementation
    // *this = fix;
}

Fixed::Fixed( const int inumber )
{
    std::cout << "Int constructor called" << std::endl;
    this->number = inumber << 8;
}

Fixed::Fixed( const float fnumber)
{
    std::cout << "Float constructor called" << std::endl;
    float tmp;
    // this->number = roundf(fnumber * (1 << bits));
    tmp = fnumber * (1 << this->bits);
    this->number = roundf(tmp);
}

Fixed &Fixed::operator= ( const Fixed &fix)
{
    std::cout << "Assignation operator called" << std::endl;
    this->number = fix.getRawBits();
    return (*this);
}

float   Fixed::toFloat( void ) const
{
    return((float) this->number / (1 << bits));
    // return((float) this->number / (float) (1 << bits)); // не обязательно оба значения приводить к флоат, так как это сделает сама программа (неявное приведение к типу), а одну из них, обязательно нужно привести к флоату, так как мне нужен флоат.
    // return (float)(this->number / (1 << bits)); // так он сначала выполнит оперцию с двумя интами и потом уже приведет к флоту.
}

int Fixed::toInt( void ) const
{
    return(this->number >> bits);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->number);
}

void    Fixed::setRawBits( int  const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->number = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream &operator <<(std::ostream &out, const Fixed &out_nimber)
{
    out << out_nimber.toFloat();
    return (out);
}