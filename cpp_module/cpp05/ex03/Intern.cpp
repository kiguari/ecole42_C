/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:27:48 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/13 12:48:46 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern( const Intern &new_intern)
{
    *this = new_intern;
}

Intern &Intern::operator= (const Intern &new_intern)
{
    if(this == &new_intern)
        return(*this);
    return(*this);
}

Form* Intern::makeForm(std::string new_form_name, std::string new_form_target)
{
    Form *tmp = NULL;
    std::string forms[4] = {"presidential request", "shrubbery request", "robotomy request", "error"};
    int i = 0;
    while(forms[i] != new_form_name && i < 4)
        i++;
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << forms[i] << std::endl;
        tmp = new PresidentialPardonForm(new_form_target);
        break;
    case 1:
        std::cout << "Intern creates " << forms[i] << std::endl;
        tmp = new ShrubberyCreationForm(new_form_target);
        break;
    case 2:
        std::cout << "Intern creates " << forms[i] << std::endl;
        tmp = new RobotomyRequestForm(new_form_target);
        break;
    default:
        throw WrongFormName();
    }
    return(tmp);
}

const char* Intern::WrongFormName::what() const throw()
{
    return("Error message - wrong form name");
}


Intern::~Intern()
{}