/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:26:13 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/15 13:26:11 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
# include <iomanip>

class Conversion
{
private:
    int         flag_point;
    float       f_result;
    char        c_result;
    double      d_result;
    int         i_result;
    std::string string_value;
    int         nan_flag;
    int         flag_char_minis;
    int         flag_non_disp;
    Conversion  ();
    Conversion  ( const Conversion &new_Conversion);
    Conversion  &operator= (const Conversion &new_Conversion);
    void        pars();
    char        to_char();
    int         to_int();
    double      to_double();
    float       to_float();
    
public:
    Conversion( const char *argv);
    void    cast();
    
    class NotDisplaylibleException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class WrongArgvException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class Impossible : public std::exception
    {
    public:
        const char* what() const throw();
    };

    ~Conversion();
};

#endif