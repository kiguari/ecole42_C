/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:44:17 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:28:48 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>
#include <iostream>

class Karen
{
    private:     
        void debug( void );
        void info( void );
        void warning ( void );
        void error ( void );
        std::string level_arr[4];
    public:
        Karen();
        void complain( std::string level );        
        ~Karen();
};


#endif