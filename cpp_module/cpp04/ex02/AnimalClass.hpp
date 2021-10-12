/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:42:02 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/06 17:09:36 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALCLASS_HPP
#define ANIMALCLASS_HPP

#include <string>
#include <iostream>

/*
что бы еще сильнее запретить создание класса Анимал пользователем,
можно поместить конструкторы под модификатор протектед,
но в маке объявление одного из методов чисто вируальным ("=0" уже запретит создание этого класса пользователем)
*/

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal( const std::string str );
    Animal( const Animal &new_animal );
    Animal &operator= ( const Animal &new_animal );
    virtual void makeSound() const = 0;
    // virtual void makeSound() const;  
    std::string getType() const;
    virtual ~Animal();
};

#endif