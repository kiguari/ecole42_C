/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:35:58 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/16 17:33:46 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class cont
{
    private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darknest_secret;
    public:
    cont();
    void indexx(int count);
    void add_cont();
    void cout_cont();
    void cout_cont_search();
    void make_table_line(std::string line);
    ~cont();
};

#endif