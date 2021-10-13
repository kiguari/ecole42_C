/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:39:43 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 17:46:48 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm - test form", 72, 45)
{
    this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &new_target) : Form("RobotomyRequestForm", 72, 45)
{
    this->target = new_target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &new_form) : Form("RobotomyRequestForm", 72, 45)
{
    this->target = new_form.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &new_form)
{
    this->target = new_form.target;
    return(*this);
}


void RobotomyRequestForm::Action() const
{
    srand(time(NULL));
	if (rand() % 2) 
    	std::cout << this->target << "has been robotomized successfully 50% of the time" << std::endl;
	else
        std::cout << this->target << "failer robotomized" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}