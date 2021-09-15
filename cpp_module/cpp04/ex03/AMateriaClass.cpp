/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:08:00 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/14 17:51:07 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateriaClass.hpp"

AMateria::AMateria()
{
    std::cout << "AmateriaClass default constructor called" << std::endl;
    this->Amateria_type = "default";
}

AMateria::AMateria( std::string const & type )
{
    std::cout << "AmateriaClass string constructor called" << std::endl;
    this->Amateria_type = type;
}