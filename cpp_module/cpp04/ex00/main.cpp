/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:32:01 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/06 13:17:58 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass.hpp"
#include "DogClass.hpp"
#include "WrongCatClass.hpp"

int main()
{
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "--------------- main from subject ---------------" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    // not subject main
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "--------- no subject main - dop testing ---------" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    Cat cat1("mysya");
    Animal* test = new Cat("barsik");
    std::cout << test->getType() << std::endl;
    test->makeSound();

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "-------------- WRONG ANIMAL TESTING -------------" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
        
    const WrongAnimal* test1 = new WrongCat("test1");
    const WrongAnimal* test2 = new WrongCat("test2");
    const WrongAnimal* test3 = new WrongAnimal();
    WrongAnimal test4("CatTest4");
    WrongAnimal test5;
    WrongCat test6("CatTest6");
    test5 = test4;
    std::cout << test1->getType() << std::endl;
    std::cout << test2->getType() << std::endl;
    std::cout << test3->getType() << std::endl;
    std::cout << test4.getType() << std::endl;
    std::cout << test5.getType() << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << test1->getType() << std::endl;
    test1->makeSound();
    test2->makeSound();
    test3->makeSound();
    test4.makeSound();
    test5.makeSound();
    test6.makeSound();
    std::cout << "-------------------------------------------------" << std::endl;
    delete test;
    delete test1;
    delete test2;
    delete test3;
    return(0);
}