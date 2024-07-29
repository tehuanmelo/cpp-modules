/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:25:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2024/07/22 13:48:45 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/easyfind.hpp"

int main() {
    
    try {
        std::vector<int> numbers;
        for (int i = 1; i < 11; i++)
            numbers.push_back(i);
            
        for (int i = 0; i < 10; i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        
        std::vector<int>::iterator it;
        it = easyfind(numbers, 19);
        
        std::cout << *it << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        std::list<int> numbers;
        for (int i = 1; i < 11; i++)
            numbers.push_back(i);

        std::list<int>::iterator i = numbers.begin();
        for (; i != numbers.end(); i++)
            std::cout << *i << " ";
        std::cout << std::endl;
        
        std::list<int>::iterator it;
        it = easyfind(numbers, 10);
        
        std::cout << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}


