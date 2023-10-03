/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/03 19:24:55 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat bu("tehuan", 20);
    ShrubberyCreationForm sh("home");

    bu.signForm(sh);
    std::cout << sh << std::endl;
    bu.executeForm(sh);





    return 0;
}