/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:45 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/21 17:14:09 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
private:
    std::vector<int> v;
    unsigned int N;
    Span    ();
public:
    Span    (const unsigned int new_N);
    Span    &operator=( const Span &new_Span);
    Span    (const Span &new_Span);
    void    addNumber(int num);
    void    BetteraddNumberCycle(unsigned int min, unsigned int max);
    void    BetteraddNumberOneForAll(int num);
    void    show(); 
    int     shortestSpan();
    int     longestSpan();
    class   WrongSize : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class   FullVector : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class   NonFoundSpan : public std::exception
    {
        public:
            const char* what() const throw();
    };  
    class   WrongBeter : public std::exception
    {
        public:
            const char* what() const throw();
    };
    ~Span();    
};

#endif