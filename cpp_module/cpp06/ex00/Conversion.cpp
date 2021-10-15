/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:25:43 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/15 13:28:14 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion()
{
    this->string_value = "123";
    this->nan_flag = 0;
    this->flag_point = 0;
    this->flag_char_minis = 0;
    this->flag_non_disp = 0;
    this->i_result = 0;
    this->d_result = 0;
    this->f_result = 0;
    this->c_result = '\0';
}

Conversion::Conversion( const char *argv)
{
    this->string_value = argv;
    this->nan_flag = 0;
    this->flag_point = 0;
    this->flag_char_minis = 0;
    this->flag_non_disp = 0;
    this->i_result = 0;
    this->d_result = 0;
    this->f_result = 0;
    this->c_result = '\0';
    if(this->string_value.length() == 0)
        return;
}

Conversion::Conversion( const Conversion &new_Conversion)
{
    *this = new_Conversion;
}

Conversion &Conversion::operator=( const Conversion &new_Conversion)
{
    this->string_value = new_Conversion.string_value;
    this->nan_flag = new_Conversion.nan_flag;
    this->flag_point = new_Conversion.flag_point;
    this->flag_char_minis = new_Conversion.flag_char_minis;
    this->flag_non_disp = new_Conversion.flag_non_disp;
    this->i_result = new_Conversion.i_result;
    this->d_result = new_Conversion.d_result;
    this->f_result = new_Conversion.f_result;
    this->c_result = new_Conversion.c_result;
    return(*this);
}

char Conversion::to_char()
{
    if(nan_flag || this->d_result > 255 || this->d_result < 0)
        throw Impossible();
    c_result = static_cast<char>(this->d_result);
    if(string_value.length() == 1)
        c_result = static_cast<char>(string_value[0]);
    if((c_result > 32 && c_result < 48) || (c_result > 57 && c_result < 126))
        return(c_result);
    else
        throw NotDisplaylibleException();
}

int  Conversion::to_int()
{
    if(nan_flag)
        throw Impossible();
    if(flag_char_minis || flag_non_disp == 1)
        throw NotDisplaylibleException();
    return(i_result = static_cast<int>(this->d_result));
}

float  Conversion::to_float()
{
    return(f_result = static_cast<float>(d_result));
}

double  Conversion::to_double()
{
    return(d_result);
}

void    Conversion::pars()
{
    if(string_value == "nan" || string_value == "-inf" ||  string_value == "+inf"
    || string_value == "-inff" ||  string_value == "+inff" || string_value == "nanf")
    {
        nan_flag = 1;
        return;
    }
    if(string_value.length() == 0)
        throw WrongArgvException();       
    for(unsigned long i = 0; i < string_value.length(); i++)
    {
        if(std::isdigit(string_value[i]) // чекаем на числа
        || (!std::isdigit(string_value[i]) && string_value[i] == '.' && this->flag_point == 0) // чекаем на одну точку
        || (i == 0 && !std::isdigit(string_value[i]) && string_value[i] == '-') // чекаем на отрицательное число
        || (!std::isdigit(string_value[i]) && i == string_value.length()-1 && i != 0 && string_value[i] == 'f')) //чекаем на наличие в конце f
        {
            if(!std::isdigit(string_value[i]) && string_value[i] == '.' && this->flag_point == 0) // чекаем на первую точку
                flag_point++;
            if(!std::isdigit(string_value[i]) && i == string_value.length()-1 && i != 0 && string_value[i] == 'f') // если в конце есть f то убираю ее
                string_value[i] = '\0';
            if(i == 0 && !std::isdigit(string_value[i]) && string_value[i] == '-')
            {
                if(string_value.length() == 1)
                    flag_char_minis = 1;
            }
            continue;
        }
        else
        {
            flag_non_disp = 1;
            // throw WrongArgvException();
        }
    }
}

void    Conversion::cast()
{
    char **ptr = nullptr;
    try
    {
        this->pars();
        this->d_result = std::strtod(string_value.c_str(), ptr);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    try
    {
        std::cout << "char: " << this->to_char() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "int: " << this->to_int() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "float: ";
        if(flag_char_minis || flag_non_disp == 1)
            throw NotDisplaylibleException();
        f_result = this->to_float();
        if((!nan_flag && (f_result - this->to_int())) || nan_flag)
            std::cout << f_result << "f" << std::endl;
        else
            std::cout << f_result << ".0f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        if(flag_char_minis || flag_non_disp == 1)
        {
            std::cout << "double: ";
            throw NotDisplaylibleException();
        }
        if(nan_flag || (!nan_flag && (d_result - this->to_int())))
            std::cout << "double: " << this->to_double() << std::endl;
        else
            std::cout << "double: " << this->to_double() << ".0" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const char* Conversion::NotDisplaylibleException::what() const throw()
{
    return("Non displayable");
}

const char* Conversion::WrongArgvException::what() const throw()
{
    return("Errorr wrong argv");
}

const char* Conversion::Impossible::what() const throw()
{
    return("impossible");
}

Conversion::~Conversion()
{}
