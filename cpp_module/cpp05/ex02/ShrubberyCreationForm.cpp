/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:21:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 16:56:10 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm - test form", 145, 137)
{
    this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &new_target) : Form("ShrubberyCreationForm", 145, 137)
{
    this->target = new_target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &new_form) : Form("ShrubberyCreationForm", 145, 137)
{
    this->target = new_form.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &new_form)
{
    this->target = new_form.target;
    return(*this);
}


void ShrubberyCreationForm::Action() const
{
    std::cout << "ShrubberyCreationForm ACTION TEST" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}