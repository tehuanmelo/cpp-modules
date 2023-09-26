/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:08:28 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/09/26 22:05:07 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : Name(name) {
    std::cout << "Constructor called" << std::endl;
    Grade = grade;
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

std::string Bureaucrat::getName() {
    return Name;
}

int Bureaucrat::getGrade() {
    return Grade;
}

std::ostream &operator<<(std::ostream &COUT, Bureaucrat &obj) {
    return (COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}

