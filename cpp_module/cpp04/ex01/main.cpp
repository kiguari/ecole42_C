/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:32:01 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 15:43:35 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass.hpp"
#include "DogClass.hpp"
#include "WrongCatClass.hpp"

int main()
{
    
    // std::cout << "-------------------------------------------------" << std::endl;
    // std::cout << "--------------- main from subject ---------------" << std::endl;
    // std::cout << "-------------------------------------------------" << std::endl;
    
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
    
    // delete meta;
    // delete j;
    // delete i;
    
    // // not subject main
    // std::cout << "-------------------------------------------------" << std::endl;
    // std::cout << "--------- no subject main - dop testing ---------" << std::endl;
    // std::cout << "-------------------------------------------------" << std::endl;
    // Cat cat1("mysya");
    // Animal* test = new Cat("barsik");
    // std::cout << test->getType() << std::endl;
    // test->makeSound();

    // std::cout << "-------------------------------------------------" << std::endl;
    // std::cout << "-------------- WRONG ANIMAL TESTING -------------" << std::endl;
    // std::cout << "-------------------------------------------------" << std::endl;
        
    // const WrongAnimal* test1 = new WrongCat("test1");
    // const WrongAnimal* test2 = new WrongCat("test2");
    // const WrongAnimal* test3 = new WrongAnimal();
    // WrongAnimal test4("CatTest4");
    // WrongAnimal test5;
    // WrongCat test6("CatTest6");
    // test5 = test4;
    // std::cout << test1->getType() << std::endl;
    // std::cout << test2->getType() << std::endl;
    // std::cout << test3->getType() << std::endl;
    // std::cout << test4.getType() << std::endl;
    // std::cout << test5.getType() << std::endl;
    // std::cout << "-------------------------------------------------" << std::endl;
    // std::cout << test1->getType() << std::endl;
    // test1->makeSound();
    // test2->makeSound();
    // test3->makeSound();
    // test4.makeSound();
    // test5.makeSound();
    // test6.makeSound();
    // std::cout << "-------------------------------------------------" << std::endl;
    // delete test1;
    // delete test2;
    // delete test3;

    Animal Animal1;
    
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "--------------- main from subject ---------------" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "--------------- main from subject ---------------" << std::endl;
    std::cout << "-------- main from subject ( arrey path )--------" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    
    Animal *Animal_arr[10]; // = new Animal*[10];
    int count = 0;
    while(count < 10)
    {
        if(count > 5)
            Animal_arr[count] = new Cat();
        else
            Animal_arr[count] = new Dog();
        Animal_arr[count]->makeSound();
        count++;
    }
    count = 0;
    while(count < 10)
    {
        delete Animal_arr[count];
        std::cout << count << std::endl;
        count++;
    }
    std::cout << count << std::endl;
    
    // delete [] Animal_arr;
    
    std::cout << "-------------------------------------------------" << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "--------- no subject main - dop testing ---------" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    Cat cat1("cat1");
    Cat cat2("cat2");
    Cat cat3(cat1);
    Cat cat4;
    cat4 = cat2;
    
    Brain brain1("brain1");
    Brain brain2("brain2");
    Brain brain3(brain1);
    Brain brain4;
    brain4 = brain2;

    Dog Dog1("Dog1");
    Dog Dog2("Dog2");
    Dog Dog3(Dog1);
    Dog Dog4;
    Dog4 = Dog2;
    
    brain1.idea_geter(0);
    brain2.idea_geter(0);
    brain3.idea_geter(0);
    brain4.idea_geter(0);
    brain4.idea_geter(1);

    cat1.makeSound();
    cat2.makeSound();
    cat3.makeSound();
    cat4.makeSound();

    Dog1.makeSound();
    Dog2.makeSound();
    Dog3.makeSound();
    Dog4.makeSound();

    return(0);
}