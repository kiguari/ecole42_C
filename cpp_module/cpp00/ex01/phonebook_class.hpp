/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:37:19 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/31 14:43:49 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "contact_class.hpp"

class phonebook
{
    private:
    cont cont[8];
    int count;
    int last_cont;
    public:
    phonebook(): count(0), last_cont(0)
    {}
    void add_to_phonebook();
    void add_cout_cont();
    void ft_search();
};

#endif