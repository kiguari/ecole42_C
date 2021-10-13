/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:15:13 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/13 12:53:19 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

/*
    В дочерних классах от формы, нам нужно:
    - поле таргет
    - конструкторы/деструкторы
    - перегрузка метода Action()
*/

class ShrubberyCreationForm : public Form
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &new_target);
    ShrubberyCreationForm(const ShrubberyCreationForm &new_form);
    ShrubberyCreationForm &operator= (const ShrubberyCreationForm &new_form);
    void Action() const;
    ~ShrubberyCreationForm();
};

#endif