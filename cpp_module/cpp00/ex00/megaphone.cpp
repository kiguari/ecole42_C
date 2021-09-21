/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:06:46 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/16 13:57:57 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	int i = 1;
	if (argc == 1)
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
	else
	{
		std::string std;
		while(argv[i])
		{
			std += argv[i];
			i++;
		}
		i = 0;
		while(std[i])
		{
			std :: cout << (char)std :: toupper(std[i]);
			i++;
		}
		std :: cout << "\n";
	}
	return(0);
}