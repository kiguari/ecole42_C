/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:30:59 by eshakita          #+#    #+#             */
/*   Updated: 2021/09/17 11:24:37 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    std::string name; // имя файла
    std::ifstream input_file; // входной файл
    std::string output_file_name; // имя исходящего файла
    std::ofstream output_file; // исходящий файл
    std::string s1; // argv 1
    std::string s2; // argv 2
    std::string input; // тестовый вывод
    std::size_t position = 0; // для фаинда
    std::size_t i; // счетчик; 
      
    if(argc != 4)
    {
        std::cout << "wrong argc1" << std::endl;
        return(1);
    }
    name = argv[1];
    s1 = argv[2];
    s2 = argv[3];      
    input_file.open(name);
    if((!input_file ) || (s1.length() == 0 || s2.length() == 0))
    {
        std::cout << "wrong argc" << std::endl;
        return(1);
    }
    i = 0;
    while(name[i])
    {
        output_file_name += (char)std :: toupper(name[i]);
        i++;
    }
    output_file_name += ".replace";
    output_file.open(output_file_name);
    while(std::getline(input_file, input))
    {
        i = 0;
        while(i <= input.length())
        {
            position = input.find(s1, i);
            
            if(position == i)
            {
                input.erase(position, s1.length());
                input.insert(position, s2);
                i += s2.length();
            }
            else
                i++;
        }
        output_file << input;
        output_file << "\n";
    }
    return (0);
}