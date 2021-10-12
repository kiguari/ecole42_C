/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSourceClass.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:59:51 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 15:51:24 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCECLASS_HPP
#define MATERIASOURCECLASS_HPP

#include "IMateriaSourceClass.hpp"
#include "IceClass.hpp"
#include "CureClass.hpp"
#include "CharacterClass.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* library[4];

public:
    MateriaSource();
    MateriaSource( std::string const &new_mat_source);
    MateriaSource( const MateriaSource &new_mat_source);
    MateriaSource &operator= (const MateriaSource &new_mat_source);

    ~MateriaSource();
    void learnMateria(AMateria*);
    /*
    смотрим если у нас свободная ячейка для того, что бы изучить новую материю (скил)
    если есть, то изучаем, если нет, то ничего не делаем.
    изучив одну материю завершаем метод.
    */
    AMateria* createMateria(std::string const & type);
    /*
    смотрим знаем ли мы такую материю, если знаем, 
    то возвращаем ее клон, если нет, то ничего не далаем.
    */
};

#endif