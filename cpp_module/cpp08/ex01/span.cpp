/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:44:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/26 18:01:02 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{}

Span::Span(const Span &new_Span)
{
    this->N = new_Span.N;
    this->v = new_Span.v;
}

Span::Span(const unsigned int new_N)
{
    this->N = new_N;
    if(N == 0)
        throw WrongSize();
}

Span &Span::operator=( const Span &new_Span)
{
    this->N = new_Span.N;
    this->v = new_Span.v;
    return(*this);
}

int Span::longestSpan()
{
    if(v.size() <= 1)
        throw NonFoundSpan();
    std::vector<int> for_sort = v;
    std::sort(for_sort.begin(), for_sort.end());
    std::vector<int>::iterator second = for_sort.end() - 1;
    std::vector<int>::iterator first = for_sort.begin();
    int res = *second - *first;
    return(res);
}

int Span::shortestSpan() // здесь ошибка вычитаю из второго элемента первый, нужно искать самую маленьку разницу из всех соседних элементов, нужно реализовать через два цикла.
{
    if(v.size() <= 1)
        throw NonFoundSpan();
    std::vector<int> for_sort = v;
    std::sort(for_sort.begin(), for_sort.end());
    std::vector<int>::iterator second = ++for_sort.begin();
    std::vector<int>::iterator first = for_sort.begin();
    int res = *second - *first;
    return(res);
}

void Span::addNumber(int num)
{
    if(v.size() >= N)
        throw FullVector();
    v.push_back(num);
}

void    Span::BetteraddNumberCycle(unsigned int min, unsigned int max)
{
    if(min < max)
    {
        if(max - min != this->N - 1)
            throw WrongBeter();
        for(int i = min; max >= min; min++)
        {
            if(this->v.size() > N)
                throw FullVector();
            this->v.push_back(i);
            i++;
        }
        return;
    }
    throw WrongBeter();
}

void    Span::BetteraddNumberOneForAll(int num)
{
    if(this->v.size() >= N)
        throw WrongBeter();
    if(!this->v.size())
    {
        std::vector<int> tmp(this->N, num);
        this->v = tmp;
    }
    else
    {
        while(this->v.size() != N)
            this->v.push_back(num);
    }
}

// реализовал метод которого нет в сабджкте, для самопроверки
void Span::show()
{
    std::cout << "vector size = " << v.size() << " | N = " << this->N << std::endl;
    for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
}

const char* Span::FullVector::what() const throw()
{
    return("Cant add Number - Vector Is Full");
};

const char* Span::WrongSize::what() const throw()
{
    return("WrongSize");
};

const char* Span::NonFoundSpan::what() const throw()
{
    return("N = 1, Non Found Span");
};

const char* Span::WrongBeter::what() const throw()
{
    return("Wrong in method beter add number");
};

Span::~Span()
{}