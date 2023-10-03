/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:01:40 by tde-melo          #+#    #+#             */
/*   Updated: 2023/10/03 19:13:41 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Form", 137, 145), Target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : 
AForm(copy), Target(copy.Target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getExecGrade()) 
        throw AForm::GradeTooLowException();
        
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    } else {
        std::string fileName = this->Target + "_shrubbery";
        std::fstream outfile;
        outfile.open(fileName, std::ios::out);
        if (outfile.is_open()) {
            for (int i = 0; i < 5; i++) {
			outfile <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		    std::endl;
		}
            outfile.close();
        }
        std::cout << executor.getName() << " executed " << fileName << std::endl;
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
            << "Grade required to sign it " << obj.getSignGrade() << std::endl
            << "Grade required to execute it " << obj.getExecGrade() << std::endl
            << "Status: " << signature
        );
}
