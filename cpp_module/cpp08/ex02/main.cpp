/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:00:57 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/22 13:48:16 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

/*
STACK - тип данный который работает по принципе "первый вошел - последний вышел"
в нем нет индексов как в массиве, а значит нельзя обратится к конкретному элементу.
Стек построен на списках, каждый элемент указывает на следующий, а последний на NULL;

Контейнер стек - контейнер который не иммет итераторов (не итерируется)
Реализовать класс MutantStack в сонове которого будет std::stack, который предложит все свои методы, а так же итераторы

методы std::stack
.pop()      - удаляет элемент с вершины
.push()     - вставляет элемент на вершину
.top()      - представляет доступ к элементу на вершине
.empty()    - проверяет, пуст ли базовый контейнер
.size()     - возвращает количество элементов

.emplace()  - (C++11) - создаёт элемент на месте сверху
.swap()     - (C++11) -меняет местами содержимое

*/

int main( void ) 
{
    MutantStack<int> test;
    test.push(3);
    test.push(4);
    test.push(5);
    test.push(2);
    std::cout << test.top() << std::endl;
    std::cout << test.size() << std::endl;
    
    MutantStack<int> test2;
    test2 = test;
    MutantStack<int>::iterator k = test2.begin();
    std::cout << "--------------- operator = ----------------------" << std::endl;
    for(MutantStack<int>::iterator i = test.begin(); i != test.end(); i++)
    {
        std::cout << "test - "<< *i << " | test2 - " << *k << std::endl;
        k++;
    }

    MutantStack<int> test3(test);
    MutantStack<int>::iterator g = test3.begin();
    std::cout << "--------------- copy constructor ----------------------" << std::endl;
    for(MutantStack<int>::iterator i = test.begin(); i != test.end(); i++)
    {
        std::cout << "test - "<< *i << " | test3 - " << *g << std::endl;
        g++;
    }
    
    std::cout << "--------------- iterator begin ----------------------" << std::endl;
    int  j = 0;
    for(MutantStack<int>::iterator i = test.begin(); i != test.end(); i++)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j++;
    }
    std::cout << "--------------- iterator end ----------------------" << std::endl;
    j = test.size();
    for(MutantStack<int>::iterator i = test.end() - 1; i >= test.begin(); i--)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j--;
    }
    std::cout << "--------------- iterator reverse begin ----------------------" << std::endl;
    j = 0;
    for(MutantStack<int>::reverse_iterator i = test.rbegin(); i != test.rend(); i++)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j++;
    }
    std::cout << "--------------- iterator reverse end ----------------------" << std::endl;
    j = test.size();
    for(MutantStack<int>::reverse_iterator i = test.rend() - 1; i >= test.rbegin(); i--)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j--;
    }
    

    
    std::cout << "--------------- iterator const begin ----------------------" << std::endl;
    j = 0;
    for(MutantStack<int>::const_iterator i = test.cbegin(); i != test.cend(); i++)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j++;
    }
    std::cout << "--------------- iterator const end ----------------------" << std::endl;
    j = test.size();
    for(MutantStack<int>::const_iterator i = test.cend() - 1; i >= test.cbegin(); i--)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j--;
    }
    std::cout << "--------------- iterator const reverse begin ----------------------" << std::endl;
    j = 0;
    for(MutantStack<int>::const_reverse_iterator i = test.crbegin(); i != test.crend(); i++)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j++;
    }
    std::cout << "--------------- iterator const reverse end ----------------------" << std::endl;
    j = test.size();
    for(MutantStack<int>::const_reverse_iterator i = test.crend() - 1; i >= test.crbegin(); i--)
    {
        std::cout << "index - " << j << " - "<< *i << std::endl;
        j--;
    }
    // if(test.size() > 1)
    //     test.pop();
    // std::cout << test.top() << std::endl;
    // std::cout << test.size() << std::endl;
    return 0;



    // main from subject
    // MutantStack<int> mstack;
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    // mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
    // MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite) {
    //     std::cout << *it << std::endl;
    // ++it; }
    // std::stack<int> s(mstack); return 0;
}
