/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:03:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/06 16:10:55 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrainClass.hpp"

Brain::Brain()
{
    std::cout << "BrainClass default constructor called" << std::endl;
    this->called_ideas[0] = "i dont have brain, i cant have ideas!";
    for(int i = 1; i < 100; i++)
    {
        called_ideas[i] = "default"; //+ std::to_string(i)
    }
}

Brain::Brain( std::string str)
{
    std::cout << "BrainClass  constructor called" << std::endl;
    this->called_ideas[0] = "i have ideas! " + str;
    for(int i = 1; i < 100; i++)
    {
        called_ideas[i] = str;
    }
}

Brain::Brain( const Brain &new_brain )
{
    std::cout << "BrainClass value constructor = called " << std::endl;
    // this->called_ideas[0] = new_brain.idea_geter(0);
    for(int i = 1; i < 100; i++)
    {
        this->called_ideas[i] = new_brain.idea_geter(i);
    }
}

Brain &Brain::operator= ( const Brain &new_brain)
{
    std::cout << "BrainClass Assignation operator called" << std::endl;
    // this->called_ideas[0] = new_brain.idea_geter(0);
    for(int i = 0; i < 100; i++)
    {
        this->called_ideas[i] = new_brain.idea_geter(i);
    }
    return(*this);
}

std::string Brain::idea_geter(int code) const
{
    if(code > 99 || code < 0)
        return("wrong code !!!");

    // std::cout << this->called_ideas[code] << std::endl;
    return(this->called_ideas[code]);
}

void Brain::idea_seter(int i, std::string new_idea)
{
    // if(this->called_ideas[0] != "i dont have brain, i cant have ideas!")
    this->called_ideas[i] = new_idea;     
}
Brain::~Brain()
{
    std::cout << "BrainClass destructor called" << std::endl;
}