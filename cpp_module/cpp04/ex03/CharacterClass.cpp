/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:23:02 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 14:37:28 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharacterClass.hpp"

Character::Character()
{
    this->name = "no_namerz";
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for(int j = 0; j < 5; j++)
        inventory_trash[j] = NULL;
}

Character::Character( const std::string &new_name)
{
    this->name = new_name;
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for(int j = 0; j < 5; j++)
        inventory_trash[j] = NULL;
}

Character::Character( const Character &new_character)
{
    *this = new_character;
}

Character &Character::operator=( const Character &new_character)
{
    this->name = new_character.name;
    for(int i = 0; i < 4; i++)
    {
        if(new_character.inventory[i])
        {
            if(this->inventory[i])
                delete this->inventory[i];
            this->inventory[i] = new_character.inventory[i]->clone();
        }
        else
        {
            if(this->inventory[i])
            {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }
    }
    for(int j = 0; j < 5; j++)
        inventory_trash[j] = NULL;
    return(*this);
}

std::string const &Character::getName() const
{
    return(this->name);
}

void Character::equip(AMateria *m)
{
    if(!m)
        return;
    for(int i = 0; i < 4; i++)
    {
        if(this->inventory[i] == m)
            return;
    }
    for(int j = 0; j < 5; j++)
    {
        if(this->inventory_trash[j] != NULL)
        {
            delete this->inventory_trash[j];
            this->inventory_trash[j] = NULL;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(this->inventory[i] == NULL)
        {
            // this->inventory[i] = m->clone();
            this->inventory[i] = m;
            // delete m;
            break;
        }
    }
    
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return;
    // delete this->inventory[idx];
    for(int j = 0; j < 5; j++)
    {
        if(this->inventory_trash[j] == NULL)
        {
            this->inventory_trash[j] = this->inventory[idx];
            break;
        }
        
    }
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        return;
    if(inventory[idx])
        inventory[idx]->use(target);
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        if(this->inventory[i] != NULL)
            delete this->inventory[i];
    }
    for(int j = 0; j < 5; j++)
    {
        if(this->inventory_trash[j] != NULL)
            delete this->inventory_trash[j];
    }
    
}