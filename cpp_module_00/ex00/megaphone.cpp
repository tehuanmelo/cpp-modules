/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:00:06 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/05 16:38:38 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string trimString(std::string str) {
    size_t start = 0;
    size_t end = str.length() - 1;
    for (;start <= end; start++) 
        if (str[start] != ' ')
            break;
    for (;end > start; end--)
        if (str[end] != ' ')
            break;
    return (str.substr(start, (end - start) + 1));
}

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++) {
            std::string word = trimString(av[i]);
            for (int j = 0; word[j]; j++)
                std::cout << char(std::toupper(word[j]));
            if (ac > 1)
                std::cout << ' ';
        }
    }
    std::cout << std::endl;
}
