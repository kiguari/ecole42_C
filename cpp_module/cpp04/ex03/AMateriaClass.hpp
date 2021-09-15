/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaClass.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:08:02 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/14 17:18:30 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIACLASS_HPP
#define AMATERIACLASS_HPP

#include <string>
#include <iostream>

class AMateria
{
    protected:
        std::string Amateria_type;
    
    public:
        AMateria();
        AMateria( const AMateria &new_amateria);
        AMateria &operator= (const AMateria &new_amateria);
        
        AMateria(std::string const & type);
        
        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        ~AMateria();
};

#endif
