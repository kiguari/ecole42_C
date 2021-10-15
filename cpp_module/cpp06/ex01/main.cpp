/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:15:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/15 15:27:28 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
написать функцию  "uintptr_t serialize(Data* ptr);"
функция вернет параментр целочисленный

написать функцию Data* deserialize(uintptr_t raw);
Эта функция вернет необработанные данные, созданные с помощью "сериализации", в структуру данных.

Оберните эти две функции в программу, которая докажет, что все работает так, как задумано. 

Вы должны создать допустимую структуру данных.
Возьмите адрес структуры данных, используйте сериализацию на нем.
Отправьте возвращаемое значение в десериализации.
Проверьте, равно ли возвращаемое значение первому указателю. 
Не забудьте заинключдить структру данных, которую вы используете.


нужно работать с оператором "reinterpret_cast < type-id > ( expression )"
Позволяет преобразовывать любой указатель в указатель любого другого типа. 
Также позволяет преобразовывать любой целочисленный тип в любой тип указателя и наоборот.

uintptr_t - тип данных в которой может поместиться любой тип данных, любой указатель

Сериализация - это процесс перевода структуры данных в последовательность битов.
Десериализация - процесс обратные сериализации. Создание структуры данных из битовой последовательности.

Сериализация используется например для передачи данных по сети.

*/

#include <iostream>
#include <iomanip>

struct Data
{
    int         i_val;
    char        c_val;
    std::string str_val;
    float       f_val;
};

uintptr_t serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}

void data_init(Data *Data)
{
    Data->c_val = 'c';
    Data->f_val = 1.2;
    Data->i_val = 50;
    Data->str_val = "test_test";
}

int main()
{
    Data *Data_prev_cast = new Data;
    Data *Data_after_cast;
    uintptr_t cast;
    data_init(Data_prev_cast);
    cast = serialize(Data_prev_cast);
    std::cout << "uintptr_t return after firs cast: "<< cast << std::endl;
    std::cout <<"memory: " << Data_prev_cast << " char: "<< Data_prev_cast->c_val << " int: " << Data_prev_cast->i_val << " float: " << Data_prev_cast->f_val << " string: " << Data_prev_cast->str_val << std::endl;
    Data_after_cast = deserialize(cast);
    std::cout <<"memory: " << Data_after_cast << " char: "<< Data_after_cast->c_val << " int: " << Data_after_cast->i_val << " float: " << Data_after_cast->f_val << " string: " << Data_after_cast->str_val << std::endl;
    delete Data_after_cast;
    return(0);
}