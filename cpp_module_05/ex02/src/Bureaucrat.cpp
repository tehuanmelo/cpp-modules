/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:08:28 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/03 19:02:55 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

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

void Bureaucrat::signForm(AForm &f) {
    f.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form) {
    form.execute(*this);
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

