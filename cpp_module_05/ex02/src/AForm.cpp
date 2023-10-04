/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:55:42 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/03 15:38:47 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(std::string name, int execGrade, int signGrade) : 
Name(name) , ToExecuteGrade(execGrade), ToSignGrade(signGrade), IsSigned(false) {
    if (this->ToExecuteGrade > 150 || this->ToSignGrade > 150)
        throw AForm::GradeTooLowException();
    else if (this->ToExecuteGrade < 1 || this->ToSignGrade < 1)
        throw AForm::GradeTooHighException();
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : 
Name(copy.Name), ToExecuteGrade(copy.ToExecuteGrade), 
ToSignGrade(copy.ToSignGrade), IsSigned(copy.IsSigned) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy) {
    if (this != &copy)
        this->IsSigned = copy.IsSigned;
    std::cout << "AForm assigment constructor called" << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm deconstructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (this->IsSigned)
        std::cout << "AForm " << getName() << " is already signed" << std::endl;
    else if (b.getGrade() > this->ToSignGrade) 
        throw AForm::GradeTooLowException();
    else {
        this->IsSigned = true;
        std::cout << b.getName() << " has signed " << getName() << std::endl;
    }
}

std::string AForm::getName() const {
    return this->Name;
}

int AForm::getExecGrade() const {
    return this->ToExecuteGrade;
}

int AForm::getSignGrade() const {
    return this->ToSignGrade;
}

bool AForm::getIsSigned() const {
    return this->IsSigned;
}

bool AForm::checkFormRequirements(const Bureaucrat& executor) const{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (!this->IsSigned)
        throw AForm::FormNotSignedException();
    return true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream &operator<<(std::ostream &COUT, const AForm &obj) {
    std::string signature;
    if (obj.getIsSigned())
        signature = "Signed";
    else    
        signature = "Not Signed";
        
    return (COUT << "AForm: " << obj.getName() << std::endl 
            << "Grade required to sign it " << obj.getSignGrade() << std::endl
            << "Grade required to execute it " << obj.getExecGrade() << std::endl
            << "Status: " << signature
        );
}