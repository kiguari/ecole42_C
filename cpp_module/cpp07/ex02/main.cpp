/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:00:57 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/19 14:17:50 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*
Написать шаблон класса Array - тип элементов - Т:
- ДЕфолтный конструктор создает пустой массив
- конструктор принимающий ансайнт инт n создает
массив из n элементов инициализируемый по умолчанию
(Совет: попробуйте скомпилировать int *a = new int();, затем отобразить *a.)
- конструкторо копирования
- использовать new, мы никогда не должны ображаться к невыделенной памяти
- доступ к элементам через оператор[]
- если попытка доступа через оператор[] за границу массива - кинуть исключение
- метод size возвращает колличество элементов массива. метод не принимает аргументы и не изменяет сайз; 
*/

int main( void ) 
{
    // сдаем массив интов 0
    try
    {
        Array<int> test(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // сдаем массив интов <0
    try
    {
        Array<int> test(-5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // сдалаем массив интов дефолтный
    try
    {
        Array<int> test;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // сдаем массив интов >0
    try
    {
        Array<int> test(10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    system ("leaks array");
    return 0; 
}

// main from subject
// должно вылететь два исключения, оба при ображании за пределы массива

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     system ("leaks array");
//     return 0;
// }
