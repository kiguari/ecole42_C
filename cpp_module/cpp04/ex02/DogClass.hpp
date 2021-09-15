/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:48:31 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/09 12:11:11 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOGCLASS_HPP
#define DOGCLASS_HPP

#include "AnimalClass.hpp"
#include "BrainClass.hpp"

class Dog : public Animal
{
private:
    Brain* Dog_brain;
public:
    Dog();
    Dog( std::string str );
    Dog( const Dog &new_dog );
    Dog &operator= ( const Dog &new_dog );
    void makeSound() const;
    ~Dog();
};

#endif