/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:08:28 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/09/29 00:37:10 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : Name(name) {
    setGrade(grade);
    std::cout << "Bureaucrat " << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : Name(copy.Name) {
    this->Grade = copy.Grade;
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        this->Grade = copy.Grade;
    std::cout << "Bureaucrat assignment constructor called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat deconstructor called" << std::endl;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->Grade = grade;
    
}

std::string Bureaucrat::getName() const {
    return Name;
}

int Bureaucrat::getGrade() const {
    return Grade;
}

void Bureaucrat::incrementGrade() {
    setGrade(Grade - 1);
}

void Bureaucrat::decrementGrade() {
    setGrade(Grade + 1);
}

void Bureaucrat::signForm(Form &f) {
    if (f.getIsSigned())
        std::cout << "Form " << getName() << " is already signed" << std::endl;
    else if (this->getGrade() > f.getSignGrade()) 
        throw Form::GradeTooLowException();
    else {
        f.setIsSigned(true);
        std::cout << this->getName() << " has signed the " << f.getName() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

std::ostream &operator<<(std::ostream &COUT, const Bureaucrat &obj) {
    return (COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}

