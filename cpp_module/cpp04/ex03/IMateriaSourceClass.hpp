/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSourceClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:46:29 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 13:56:58 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCECLASS_HPP
#define IMATERIASOURCECLASS_HPP

#include "AMateriaClass.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {};
    virtual void learnMateria(AMateria*) = 0; 
    /*
    метод должен скопировать Materia и должен сохранить в памяти для последующего клонирования. 
    Так же как и для Character, Source не может знать более 4 Materia которые не обязательно уникальны.
    */
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif