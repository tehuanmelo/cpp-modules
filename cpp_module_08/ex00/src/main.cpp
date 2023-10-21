/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:25:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/21 18:46:34 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/easyfind.hpp"

int main() {
    
    try {
        std::vector<int> numbers;
        for (int i = 1; i < 11; i++)
            numbers.push_back(i);
        std::vector<int>::iterator it;
        it = easyfind(numbers, 10);
        std::cout << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        std::list<int> numbers;
        for (int i = 1; i < 11; i++)
            numbers.push_back(i);
        std::list<int>::iterator it;
        it = easyfind(numbers, 10);
        std::cout << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}


