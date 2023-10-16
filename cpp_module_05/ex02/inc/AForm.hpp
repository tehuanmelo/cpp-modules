/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:54 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/06 17:23:55 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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
    // CONSTRUCTORS
    AForm(std::string name, int execGrade, int signGrade);
    AForm(const AForm &copy);
    AForm& operator=(const AForm &copy);
    virtual ~AForm();
    
    // GETTERS AND SETTERS
    std::string getName() const;
    int getExecGrade() const;
    int getSignGrade() const;
    bool getIsSigned() const;
    
    void beSigned(const Bureaucrat &b);
    virtual void execute(Bureaucrat const& executor) const = 0;
    bool checkFormRequirements(const Bureaucrat& executor) const;
    
    // EXCEPTION NESTED CLASSES
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
