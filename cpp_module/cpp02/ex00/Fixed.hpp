/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:19:30 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/20 14:03:17 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int number;
    static const int bits = 8;
    
public:
    Fixed();
    Fixed(const Fixed &fix);
    Fixed   &operator= (const Fixed &fix);
    int     getRawBits( void ) const;
    void    setRawBits( int  const raw );
    ~Fixed();
};

#endif