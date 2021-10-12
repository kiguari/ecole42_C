/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:32:01 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 15:51:33 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSourceClass.hpp"

/*
Классы Ice и Cure являются наследниками AMatria. AMateria - абстрактный класс.

Интерфейс - это класс, который не имеет переменных-членов 
и все методы которого являеются виртуальными функциями
Люблй класс который наследует интерфейсный класс должен содержать 
определение всех методов интерфейса.
Название интерфейса следует начинать с I, например IMateriaSourceClass.
Название абстрактного класса следует начинать с A, например AMateria.

В сабджекте сказано, что unequip не должен делать delete,
таким образом мы получим утечку
что бы это обойти, можно сделать дополнительный массив указателей
и в unequip перезаписывать в него и потом уже в удобном месте
его делетить за пределами unequip
*/

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    // me->unequip(0);
    // me->unequip(1);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // me->equip(tmp);
    
    delete bob;
    delete me;
    delete src;

    return(0);
}

// Output:
// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e
// * shoots an ice bolt at bob *$
// * heals bob's wounds *$