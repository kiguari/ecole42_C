/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:00:57 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/21 17:45:42 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

/*
    реализовать класс в котором может храниться N колличество интов.
    это можно реализовать через обычный интовый массив, но следуюя укзаания сабджекта
    используем контейнер (vector). N - unsigned int передаваемый конструктору в качестве парметра.
    
    реализовать метод addNumber, который добавляет число в вектор
    если размер вектора начинает превышать N - кидаем исключение

    реализовать методы shortestSpan и longestSpan
    который возвращаеют минимальную разницу между элементами вектора и соответственно максимальную
    если в векторе не занесено ни одного значения или же есть только одно значение - кинуть исключение
    
    протестировать не меньше чем с 10к намберов
*/

int main( void ) 
{
    // создаем на 5 элементов и добавляем 5 элементов
    try
    {
        Span test1(5);
        test1.addNumber(10);
        test1.addNumber(24);
        test1.addNumber(3);
        test1.addNumber(45);
        test1.addNumber(5);
        std::cout << "shortes span " << test1.shortestSpan() << std::endl;
        std::cout << "longest span " << test1.longestSpan() << std::endl;
        std::cout << "test1 ok" << std::endl;
        // test.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // создаем на 5 элементов и пытаемся добавить шестой
    try
    {
        Span test2(5);
        test2.addNumber(1);
        test2.addNumber(2);
        test2.addNumber(3);
        test2.addNumber(4);
        test2.addNumber(5);
        test2.addNumber(6);
        std::cout << "shortes span " << test2.shortestSpan() << std::endl;
        std::cout << "longest span " << test2.longestSpan() << std::endl;
        std::cout << "test2 ok" << std::endl;
        // test2.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // создаем на 0 элементов
    try
    {
        Span test3(0);
        test3.addNumber(1);
        test3.addNumber(2);
        test3.addNumber(3);
        test3.addNumber(4);
        test3.addNumber(5);
        std::cout << "shortes span " << test3.shortestSpan() << std::endl;
        std::cout << "longest span " << test3.longestSpan() << std::endl;
        std::cout << "test3 ok" << std::endl;
        // test2.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    /*
    создаем на отрицательное число элементов, в сабджекте сказано 
    что конструктор принимает unsigned int
    при подаче отрицательного числа, он неявно его приведет к unsigned int
    */
    try
    {
        Span test4(-5);
        test4.addNumber(1);
        test4.addNumber(2);
        test4.addNumber(3);
        test4.addNumber(4);
        test4.addNumber(5);
        test4.addNumber(1);
        std::cout << "shortes span " << test4.shortestSpan() << std::endl;
        std::cout << "longest span " << test4.longestSpan() << std::endl;
        std::cout << "test4 ok" << std::endl;
        // test4.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // создаем на 100000 элементов циклом
    try
    {
        Span test5(100000);
        for(int i = 0; i < 100000; i ++)
        {
            test5.addNumber(i);
        }        
        std::cout << "shortes span " << test5.shortestSpan() << std::endl;
        std::cout << "longest span " << test5.longestSpan() << std::endl;
        std::cout << "test5 ok" << std::endl;
        // test4.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // доп тест 1
    try
    {
        Span test6(5);
        test6.addNumber(3);
        test6.addNumber(3);
        test6.addNumber(3);
        test6.addNumber(4);
        test6.addNumber(5);
        
        std::cout << "shortes span " << test6.shortestSpan() << std::endl;
        std::cout << "longest span " << test6.longestSpan() << std::endl;
        std::cout << "test6 ok" << std::endl;
        // test4.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // доп тест 2
    try
    {
        Span test7(5);
        test7.addNumber(0);
        test7.addNumber(4);
        test7.addNumber(3);
        test7.addNumber(4);
        test7.addNumber(5);
        
        std::cout << "shortes span " << test7.shortestSpan() << std::endl;
        std::cout << "longest span " << test7.longestSpan() << std::endl;
        std::cout << "test7 ok" << std::endl;
        // test4.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // доп тест 3 better add number
    try
    {
        Span test8(5);
        test8.addNumber(2);
        test8.addNumber(4);
        test8.BetteraddNumberOneForAll(8);
        // test8.addNumber(4);
        // test8.show();
        
        std::cout << "shortes span " << test8.shortestSpan() << std::endl;
        std::cout << "longest span " << test8.longestSpan() << std::endl;
        std::cout << "test8 ok" << std::endl;
        // test4.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Span test9(5);
        // test9.addNumber(4);
        test9.BetteraddNumberCycle(1, 5);
        // test9.show();
        // test9.addNumber(4);
        
        std::cout << "shortes span " << test9.shortestSpan() << std::endl;
        std::cout << "longest span " << test9.longestSpan() << std::endl;
        std::cout << "test9 ok" << std::endl;
        // test4.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    // // main из сабджекта
    // Span sp = Span(5);
    // sp.addNumber(5);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // // $> ./ex01
    // // 2 14
    // // $>
    return 0; 
}
