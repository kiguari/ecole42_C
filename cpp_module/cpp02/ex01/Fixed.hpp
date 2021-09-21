/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:19:30 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/20 14:17:12 by eshakita         ###   ########.fr       */
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
    Fixed( const int inumber );
    Fixed( const float fnumber );
    Fixed( const Fixed &fix );
    Fixed   &operator= (const Fixed &fix);
    int     getRawBits( void ) const;
    void    setRawBits( int  const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
    ~Fixed();
};

std::ostream  &operator <<(std::ostream &os, const Fixed &out_nimber);

#endif