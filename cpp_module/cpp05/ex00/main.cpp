/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:43:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/12 17:38:34 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- исключения не должны быть кононичной формы (остальные должны быть)
- бюракрат: у него должны быть постоянное (constanc name) имя и оценка (grade) которая 
варируется от 1(max) до 150(min), попытка создать бюракрата с недопустимой оценкой 
должна вызвать исключение либо Bureaucrat::GradeTooHighException 
лтбо Bureaucrat::GradeTooLowException.
- нужно реализовать два гетера getName getGrade, 
а так же два метода увеличения или уменьшения grade. Оба метода должны выдавать исключения, 
если grade становится слишком большой или слишком высокий.
- 1 это самый высокий grade, а 150 это самый низкий грейд, 
если инкрементировать grade 3, то получится grade 2.

The exceptions you throw must be catchable by a block like:
try
{
    * do some stuff with bureaucrats *
}
catch (std::exception & e) 
{
    * handle exception *
}

Нужно сделать перегрузку оператора << в ostream оно должно выводить что то типа
<name>, bureaucrat grade <grade>.

*/

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat burik1(1, "buric1");
        // Bureaucrat burik2(1, "buric2");
        // Bureaucrat burik2(151, "buric2");
        // Bureaucrat burik2(0, "buric2");
        Bureaucrat burik2(149, "buric2");
        Bureaucrat burik3(1, "buric3");
        Bureaucrat burik4(1, "buric4");
        
        Bureaucrat burik5;
        burik5 = burik4;
        Bureaucrat burik6(burik2);
        Bureaucrat burik7("burik7");
    
        std::cout << burik1 << std::endl;
        std::cout << burik2 << std::endl;
        std::cout << burik3 << std::endl;
        std::cout << burik4 << std::endl;
        std::cout << burik5 << std::endl;
        std::cout << burik6 << std::endl;
        std::cout << burik7 << std::endl;

        std::cout << burik2.getName() << std::endl;
        burik2.grade_minis_decriment();
        std::cout << burik2 << std::endl;
        burik2.grade_plus_inkriment();
        std::cout << burik2 << std::endl;
    }
    /*
    Ловит std::exception и все дочерние ему классы-исключения
    Можно ловить по отдельности каждое исключение 
    (Bureaucrat::GradeTooHighException&) (Bureaucrat::GradeTooLowException&)
    Но что бы ловить одновременно все дочерние, параметром нужно указывать родительский exeption
    */
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}