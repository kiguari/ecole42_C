/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:19:51 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/20 14:48:41 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// конструкторы

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::Fixed(const Fixed &fix)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->number = fix.getRawBits(); // для Assignation operator called // <-- This line may be missing depending on your implementation
    // *this = fix;
}

Fixed::Fixed( const int inumber )
{
    // std::cout << "Int constructor called" << std::endl;
    this->number = inumber << 8;
    // this->number = inumber;
}

Fixed::Fixed( const float fnumber)
{
    // std::cout << "Float constructor called" << std::endl;
    float tmp;
    // this->number = roundf(fnumber * (1 << bits));
    tmp = fnumber * (1 << this->bits);
    this->number = roundf(tmp);
}

Fixed &Fixed::operator= ( const Fixed &fix)
{
    // std::cout << "Assignation operator called" << std::endl;
    this->number = fix.getRawBits();
    return (*this);
}

// с первого задания (гетер, сетер, то инт, то флоат)
float   Fixed::toFloat( void ) const
{
    return((float) this->number / (1 << bits));
    // return((float) this->number / (float) (1 << bits)); // не обязательно оба значения приводить к флоат, так как это сделает сама программа (неявное приведение к типу), а одну из них, обязательно нужно привести к флоату, так как мне нужен флоат.
    // return (float)(this->number / (1 << bits)); // так он сначала выполнит оперцию с двумя интами и потом уже приведет к флоту.
}

int Fixed::toInt( void ) const
{
    // return(this->number);
    return(this->number >> bits);
}

int     Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return(this->number);
}

void    Fixed::setRawBits( int  const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->number = raw;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

// перегрузка оператора для вывода 
std::ostream &operator <<(std::ostream &out, const Fixed &out_nimber)
{
    out << out_nimber.toFloat();
    // out << out_nimber.toInt();
    return (out);
}

// перегрузка операторов (мат операции)
Fixed Fixed::operator*(const Fixed &input) const
{
    Fixed output;
    int result = (this->getRawBits() * input.getRawBits() / (1 << input.bits));
    // result = result >> 8;
    output.setRawBits(result);
    return(output);
}

Fixed Fixed::operator+(const Fixed &input) const
{
    Fixed output;
    int result = this->getRawBits() + input.getRawBits();
    // result = result >> 8;
    output.setRawBits(result);
    return(output);
}

Fixed Fixed::operator-(const Fixed &input) const
{
    Fixed output;
    int result = this->getRawBits() - input.getRawBits();
    // result = result >> 8;
    output.setRawBits(result);
    return(output);
}

Fixed Fixed::operator/(const Fixed &input) const
{
    Fixed output;
    int result = (this->getRawBits() * (1 << output.bits) / input.getRawBits());
    // result = result >> 8;
    output.setRawBits(result);
    return(output);
}

// перегрузка операторов сравнения
bool      Fixed::operator>(const Fixed &input) const 
{
    return(this->getRawBits() > input.getRawBits());
}

bool      Fixed::operator<(const Fixed &input) const 
{
    return(this->getRawBits() < input.getRawBits());
}

bool      Fixed::operator>=(const Fixed &input) const 
{
    return(this->getRawBits() >= input.getRawBits());
}

bool      Fixed::operator<=(const Fixed &input) const 
{
    return(this->getRawBits() <= input.getRawBits());
}

bool      Fixed::operator!=(const Fixed &input) const 
{
    return(this->getRawBits() != input.getRawBits());
}

bool      Fixed::operator==(const Fixed &input) const 
{
    return(this->getRawBits() == input.getRawBits());
}

// инкрементация и декрементация
Fixed Fixed::operator++()
{
    this->number++;
    return(*this);
}

Fixed Fixed::operator--()
{
    this->number--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed out(*this);
    this->number++;
    return(out);
}

Fixed Fixed::operator--(int)
{
    Fixed out(*this);
    this->number--;
    return(out);
}

// min max функции
Fixed &Fixed::min(Fixed &input_first, Fixed &input_second)
{
    if(input_first < input_second)
        return(input_first);
    return(input_second);
}

Fixed &Fixed::max(Fixed &input_first, Fixed &input_second)
{
    if(input_first > input_second)
        return(input_first);
    return(input_second);
}

Fixed const&Fixed::min(const Fixed &input_first, const Fixed &input_second)
{
    if(input_first < input_second)
        return(input_first);
    return(input_second);
}

Fixed const&Fixed::max(const Fixed &input_first, const Fixed &input_second)
{
    if(input_first > input_second)
        return(input_first);
    return(input_second);
}
