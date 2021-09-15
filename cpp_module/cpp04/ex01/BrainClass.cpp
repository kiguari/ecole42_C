/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:03:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/09 12:12:19 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrainClass.hpp"

Brain::Brain()
{
    std::cout << "BrainClass default constructor called" << std::endl;
    this->called_ideas[0] = "i dont have brain, i cant have ideas!";
}

Brain::Brain( std::string str)
{
    std::cout << "BrainClass  constructor called" << std::endl;
    this->called_ideas[0] = "i have ideas! " + str;
}

Brain::Brain( const Brain &new_brain )
{
    std::cout << "BrainClass value constructor = called " << std::endl;
    this->called_ideas[0] = new_brain.idea_geter(0);
}

Brain &Brain::operator= ( const Brain &new_brain)
{
    std::cout << "BrainClass Assignation operator called" << std::endl;
    this->called_ideas[0] = new_brain.idea_geter(0);
    return(*this);
}

std::string Brain::idea_geter(int code) const
{
    if(code != 0)
        return("wrong code !!!");
    return(this->called_ideas[code]);
}

void Brain::idea_seter(std::string new_idea)
{
    if(this->called_ideas[0] != "i dont have brain, i cant have ideas!")
        this->called_ideas[0] = new_idea;       
}
Brain::~Brain()
{
    std::cout << "BrainClass destructor called" << std::endl;
}