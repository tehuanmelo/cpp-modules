/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:09:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/11/29 20:57:14 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

class RPN {
private:
    std::stack<double> _stack;
    double result;
public:
    RPN();
    RPN(const RPN& copy);
    ~RPN();
    RPN& operator=(const RPN& copy);
    
    bool readInput(const std::string &input);
    bool calculate(const double &n1, const double &n2, const int &op);
    double getStackTop();
};

#endif