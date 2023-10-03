/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:58:57 by tde-melo          #+#    #+#             */
/*   Updated: 2023/10/03 19:12:46 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string Target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        std::string getTarget() const {
            return Target;
        }

        void execute(Bureaucrat const& executor) const;
        
};

std::ostream& operator<<(std::ostream &COUT, const ShrubberyCreationForm &obj);





#endif

