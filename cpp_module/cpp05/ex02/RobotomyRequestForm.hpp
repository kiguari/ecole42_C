/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:19:05 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 17:46:43 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

/*
    В дочерних классах от формы, нам нужно:
    - поле таргет
    - конструкторы/деструкторы
    - перегрузка метода Action()
*/

class RobotomyRequestForm : public Form
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &new_target);
    RobotomyRequestForm(const RobotomyRequestForm &new_form);
    RobotomyRequestForm &operator= (const RobotomyRequestForm &new_form);
    void Action() const;
    ~RobotomyRequestForm();
};

#endif