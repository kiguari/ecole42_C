/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:43:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 13:00:47 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- создать класс форм, у которого есть имя, 
значени показывающее подписана ли форма (в начале не подписана),
grade бюракрата необходимый для его подписи (sign in) и grade бюракрата 
для его валидации (execute it).
имя и грейд константны и приватны (не протектед).

- сделать исключения с теми же условиями что у бюракрата
Если у формы grade_required меньше 1 то:
Form::GradeTooHighException
Елси у формы грейд больше 150
Form::GradeTooLowException
И если грейд формы будет выше чем грейд бюдакрата, то еще раз кину исключение
Form::GradeTooHighException

- сделать гетеры для всех атрибутов и перегрузку оператора <<
который полностью описывает состояние формы.
- реализовать метод beSigned, который принимает бюракрата и подписывает форму если 
grade бюракрата достаточен, если grade недостаточен то кинуть исключение Form::GradeTooLowException
- реализовать метод signForm, если форма подписана, напечатать "<bureaucrat> signs <form>"
иначе "<bureaucrat> cannot sign <form> because <reason>"
*/

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // тест где грейд бюракрата выше чем грейд формы, все оке
        Bureaucrat burik1(1, "buric1");
        Form form1("test_form1", 2);
        form1.beSigned(burik1);
        
        // тест где грейд бюракрата ниже грейда формы
        // Bureaucrat burik2(3, "buric1");
        // Form form2("test_form2", 2);
        // form2.beSigned(burik2);

        // тест где форма уже подписана
        // Bureaucrat burik3(1, "buric1");
        // form1.beSigned(burik3);

        // тест создания слишком высокой формы
        // Form form4("test_form4", 0);

        // тест создания слишком низкой формы
        // Form form5("test_form5", 151);

        // тетс на создание форм всеми конструкторами
        // Form test1;
        // Form test3("test3", 10);
        // Form test4;
        // test4 = test3;
        // Form test5(test3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}