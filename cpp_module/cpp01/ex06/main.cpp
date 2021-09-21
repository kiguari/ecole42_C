/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:44:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 12:00:07 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int ft_chose(std::string command)
{
    std::string lev[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while(lev[i] != command && i < 5)
        i++;
    return(i);
}

int main(int argc, char **argv)
{
    Karen Karen;
    std::string command;
    int i = 0;
    int j = 0;
    (void)argc;
    while(argv[1] && argv[1][i])
    {
        command += (char)std :: toupper(argv[1][i]);
        i++;
    }
    j = ft_chose(command);
    switch (j)
    {
    case 0:
        Karen.complain("DEBUG");
    case 1:
        Karen.complain("INFO");
    case 2:
        Karen.complain("WARNING");
    case 3:
        Karen.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
    return (0);
}
