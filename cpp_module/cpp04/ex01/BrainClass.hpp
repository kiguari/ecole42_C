/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:48:52 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/06 14:43:52 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINCLASS_HPP
#define BRAINCLASS_HPP

#include "AnimalClass.hpp"

class Brain
{
private:
    std::string called_ideas[100];
public:
    Brain();
    Brain( std::string str );
    Brain( const Brain &new_brain );
    Brain &operator= ( const Brain &new_brain );
    std::string idea_geter(int code) const;
    void idea_seter(int i, std::string new_idea);
    ~Brain();
};



#endif