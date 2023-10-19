/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:25:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/19 17:56:40 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/easyfind.hpp"

int main() {
    
    try
    {
        std::vector<int> numbers;

        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        std::vector<int>::iterator value;
        value = easyfind(numbers, 1);
        std::cout << *value << std::endl;
        *value = 42;
        std::cout << numbers[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}


