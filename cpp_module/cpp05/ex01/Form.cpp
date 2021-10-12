/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:10:47 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 15:31:26 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("test_form"), grade_required(150)
{
    this->indicator = false;
}

Form::Form( const std::string new_name, const int new_grade_required) : name(new_name), grade_required((new_grade_required))
{
    if(new_grade_required > 150)
        throw GradeTooLowException();
    if(new_grade_required < 1)
        throw GradeTooHighException();
    this->indicator = false;
}

Form::Form( const Form &new_form) : name(new_form.getName()), grade_required(new_form.getGrade_required())
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

bool Form::getFormStatus() const
{
    return(this->indicator);
}

Form::~Form()
{
    // std::cout << "delete " << this->getName() << std::endl
}

std::ostream &operator<< (std::ostream &out, const Form &out_Form)
{
    if(out_Form.getFormStatus())
        out << "Form name - " << out_Form.getName() << " grade required for this form - " << out_Form.getName() << " success sign" << std::endl;
    else
        out << "Form name - " << out_Form.getName() << " grade required for this form - " << out_Form.getName() << " fail sign" << std::endl;
    return(out);
}