/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:43:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/13 13:00:16 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
сделать класс Intern
реализовать метод makeForm() принимает первым парметром принимает 
имя формы, вторым цель этой формы.
метод возвращает указатель на конкретную форму.

Он выведет
на стандартный вывод что-то вроде"Стажер создает <форму>".
Если он использует худший метод, например, ветвления if/elseif/elseif/else, 
или какие-то другие уродливые вещи, подобные этому, 
он не будет принят во время оценки. 
Если запрошенная форма неизвестна, выведите явное сообщение об ошибке.
*/

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        // ShrubberyCreationForm test
        // тест бюракрат может подписать форму, но не может ее выполнить
        // Bureaucrat burik1(144, "buric1");
        // ShrubberyCreationForm form1("Home1");
        // form1.beSigned(burik1);
        // burik1.executeForm(form1);

        // тест бюракрат может и подписать и выполнить
        // Bureaucrat burik2(1, "buric2");
        // ShrubberyCreationForm form2("Home2");
        // form2.beSigned(burik2);
        // burik2.executeForm(form2);

        // тест бюракрат не может и подписать и выполнить
        // Bureaucrat burik3(150, "buric3");
        // ShrubberyCreationForm form3("Home3");
        // form3.beSigned(burik3);
        // burik3.executeForm(form3);

        // RobotomyRequestForm
        // тест бюракрат может подписать форму, но не может ее выполнить
        // Bureaucrat burik4(144, "buric4");
        // RobotomyRequestForm form4("Home4");
        // form4.beSigned(burik4);
        // burik4.executeForm(form4);

        // тест бюракрат может и подписать и выполнить
        // Bureaucrat burik5(1, "buric5");
        // RobotomyRequestForm form5("Home5");
        // form5.beSigned(burik5);
        // burik5.executeForm(form5);

        // тест бюракрат не может и подписать и выполнить
        // Bureaucrat burik6(150, "buric6");
        // RobotomyRequestForm form6("Home6");
        // form6.beSigned(burik6);
        // burik6.executeForm(form6);

        // PresidentialPardonForm
        // тест бюракрат может подписать форму, но не может ее выполнить
        // Bureaucrat burik7(144, "buric7");
        // PresidentialPardonForm form7("Home7");
        // form7.beSigned(burik7);
        // burik7.executeForm(form7);

        // // тест бюракрат может и подписать и выполнить
        // Bureaucrat burik8(1, "buric8");
        // PresidentialPardonForm form8("Home8");
        // form8.beSigned(burik8);
        // burik8.executeForm(form8);

        // // тест бюракрат не может и подписать и выполнить
        // Bureaucrat burik9(150, "buric9");
        // PresidentialPardonForm form9("Home9");
        // form9.beSigned(burik9);
        // burik9.executeForm(form9);
        
        // main from subject ex03
        Intern  someRandomIntern;
        Form*   rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        // // дополниетльные тесты
        Bureaucrat  burik10(1, "buric10");
        Intern      Intern10;
        Form        *form10;
        form10 = Intern10.makeForm("robotomy request", "Bender");
        form10->beSigned(burik10);
        burik10.executeForm(*form10);

        Bureaucrat  burik11(1, "buric11");
        Intern      Intern11;
        Form        *form11;
        form11 = Intern11.makeForm("presidential request", "Bender");
        form11->beSigned(burik11);
        burik11.executeForm(*form11);

        Bureaucrat  burik12(1, "buric12");
        Intern      Intern12;
        Form        *form12;
        form12 = Intern12.makeForm("shrubbery request", "Bender");
        form12->beSigned(burik12);
        burik12.executeForm(*form12);

        Bureaucrat  burik13(1, "buric13");
        Intern      Intern13;
        Form        *form13;
        form13 = Intern13.makeForm("wrong request", "Bender");
        form13->beSigned(burik13);
        burik13.executeForm(*form13);

        Bureaucrat  burik14(1, "buric14");
        Intern      Intern14;
        Form        *form14;
        form14 = Intern14.makeForm("error", "Bender");
        form14->beSigned(burik14);
        burik14.executeForm(*form14);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}