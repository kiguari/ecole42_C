/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:27:45 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/13 12:48:18 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    Intern( const Intern &new_intern);
    Intern &operator= (const Intern &new_intern);
public:
    Intern();
    Form* makeForm(std::string new_form_name, std::string new_form_target);
    class WrongFormName : public std::exception
    {
        const char* what() const throw();
    };
    ~Intern();
};

#endif