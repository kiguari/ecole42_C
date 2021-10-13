/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:19:49 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 17:46:51 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

/*
    В дочерних классах от формы, нам нужно:
    - поле таргет
    - конструкторы/деструкторы
    - перегрузка метода Action()
*/

class PresidentialPardonForm : public Form
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &new_target);
    PresidentialPardonForm(const PresidentialPardonForm &new_form);
    PresidentialPardonForm &operator= (const PresidentialPardonForm &new_form);
    void Action() const;
    ~PresidentialPardonForm();
};

#endif