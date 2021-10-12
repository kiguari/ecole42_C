/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:03:51 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/08 14:09:20 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTERCLASS_HPP
# define CHARACTERCLASS_HPP

#include "ICharacterClass.hpp"

class Character : public ICharacter
{
private:
    AMateria* inventory[4];
    AMateria* inventory_trash[5];
    std::string name;

public:
    Character();
    Character( const std::string &new_name);
    Character( const Character &new_character);
    Character &operator= (const Character &new_character);

    std::string const & getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

    ~Character();  
};

#endif