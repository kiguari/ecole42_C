/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:10:47 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 17:43:32 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("test_form"), grade_required(150), excete_required(150)
{
    this->indicator = false;
}

Form::Form( const std::string new_name, const int new_grade_required) : name(new_name), grade_required((new_grade_required)), excete_required(150)
{
    if(new_grade_required > 150 || excete_required > 150)
        throw GradeTooLowException();
    if(new_grade_required < 1 || excete_required < 1)
        throw GradeTooHighException();
    this->indicator = false;
}

Form::Form( const std::string new_name, const int new_grade_required, const int new_excete_required) : name(new_name), grade_required((new_grade_required)), excete_required(new_excete_required)
{
    if(new_grade_required > 150 || excete_required > 150)
        throw GradeTooLowException();
    if(new_grade_required < 1 || excete_required < 1)
        throw GradeTooHighException();
    this->indicator = false;
}

Form::Form( const Form &new_form) : name(new_form.getName()), grade_required(new_form.getGrade_required()), excete_required(new_form.getExcecute_required())
{
    this->indicator = new_form.getFormStatus();
}

Form &Form::operator= (const Form &new_form)
{
    this->indicator = new_form.getFormStatus();
    return(*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Error too hight form grade");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Error too low form grade");
}

const char* Form::FormStatusFale::what() const throw()
{
    return("Error, this form cant be excecute, they are not signed");
}

void Form::beSigned(Bureaucrat &burik)
{
    if(burik.getGrade() > this->getGrade_required())
        throw GradeTooHighException();
    else if(burik.getGrade() <= this->getGrade_required())
        burik.signForm(*this);
}

void Form::setSign()
{
    this->indicator = true;
}

std::string Form::getName() const
{
    return(this->name);
}

int Form::getGrade_required() const
{
    return(this->grade_required);
}

int Form::getExcecute_required() const
{
    return(this->excete_required);
}

bool Form::getFormStatus() const
{
    return(this->indicator);
}

/*
    Для экзекьюции формы, чекаем, подписана ли он (sign) 
    и чекаем грейды, если не проходит то пробрасываем исключение
    если все ок то вызываем Action, 
    он обратится к Action соответсвующего дочернего класса
*/
void Form::execute(Bureaucrat const & executor) const
{
    if(!this->indicator)
        throw FormStatusFale();
    if(executor.getGrade() > this->getExcecute_required())
    {
        throw GradeTooHighException();
    }
    this->Action();
}

Form::~Form()
{
    // std::cout << "delete " << this->getName() << std::endl
}

std::ostream &operator<< (std::ostream &out, const Form &out_Form)
{
    if(out_Form.getFormStatus())
        out << "Form name - " << out_Form.getName() << " grade required for this form - " << out_Form.getName() << " excecute required for this form - " << out_Form.getExcecute_required() << " success sign" << std::endl;
    else
        out << "Form name - " << out_Form.getName() << " grade required for this form - " << out_Form.getName() << " excecute required for this form - " << out_Form.getExcecute_required() << " fail sign" << std::endl;
    return(out);
}
