/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:00:57 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/20 10:04:52 by eshakita         ###   ########.fr       */
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
    // std::string re = 0;
    // INT ///////////////////////////////////////////////////////////
    // сдаем массив интов 0 
    try
    {
        Array<int> test(0);
        std::cout << "test 1 int - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 1 int - not ok" << std::endl;
    }
    // сдаем массив интов <0
    try
    {
        Array<int> test2(-5);
        std::cout << "test 2 int - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 2 int - not ok" << std::endl;
    }
    // сдалаем массив интов дефолтный
    try
    {
        Array<int> test3;
        std::cout << "test 3 int - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 3 int - not ok" << std::endl;
    }
    // сдаем массив интов >0
    try
    {
        Array<int> test4(10);
        std::cout << "test 4 int - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 4 int - not ok" << std::endl;
    }
    
    // system ("leaks array");
    // return 0;


    // FLOAT ///////////////////////////////////////////////////////////
    // сдаем массив флотов 0
    try
    {
        Array<float> test5(0);
        std::cout << "test 5 float - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 5 float - not ok" << std::endl;
    }
    // сдаем массив флотов <0
    try
    {
        Array<float> test6(-5);
        std::cout << "test 6 float - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 6 float - not ok" << std::endl;
    }
    // сдалаем массив флотов дефолтный
    try
    {
        Array<float> test7;
        std::cout << "test 7 float - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 7 float - not ok" << std::endl;
    }
    // сдаем массив флотов>0
    try
    {
        Array<float> test8(10);
        std::cout << "test 8 float - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 8 float - not ok" << std::endl;
    }
    
    // system ("leaks array");
    // return 0;

    // STRING ///////////////////////////////////////////////////////////
    // сдаем массив флотов 0
    try
    {
        Array<std::string> test9(0);
        std::cout << "test 9 std::string - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 9 std::string - not ok" << std::endl;
    }
    // сдаем массив флотов <0
    try
    {
        Array<std::string> test10(-5);
        std::cout << "test 10 std::string - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 10 std::string - not ok" << std::endl;
    }
    // сдалаем массив флотов дефолтный
    try
    {
        Array<std::string> test11;
        std::cout << "test 11 std::string - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 11 std::string - not ok" << std::endl;
    }
    // сдаем массив флотов>0
    try
    {
        Array<std::string> test12(10);
        std::cout << "test 12 std::string - ok" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "test 12 std::string - not ok" << std::endl;
    }
    
    system ("leaks array");
    // std::cout << sizeof(int) << std::endl;
    // std::cout << sizeof(float) << std::endl;
    // std::cout << sizeof(double) << std::endl;
    // std::cout << sizeof(std::string) << std::endl;
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
