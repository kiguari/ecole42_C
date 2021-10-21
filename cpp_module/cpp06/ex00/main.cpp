/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:32:10 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/21 16:18:28 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

/*
Написать программу которая принимает аргумент в качестве параметра
Он должен принаджлежать int double float char и только в десятичной системе счисления

Неотображаемые символы не могут быть переданы в качестве аргмента и 
если пребразование не отображается, то нужно вывести ошибку

при выводе флота добавить .0f или f в зависимости от значения, так же могут приниматься -inff, +inff и nanf
при выводе дабла в зависимости от значения добавить .0, так же могут приниматься -inf, +inf и nan

программа должна определить тип литерала, получить этот литерал в правильном типе (чтобы
он больше не был строкой), затем явно преобразовать его в каждый из трех других типов и
отобразить результаты, используя то же форматирование, что и ниже. 
Если преобразование не имеет смысла или переполняется, 
покажите, что преобразование невозможно. Вы можете включить любой заголовок
, необходимый для обработки числовых ограничений и специальных значений.

Пример:
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0


*/

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << "Error wrong argc" << std::endl;
        return(1);
    }
    Conversion Convers(argv[1]);
    Convers.cast();
    
    //same test for look like strtod work
    
    // char        *str2 = NULL;
    // std::string str = argv[1];
    // double      test = static_cast<double>(std::strtod(str.c_str(), &str2));
    // int         test2 = static_cast<int>(test);
    // char        test3 = static_cast<char>(test);
    // float       test4 = static_cast<float>(test);
    
    // std::cout << "double convers - " << test << std::endl;
    // std::cout << "int convers - " << test2 << std::endl;
    // std::cout << "char convers - " << test3 << std::endl;
    // std::cout << "float convers - " << test4 << std::endl;

    return(0);
}