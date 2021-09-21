/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:19:30 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/20 14:39:50 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int number;
    static const int bits = 8;

public:
    Fixed();
    Fixed( const int int_number );
    Fixed( const float float_number );
    Fixed( const Fixed &fix );
    // перегрузка конструктора на =
    Fixed   &operator= (const Fixed &fix);
    // + - / * (математические операторы)
    Fixed   operator *(const Fixed &input) const;
    Fixed   operator +(const Fixed &input) const;
    Fixed   operator -(const Fixed &input) const;
    Fixed   operator /(const Fixed &input) const;
    // операторы сравнения
    bool    operator>(const Fixed &input) const;
    bool    operator<(const Fixed &input) const;
    bool    operator!=(const Fixed &input) const;
    bool    operator>=(const Fixed &input) const;
    bool    operator<=(const Fixed &input) const;
    bool    operator==(const Fixed &input) const;
    // инткрементация декрементация
    Fixed   operator ++();      // i++
    Fixed   operator ++(int);   // ++i
    Fixed   operator --();      // i--
    Fixed   operator --(int);   // --i
    // min max функции c перегрузками
    static  Fixed   &min(Fixed &input_first, Fixed &input_second);
    static  Fixed   const&min(Fixed const &input_first, Fixed const &input_second); 
    static  Fixed   &max(Fixed &input_first, Fixed &input_second);
    static  Fixed   const&max(Fixed const &input_first, Fixed const &input_second);    
    
    int     getRawBits( void ) const; // гетер
    void    setRawBits( int  const raw ); // сетер
    float   toFloat( void ) const; 
    int     toInt( void ) const;
    ~Fixed();
};

// перегрузка оператора << для вывода в cout класса
std::ostream  &operator <<(std::ostream &os, const Fixed &out_nimber);

#endif