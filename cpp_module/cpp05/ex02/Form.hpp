/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:10:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 15:53:35 by eshakita         ###   ########.fr       */
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
    const   int excete_required;
public:
    Form();
    Form( const std::string new_name, const int new_grade_required);
    Form( const std::string new_name, const int new_grade_required, const int excete_required);
    Form( const Form &new_form);
    Form &operator= (const Form &new_form);
    
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
    // добавляем исключение на случай если грайд для экзекьюции выше чем грейд бюракрата
    class FormStatusFale : public std::exception
    {
    public:
        const char* what() const throw();
    };
    
    void beSigned(Bureaucrat &burik);
    void setSign();
    
    std::string getName() const;
    int getGrade_required() const;
    int getExcecute_required() const;
    bool getFormStatus() const;
    
    virtual void Action() const = 0;

    void execute(Bureaucrat const & executor) const;
    
    ~Form();
};

std::ostream  &operator<< (std::ostream &out, const Form &out_Form);

#endif