/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:15:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/18 09:56:09 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
Создайте базовый класс, в которой есть только общедоступный виртуальный деструктор. 
Создайте три пустыx класса A, B и C, 
которые публично наследуются от базового.

Напишите функцию "Base * generate(void);"
которая случайным образом создает экземпляр A, B или C
и возвращает экземпляр в качестве базового указателя. 
Не стесняйтесь использовать все, что вам нравится, для случайности.

Напишите функцию "void identify(Base* p);"
которая отображает соответствие "A", "B" или "C" -в соответствии с реальным типом p.

Напишите функцию "void identify(Base& p);"
вы никогда не должны использовать указатель внутри этой функция. 
это отображает "A", "B" или "C" в соответствии с реальным типом p.

Оберните эти функции в программу, которая докажет, что все работает так, как задумано.
<typeinfo> запрещено.
*/

Base * generate(void)
{
    Base *tmp;
    srand(time(NULL));
	int first = rand();
    int second = rand();
    int third = rand();
    if(first >= second && first >= third)
        return(tmp = new A);
    if(second >= first && second >= third)
        return(tmp = new B);
    // if(third >= second && third >= first)
    return(tmp = new C);
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "This is A class" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "This is B class" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "This is C class" << std::endl;
    else
        std::cout << "wrong pointer" << std::endl;
}

// ссылка всегда указывает на какой то объект
// проверить ссылку на то, что она NULL нельзя
void identify(Base& p)
{
    int flag = 0;
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "This is A class" << std::endl;
        flag = 1;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "This is B class" << std::endl;
        flag = 1;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "This is C class" << std::endl;
        flag = 1;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    if(!flag)
        std::cout << "wrong reference" << std::endl;
}

int main()
{
    Base *base1 = generate();
    Base &base2 = *base1;
    identify(base1);
    identify(base2);
    // identify(NULL);
    // identify(0);
    return(0);
}