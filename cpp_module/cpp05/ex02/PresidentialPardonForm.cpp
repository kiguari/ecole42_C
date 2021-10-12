/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:42:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 17:46:54 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm - test form", 25, 5)
{
    this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &new_target) : Form("PresidentialPardonForm", 25, 5)
{
    this->target = new_target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &new_form) : Form("PresidentialPardonForm", 25, 5)
{
    this->target = new_form.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &new_form)
{
    this->target = new_form.target;
    return(*this);
}


void PresidentialPardonForm::Action() const
{
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}