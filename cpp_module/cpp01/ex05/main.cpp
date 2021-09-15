/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:44:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/02 17:31:07 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main()
{
    Karen Karen;
    Karen.complain("DEBUG");
    Karen.complain("INFO");
    Karen.complain("WARNING");
    Karen.complain("ERROR");
    Karen.complain("");
    Karen.complain("gfhg");
    return (0);
}
