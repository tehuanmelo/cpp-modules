/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:28:34 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/03 16:35:41 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string.h>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESETCOLOR "\033[0m"

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal& operator=(const WrongAnimal& copy);
    virtual ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};

#endif