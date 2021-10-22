/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:45 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/22 13:53:49 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

/*
Итераторы обеспечивают доступ к элементам контейнера.
С помощью итераторов очень удобно перебирать элементы.
Итератор описывается типом iterator.
Но для каждого контейнера конкретный тип итератора будет отличаться.
Так, итератор для контейнера list<int> представляет тип list<int>::iterator, 
а итератор контейнера vector<int> представляет тип vector<int>::iterator и так далее.

Для получения итераторов контейнеры в C++ обладают такими функциями,
как begin() и end(). Функция begin() возвращает итератор,
который указывает на первый элемент контейнера (при наличии в контейнере элементов).
Функция end() возвращает итератор, который указывает на
следующую позицию после последнего элемента, то есть по сути на конец контейнера. 
Если контейнер пуст, то итераторы, возвращаемые обоими методами begin и end совпадают.
Если итератор begin не равен итератору end, то между ними есть как минимум один элемент.
*/

// если делать мейн через трайк кетч то нужно делать исключение
// если сделать через возврат тру фолс, то можно через if, else
// class NotFind : public std::exception
// {
//     public:
//         const char* what() const throw() {return("Value not find");}
// };

// template <typename T, typename T2> 
template <typename T>
/*
по сабджекту второй параметр должен быть типа int
но тогда мы не сможем использовать для например стрингового вектора или флотового,
а если мы сделаем для второго параметра тоже typename другого типа (Т2)
то тогда сможем

и второй вариант, это поиск чере метод find
*/
bool easyFind(T array, int value)
// bool easyFind(T array, T2 value)

{
    for(typename T::iterator i = array.begin(); i != array.end(); ++i)
    {
        if(*i == value)
        {
            // std::cout << "easyfind - find value " << value << std::endl;
            return true;
        }
    }
    // throw NotFind();
    return(false);

    // typename T::iterator second_var = std::find(array.begin(), array.end(), value);
    // if(second_var == array.end())
    //     return(false);
    // return true;
}

#endif