/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:45 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/22 16:18:43 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T *array;
    int array_size;
    int flag;
    
public:
    Array() : array(nullptr), array_size(10), flag(0)
    {
        array = new T[array_size];
        /*  
            Нужно создать пустой массив, пустой массив это не = NULL, 
            массив является пустым, когда его значения не инициализированны.
            Тоесть в каждом элементе массива - мусор.
            Тоеать память выделанна и заполнить его будут уже при необходимости
            
            сделаем его размером например 10.

            Но изначально я в любом случае сам массив инициализирую NULL,
            что бы было удобно чекать на []delete
        */
    }
    Array(unsigned int new_array_size) : array(nullptr), array_size(new_array_size), flag(1)//, array = new T[new_array_size]
    {
        if(array_size == 0) // нет смысла создавать массив размеров в 0, хотя это возможно, оператор new и компилятор не ругаются
            throw ArrayExp();
        array = new T[array_size];
    }
    Array(const Array &new_Array)
    {
        *this = new_Array;
    }
    Array &operator= (const Array &new_Array)
    {
        if(new_Array.array != nullptr && new_Array.array_size > 0)
        {
            if(flag) //!!! я чекаю не тот флаг!!!! нужно new_Array->flag !!!!!!!!!!
            {
                this->array_size = new_Array.array_size;
                array = new T[array_size];
                for(int i = 0; i < this->array_size; i++)
                {
                    this->array[i] = new_Array.array[i];
                }
            }
            else
            {
                this->array_size = new_Array.array_size;
                this->array = new T[this->array_size];
            }
            return(*this);
        }
        else
        {
            this->array_size = new_Array.array_size; // тут 0
            throw ArrayExp();
        }        
    }

    T &operator[] (const int index)
    {
        if(index >= this->array_size || index < 0)
            throw ArraySega();
        return(array[index]);
    }
    
    class ArrayExp : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return("Wrong array size");
        }
    };
    
    class ArraySega : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return("Wrong index - its - SegaMegaDraiv");
        }
    };
    
    int size() const
    {
        return(this->array_size);
    }
    
    ~Array()
    {
        if (array) // if(array_size)
            delete []array;
    }
};

#endif