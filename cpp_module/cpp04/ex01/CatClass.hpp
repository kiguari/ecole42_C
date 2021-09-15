/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:44:50 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 18:05:24 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCLASS_HPP
#define CATCLASS_HPP

#include "AnimalClass.hpp"
#include "BrainClass.hpp"

class Cat : public Animal
{
private:
    Brain* Cat_brain;
public:
    Cat();
    Cat( std::string str );
    Cat( const Cat &new_cat );
    Cat &operator= ( const Cat &new_cat );
    void makeSound() const;
    ~Cat();
};

#endif