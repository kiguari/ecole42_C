/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:42:02 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:22 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALCLASS_HPP
#define ANIMALCLASS_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal( const std::string str );
    Animal( const Animal &new_animal );
    Animal &operator= ( const Animal &new_animal );
    virtual void makeSound() const;  
    std::string getType() const;
    virtual ~Animal();
};

#endif