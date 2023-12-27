/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:09:18 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/12/27 22:04:05 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const std::string input)
{
    this->readInput(input);
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    if (this == &copy)
        return *this;
    if (!this->stack.empty())
        this->stack.clear();
    for (std::list<double>::const_iterator it = copy.stack.begin(); it != copy.stack.end(); it++)
        this->stack.push_back(*it);
    this->result = copy.result;
    return *this;
}

RPN::~RPN()
{
}

void RPN::printResult()
{
    // this condition is to make sure when to print integer and floats
    double value = static_cast<int>(this->getStackTop());
    if (value == this->getStackTop())
        std::cout << value << std::endl;
    else
        std::cout << this->getStackTop() << std::endl;
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
    this->stack.push_back(this->result);
    return true;
}

void RPN::readInput(const std::string &input)
{
    double n1, n2;
    int operands = 0, operators = 0;
    if (input.find_first_not_of("0123456789-+*/ ") != std::string::npos)
        error();
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (isspace(input[i]))
            continue;
        else if (isdigit(input[i]))
        {
            operands++;
            this->stack.push_back(input[i] - '0');
        }
        else
        {
            if (this->stack.size() < 2)
                error();
            operators++;
            char op = input[i];
            n2 = this->stack.back();
            this->stack.pop_back();
            n1 = this->stack.back();
            this->stack.pop_back();
            if (!this->calculate(n1, n2, op))
                error();
        }
    }

    (operators + 1 == operands) ? this->printResult() : error();
}

double RPN::getStackTop()
{
    return this->stack.back();
}

void error()
{
    std::cout << RED << "Error" << RESET << std::endl;
    exit(1);
}
