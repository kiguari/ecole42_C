/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:43:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/13 11:25:18 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
создать классы наследники класса form, класс form - сделать вирутальным:
- ShrubberyCreationForm (Required grades: sign 145, exec 137)
реализовать метод Action (Создайте файл с именем <target>_shrubbery и 
запишите в него деревья ASCII в текущем каталоге<target>)
- RobotomyRequestForm (Required grades: sign 72, exec 45)
реализовать метод Action (Издает несколько сообщений и сообщает нам,
что <цель> была успешно автоматизирована в 50% случаев<цель>. 
В противном случае, скажите нам, что это провал.)
- PresidentialPardonForm (Required grades: sign 25, exec 5)
реализовать метод Action (Tells us <target> has been pardoned by Zafod Beeblebrox.)

у всех этих классов конструкторы могут принимать только один параметр, который представляет цель формы

реализовать метод execute(Bureaucrat const & executor) const
в базовой форме (родительской) выполняющий ACtion во всех конкретных формах
Вы должны убедиться, что форма подписана и что бюрократ, пытающийся
выполнить форму, имеет достаточно высокий балл, иначе вы создадите соответствующее исключение.
Независимо от того, хотите ли вы провести эти проверки в каждом конкретном классе или сделать регистрацию в
базовый класс, затем вызывающий другой метод для выполнения действия, зависит от вас, но один способ
красивее другого. В любом случае базовая форма должна быть абстрактным классом.

добавить метод executeForm(Form const & form) для бюракрата. 
Он должен попытаться выполнить форму, и если это удастся, выведите что-то вроде
<bureaucrat> executes <form>. Если нет, выведите явное сообщение об ошибке.

*/

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // ShrubberyCreationForm test
        // тест бюракрат может подписать форму, но не может ее выполнить
        Bureaucrat burik1(144, "buric1");
        ShrubberyCreationForm form1("Home1");
        form1.beSigned(burik1);
        burik1.executeForm(form1);

        // тест бюракрат может и подписать и выполнить
        Bureaucrat burik2(1, "buric2");
        ShrubberyCreationForm form2("Home2");
        form2.beSigned(burik2);
        burik2.executeForm(form2);

        // тест бюракрат не может и подписать и выполнить
        Bureaucrat burik3(150, "buric3");
        ShrubberyCreationForm form3("Home3");
        form3.beSigned(burik3);
        burik3.executeForm(form3);

        // RobotomyRequestForm
        // тест бюракрат может подписать форму, но не может ее выполнить
        Bureaucrat burik4(144, "buric4");
        RobotomyRequestForm form4("Home4");
        form4.beSigned(burik4);
        burik4.executeForm(form4);

        // тест бюракрат может и подписать и выполнить
        Bureaucrat burik5(1, "buric5");
        RobotomyRequestForm form5("Home5");
        form5.beSigned(burik5);
        burik5.executeForm(form5);

        // тест бюракрат не может и подписать и выполнить
        Bureaucrat burik6(150, "buric6");
        RobotomyRequestForm form6("Home6");
        form6.beSigned(burik6);
        burik6.executeForm(form6);

        // PresidentialPardonForm
        // тест бюракрат может подписать форму, но не может ее выполнить
        Bureaucrat burik7(144, "buric7");
        PresidentialPardonForm form7("Home7");
        form7.beSigned(burik7);
        burik7.executeForm(form7);

        // // тест бюракрат может и подписать и выполнить
        Bureaucrat burik8(1, "buric8");
        PresidentialPardonForm form8("Home8");
        form8.beSigned(burik8);
        burik8.executeForm(form8);

        // // тест бюракрат не может и подписать и выполнить
        Bureaucrat burik9(150, "buric9");
        PresidentialPardonForm form9("Home9");
        form9.beSigned(burik9);
        burik9.executeForm(form9);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}