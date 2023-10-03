/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/01 21:28:38 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    Bureaucrat bureaucrat1("Jack Johnson", 30);
    Form form1("Salary Letter", 10, 20); 

    Bureaucrat b(bureaucrat1);
    Bureaucrat c(b);
    c = bureaucrat1;

    std::cout << std::endl;
    
   try {
    std::cout << bureaucrat1 << std::endl;
    std::cout << form1 << std::endl;
    form1.beSigned(bureaucrat1);
    std::cout << std::endl;
   }
   catch(const std::exception& e) {
    std::cerr << form1.getName() << " can't be signed by "
    << bureaucrat1.getName() << " because form's " << e.what() << "\n\n";
   }
   
   
   Bureaucrat Bureaucrat2("Ben Harper", 89);
   Form form2("Labour contract", 34, 54);
   
    std::cout << std::endl;
    
   try {
    std::cout << Bureaucrat2 << std::endl;
    std::cout << form2 << std::endl;
    Bureaucrat2.signForm(form2);
   }
   catch(const std::exception& e) {
    std::cerr << Bureaucrat2.getName() << " can't sign the " 
    << form2.getName() << " because bureaucrat's " << e.what() << "\n\n";
   }

    return 0;
}