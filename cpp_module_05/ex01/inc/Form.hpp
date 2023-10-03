/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:54 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/09/29 00:44:58 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include  <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string Name;
    const int ToExecuteGrade;
    const int ToSignGrade;
    bool IsSigned;
    
public:
    Form(std::string name, int execGrade, int signGrade);
    Form(const Form &copy);
    Form& operator=(const Form &copy);
    virtual ~Form();
    
    void beSigned(const Bureaucrat &b);
    
    std::string getName() const;
    int getExecGrade() const;
    int getSignGrade() const;
    bool getIsSigned() const;
    
    void setIsSigned(bool signature);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream &COUT, const Form &obj);

#endif
