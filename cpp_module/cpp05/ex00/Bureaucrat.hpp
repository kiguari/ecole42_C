/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:03:06 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/11 16:23:49 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
    const   std::string name;
    int     grade;
public:
    Bureaucrat();
    Bureaucrat( const std::string new_name);
    Bureaucrat( const Bureaucrat &new_burik);
    // нужен конструктор который будет принимать грейд и имя
    Bureaucrat( const int new_grade, const std::string new_name);
    Bureaucrat &operator= ( const Bureaucrat &new_burik);
    
    /*
    исключения, наследуются от оригинального класса exception
    в оригинально эксепшене есть метод what, его вызов сообщит, 
    что пошло не так и что вызвало исключение.
    следовательно в нашем классе исключений нужно сделать перегрузку этого метода.
    */
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
    
    // инкримент по сути должен работать как декримент, а декримент как инкримент
    void grade_minis_decriment();
    void grade_plus_inkriment();
    
    // гетер и сетер
    int getGrade() const;
    /* const */ std::string getName() const;
    ~Bureaucrat();
};

std::ostream  &operator<< (std::ostream &out, const Bureaucrat &out_Bureaucrat);

#endif