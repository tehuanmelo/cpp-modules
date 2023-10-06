/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:55:42 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/05 23:13:57 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(std::string name, int execGrade, int signGrade) : 
Name(name) , ToExecuteGrade(execGrade), ToSignGrade(signGrade), IsSigned(false) {
    if (this->ToExecuteGrade > 150 || this->ToSignGrade > 150)
        throw Form::GradeTooLowException();
    else if (this->ToExecuteGrade < 1 || this->ToSignGrade < 1)
        throw Form::GradeTooHighException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& copy) : 
Name(copy.Name), ToExecuteGrade(copy.ToExecuteGrade), 
ToSignGrade(copy.ToSignGrade), IsSigned(copy.IsSigned) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& copy) {
    if (this != &copy)
        this->IsSigned = copy.IsSigned;
    std::cout << "Form assigment constructor called" << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << "Form deconstructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &b) {
    if (this->IsSigned)
        std::cout << "Form " << getName() << " is already signed" << std::endl;
    else if (b.getGrade() > this->ToSignGrade) 
        throw Form::GradeTooLowException();
    else {
        this->IsSigned = true;
        std::cout << b.getName() << " has signed " << getName() << std::endl;
    }
}

std::string Form::getName() const {
    return this->Name;
}

int Form::getExecGrade() const {
    return this->ToExecuteGrade;
}

int Form::getSignGrade() const {
    return this->ToSignGrade;
}

bool Form::getIsSigned() const {
    return this->IsSigned;
}

bool Form::checkFormRequirements(const Bureaucrat& executor) const{
    if (executor.getGrade() > this->getExecGrade())
        throw Form::GradeTooLowException();
    if (!this->IsSigned)
        throw Form::FormNotSignedException();
    return true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* Form::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream &operator<<(std::ostream &COUT, const Form &obj) {
    std::string signature;
    if (obj.getIsSigned())
        signature = "Signed";
    else    
        signature = "Not Signed";
        
    return (COUT << "Form: " << obj.getName() << std::endl 
            << "Grade required to sign it " << obj.getSignGrade() << std::endl
            << "Grade required to execute it " << obj.getExecGrade() << std::endl
            << "Status: " << signature
        );
}