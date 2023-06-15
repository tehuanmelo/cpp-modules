/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:04:39 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/08 23:16:47 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
  std::string strINIT = "HI THIS IS BRAIN";
  std::string *stringPTR = &strINIT;
  std::string &stringREF = strINIT;

  std::cout << "The memory address of the string: " << &strINIT << std::endl;
  std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
  std::cout << std::endl;
  std::cout << "The value of the string variable: " << strINIT << std::endl;
  std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}