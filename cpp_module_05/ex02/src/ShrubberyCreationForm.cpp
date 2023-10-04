/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:01:40 by tde-melo          #+#    #+#             */
/*   Updated: 2023/10/04 22:11:21 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 137, 145), Target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : 
AForm(copy), Target(copy.Target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=
(const ShrubberyCreationForm& copy) {
    if (this != &copy)
        return *this;
    return *this;
    std::cout << "ShrubberyCreationForm assignment constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm deconstructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->Target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
   
    if (checkFormRequirements(executor)) {
        std::string fileName = this->Target + "_shrubbery";
        std::fstream outfile;
        outfile.open(fileName, std::ios::out);
        if (outfile.is_open()) {
            for (int i = 0; i < 10; i++) {
                outfile <<
                "         A" << std::endl <<
                "        AAA" << std::endl <<
                "      .AAAAA." << std::endl <<
                "     .AAAAAAA." << std::endl <<
                "      AAAAAAA" << std::endl <<
                "    .AAAAAAAAA." << std::endl <<
                "   .AAAAAAAAAAA." << std::endl <<
                "     AAAAAAAAA" << std::endl <<
                "   .AAAAAAAAAAA." << std::endl <<
                "  .AAAAAAAAAAAAA." << std::endl <<
                "        ###" << std::endl <<
                "        ###" << std::endl <<
                "        ###" << std::endl <<
                std::endl;
		    }
            outfile.close();
        }
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &COUT, const ShrubberyCreationForm &obj) {
    std::string signature;
    if (obj.getIsSigned())
        signature = "Signed";
    else    
        signature = "Not Signed";
    return (COUT << "Form: " << obj.getName() << std::endl 
            << "Target: " << obj.getTarget() << std::endl
            << "Grade required to sign it: " << obj.getSignGrade() << std::endl
            << "Grade required to execute it: " << obj.getExecGrade() << std::endl
            << "Status: " << signature
        );
}
