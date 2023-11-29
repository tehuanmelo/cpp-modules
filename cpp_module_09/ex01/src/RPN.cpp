/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:09:18 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/11/29 20:56:18 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& copy)
{
    *this = copy;
}

RPN& RPN::operator=(const RPN& copy)
{
    if (this == &copy)
        return *this;
    this->_stack = copy._stack;
    this->result = copy.result;
    return *this; 
}

RPN::~RPN()
{
}

bool RPN::calculate(const double &n1, const double &n2, const int &op)
{
    switch (op)
    {
    case '+':
        this->result = n1 + n2;
        break;
    case '-':
        this->result = n1 - n2;
        break;
    case '*':
        this->result = n1 * n2;
        break;
    case '/':
        if (n2 == 0)
            return false;
        this->result = n1 / n2;
        break;
    }
    this->_stack.push(this->result);
    return true;
}

bool RPN::readInput(const std::string &input)
{
    double n1, n2;
    int operands = 0, operators = 0;
    if (input.find_first_not_of("0123456789-+*/ ") != std::string::npos)
        return false;
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (isspace(input[i]))
            continue;
        else if (isdigit(input[i]))
        {
            operands++;
            this->_stack.push(input[i] - '0');
        }
        else
        {
            if (this->_stack.size() < 2)
                return false;
            operators++;
            char op = input[i];
            n2 = this->_stack.top();
            this->_stack.pop();
            n1 = this->_stack.top();
            this->_stack.pop();
            if (!this->calculate(n1, n2, op))
                return false;
        }
    }

    return operators + 1 == operands;
}

double RPN::getStackTop()
{
    return this->_stack.top();
}
