/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacterClass.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:38:07 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/14 16:03:31 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTERCLASS_HPP
#define ICHARACTERCLASS_HPP

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equi(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int iidx, ICharacter& target) = 0;
};

#endif