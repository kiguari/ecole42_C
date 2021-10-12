/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:10:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 13:01:56 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    bool    indicator;
    const   std::string name;
    const   int grade_required;
public:
    Form();
    Form( const std::string new_name, const int new_grade_required);
    Form( const Form &new_form);
    Form &operator= (const Form &new_form);
    // исключения для форм
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
    // процесс подписания формы
    void beSigned(Bureaucrat &burik);
    // подписание
    void setSign();
    // все гетеры
    std::string getName() const;
    int getGrade_required() const;
    bool getFormStatus() const;
    ~Form();
};

std::ostream  &operator<< (std::ostream &out, const Form &out_Form);

#endif