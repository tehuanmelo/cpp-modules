/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:09:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/12/27 22:00:30 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

class RPN
{
private:
    std::list<double> stack;
    double result;

public:
    RPN();
    RPN(const std::string input);
    RPN(const RPN &copy);
    ~RPN();
    RPN &operator=(const RPN &copy);

    void readInput(const std::string &input);
    bool calculate(const double &n1, const double &n2, const int &op);
    double getStackTop();
    void printResult();
};

void error();

#endif