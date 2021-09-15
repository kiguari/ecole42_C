/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimalClass.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:06:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:47:12 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMALCLASS_HPP
#define WRONGANIMALCLASS_HPP

#include "AnimalClass.hpp"

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal( const std::string str );
    WrongAnimal( const WrongAnimal &new_wrong_animal );
    WrongAnimal &operator= ( const WrongAnimal &new_wrong_animal );
    void makeSound() const;  
    std::string getType() const;
    ~WrongAnimal();
};

#endif