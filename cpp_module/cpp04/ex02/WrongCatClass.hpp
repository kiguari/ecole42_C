/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCatClass.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:11:59 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/08 16:15:33 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCATCLASS_HPP
#define WRONGCATCLASS_HPP

#include "WrongAnimalClass.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
    WrongCat();
    WrongCat( std::string str );
    WrongCat( const WrongCat &new_cat );
    WrongCat &operator= ( const WrongCat &new_cat );
    ~WrongCat();
};

#endif