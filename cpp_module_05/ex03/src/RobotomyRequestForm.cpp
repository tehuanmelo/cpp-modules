/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:01:40 by tde-melo          #+#    #+#             */
/*   Updated: 2023/10/03 22:00:43 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("Robotomy Request Form", 45, 72), Target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : 
Form(copy), Target(copy.Target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=
(const RobotomyRequestForm& copy) {
    if (this != &copy)
        return *this;
    return *this;
    std::cout << "RobotomyRequestForm assignment constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm deconstructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->Target;
}

int robotomy_counter = 0;
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (this->checkFormRequirements(executor)) {
        if (!robotomy_counter++ % 2) {
            std::cout << "DRRRRRRRRRRRLL!!!! " << 
            this->Target << " has been robotomyzed" << std::endl;
        } else {
            std::cout << "Robotomy failed" << std::endl;
        }
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &COUT, const RobotomyRequestForm &obj) {
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
