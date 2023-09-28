/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:08:28 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/09/28 18:23:37 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : Name(name) {
    std::cout << "Constructor called" << std::endl;
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : Name(copy.Name) {
    std::cout << "Copy constructor called" << std::endl;
    Grade = copy.Grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    std::cout << "Copy assignment operator constructor called" << std::endl;
    if (this != &copy)
        Grade = copy.Grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Deconstructor called" << std::endl;
}

void Bureaucrat::setGrade(int grade) {
    // try
    // {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        Grade = grade;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

std::ostream &operator<<(std::ostream &COUT, const Bureaucrat &obj) {
    return (COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}

