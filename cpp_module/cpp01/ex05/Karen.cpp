/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:44:20 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 13:18:19 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
    level_arr[0] = "DEBUG";
    level_arr[1] = "INFO";
    level_arr[2] = "WARNING";
    level_arr[3] = "ERROR";
}

void Karen::debug( void )
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info( void )
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error( void )
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain( std::string level )
{
    // typedef void (Karen::*function)(void);
    // function f1[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error}; // массив указателей на функции
    // function f2;
    // int i = 0;
    // while((level_arr[i] != level) && i < 3)
    //     i++;
    // f2 = f1[i];
    // (this->*f2)();

    void (Karen::*function[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error}; // массив указателей на функции
    void (Karen::*function2)(void);
    int i = 0;
    while((level_arr[i] != level) && i < 3)
        i++;
    function2 = function[i];
    (this->*function2)();
}

Karen::~Karen()
{
    std::cout << "destructor called" << std::endl;
}