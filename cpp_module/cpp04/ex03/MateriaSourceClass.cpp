/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSourceClass.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:30:13 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 13:56:05 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSourceClass.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        this->library[i] = NULL;
    }
    // std::cout << "default MateriaSource constructor called, all library is NULL" << std::endl;
}

MateriaSource::MateriaSource( std::string const &new_mat_source)
{
    if(!new_mat_source.empty())
    {
        for(int i = 0; i < 4; i++)
        {   
            this->library[i] = NULL;
        }
    }
}

MateriaSource::MateriaSource( const MateriaSource &new_mat_source)
{
    *this = new_mat_source;
}

MateriaSource &MateriaSource::operator= (const MateriaSource &new_mat_source)
{
    for(int i = 0; i < 4; i++)
    {
        if(new_mat_source.library[i])
        {
            if(this->library[i])
                delete this->library[i];
            this->library[i] = new_mat_source.library[i]->clone();
        }
        else
        {
            if(this->library[i])
            {
                delete this->library[i];
                this->library[i] = NULL;
            }
        }
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if(this->library[i] != NULL)
            delete this->library[i];
    }
    // std::cout << "default MateriaSource destructor called, all library delete" << std::endl;
}

void MateriaSource::learnMateria(AMateria* new_materia)
{
    for(int i = 0; i < 4; i++)
    {
        if(library[i] == NULL)
        {
            library[i] = new_materia;
            // library[i] = new_materia->clone();
            // std::cout << "new materia learning complet" << std::endl;
            // break;
            return;
        }
    }
    // std::cout << "all cells of lybrary are full, cant learn new materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if(type.empty())
    {
        // std::cout << "error - wrong type for create new materia" << std::endl; 
        return 0;
    }
    for(int i = 0; i < 4; i++)
    {
        
        if(this->library[i] && this->library[i]->getType() == type)
        {
            return (this->library[i]->clone());
            // return (this->library[i]);
        }
    }
    // std::cout << "error - wrong type for create new materia" << std::endl; 
    return 0;
}
