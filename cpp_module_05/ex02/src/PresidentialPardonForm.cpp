/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:01:40 by tde-melo          #+#    #+#             */
/*   Updated: 2023/10/03 22:00:43 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", 5, 25), Target(target) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : 
AForm(copy), Target(copy.Target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=
(const PresidentialPardonForm& copy) {
    if (this != &copy)
        return *this;
    return *this;
    std::cout << "PresidentialPardonForm assignment constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm deconstructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->Target;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (this->checkFormRequirements(executor)) 
            std::cout << this->Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &COUT, const PresidentialPardonForm &obj) {
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
