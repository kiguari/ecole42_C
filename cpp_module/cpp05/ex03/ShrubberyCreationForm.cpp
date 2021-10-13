/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:21:22 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/13 12:53:08 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm - test form", 145, 137)
{
    this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &new_target) : Form("ShrubberyCreationForm", 145, 137)
{
    this->target = new_target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &new_form) : Form("ShrubberyCreationForm", 145, 137)
{
    this->target = new_form.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &new_form)
{
    this->target = new_form.target;
    return(*this);
}


void ShrubberyCreationForm::Action() const
{
    std::ifstream   input_file;
    std::ofstream   output_file;
    std::string     output_file_name = this->target + "_shrubbery";
    std::string     input;
    input_file.open(".asciithree");
    output_file.open(output_file_name);
    if(!input_file)
    {
        output_file << "ASCII THREE"  << "\n";
        output_file << "---" << "\n";
        output_file << " | " << "\n";
        output_file << "---" << "\n";
        output_file << " | " << "\n";
        output_file << "---" << "\n";
        output_file << " | " << "\n";
        output_file << " | " << "\n";
        output_file << " | " << "\n";
        output_file << " | " << "\n";
    }
    else
    {
        while(std::getline(input_file, input))
        {
            output_file << input;
            output_file << "\n";
        }
    }
    // std::cout << "ShrubberyCreationForm ACTION complite, see " << output_file_name << "file" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}