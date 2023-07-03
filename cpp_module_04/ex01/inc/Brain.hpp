/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/02 15:27:33 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string.h>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESETCOLOR "\033[0m"

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& copy);
    Brain& operator=(const Brain& copy);
    virtual ~Brain();
    void setIdeas(int i, std::string idea);
    std::string getIdea(int i) const;
};

#endif