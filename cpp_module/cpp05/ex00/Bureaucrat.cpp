/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:03:08 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/11 17:02:42 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default_burik")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat( const std::string new_name) : name(new_name)
{
    this->grade = 150;
}

/*
при описаниии конструктора копирования мы можем скопирвоать имя, 
но для этого нам нужно задать имя при инициализации, 
тем самым фактически мы не меняем имя, а задаем ему начальное значение,
так с const сделать можно (аналогично с дефолтным конструтором)
*/
Bureaucrat::Bureaucrat( const Bureaucrat &new_burik) : name(new_burik.getName())
{
    this->grade = new_burik.getGrade();
}

Bureaucrat::Bureaucrat( const int new_grade, const std::string new_name) : name(new_name)
{
    if(new_grade < 1)
        throw GradeTooHighException();
    if(new_grade > 150)
        throw GradeTooLowException();
    this->grade = new_grade;
}

/*
при перегрузке оператора = мы можем приравнять только grade, так как имя у нас const;
*/
Bureaucrat &Bureaucrat::operator= (const Bureaucrat &new_burik)
{
    this->grade = new_burik.getGrade();
    return(*this);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

// узнать для чего здесь конст
/* const */ std::string Bureaucrat::getName() const
{
    return (this->name);
}

// описание исключений
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Error too high grade, can not incriment grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Error too low grade, can not decriment grade");
}

// инкримент дикримент
void Bureaucrat::grade_plus_inkriment()
{
    if(this->grade - 1 <= 0)
        throw GradeTooHighException();
    this->grade -= 1;
}

void Bureaucrat::grade_minis_decriment()
{
    if(this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade += 1;
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "delete " << this->getName() << std::endl;
}

std::ostream &operator<< (std::ostream &out, const Bureaucrat &out_Bureaucrat)
{
    out << out_Bureaucrat.getName() << ", bureaucrat grade " << out_Bureaucrat.getGrade();
    return(out);
}