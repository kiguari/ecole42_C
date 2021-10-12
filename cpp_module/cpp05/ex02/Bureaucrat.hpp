/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:03:06 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 15:59:03 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const   std::string name;
    int     grade;
public:
    Bureaucrat();
    Bureaucrat( const std::string new_name);
    Bureaucrat( const Bureaucrat &new_burik);
    Bureaucrat( const int new_grade, const std::string new_name);
    Bureaucrat &operator= ( const Bureaucrat &new_burik);
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    void grade_minis_decriment();
    void grade_plus_inkriment();
    int getGrade() const;
    /* const */ std::string getName() const;
    void signForm(Form &signeted);

    void executeForm(Form const & form);
    
    ~Bureaucrat();
};

std::ostream  &operator<< (std::ostream &out, const Bureaucrat &out_Bureaucrat);

#endif