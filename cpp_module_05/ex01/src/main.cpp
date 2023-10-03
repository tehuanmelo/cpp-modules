/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/03 15:37:48 by tde-melo         ###   ########.fr       */
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
    std::cerr << bureaucrat1.getName() << " can't sign the " 
    << form1.getName() << " because " << e.what() << "\n\n";
   }
   
   
   Bureaucrat bureaucrat2("Ben Harper", 89);
   Form form2("Labour contract", 34, 54);
   
    std::cout << std::endl;
    
   try {
    std::cout << bureaucrat2 << std::endl;
    std::cout << form2 << std::endl;
    bureaucrat2.signForm(form2);
   }
   catch(const std::exception& e) {
    std::cerr << bureaucrat2.getName() << " can't sign the " 
    << form2.getName() << " because " << e.what() << "\n\n";
   }

    return 0;
}