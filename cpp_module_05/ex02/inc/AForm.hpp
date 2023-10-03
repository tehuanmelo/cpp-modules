/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:54 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/03 18:30:28 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include  <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string Name;
    const int ToExecuteGrade;
    const int ToSignGrade;
    bool IsSigned;
    
public:
    AForm(std::string name, int execGrade, int signGrade);
    AForm(const AForm &copy);
    AForm& operator=(const AForm &copy);
    virtual ~AForm();
    
    void beSigned(const Bureaucrat &b);
    
    // pure virtual function implementation must be in the derived class
    virtual void execute(Bureaucrat const& executor) const = 0;
    
    std::string getName() const;
    int getExecGrade() const;
    int getSignGrade() const;
    bool getIsSigned() const;
    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    
    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream &COUT, const AForm &obj);

#endif
