/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:31:39 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/20 14:58:42 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed           a;
    Fixed const     b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;

    // Fixed c(1);
    // std::cout << c << std::endl;
	// std::cout << ++c << std::endl;
    // std::cout << c << std::endl;

    // Fixed n(2), g(3);
    // if(n > g)
    //     std::cout << "n > g" << std::endl;
    // else
    //     std::cout << "n < g" << std::endl;

    // float t = 10.55;
    // std::cout << t << " - t" << std::endl;
    // t = t * ( 1 << 8 );
    // std::cout << t << " - t" << std::endl;
    // t++;
    // t = t / ( 1 << 8 );
    // std::cout << t << " - t"<< std::endl;

    return 0;
    
}

/*
Should output something like:

$> ./a.out 0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/