/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:20:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/12/26 23:12:57 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>

class PmergeMe
{
private:
    const char **unsorted;
    static const int k = 5;
    std::vector<int> vec;
    std::deque<int> deq;

public:
    PmergeMe();
    PmergeMe(const char **unsorted);
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe();

    void parsing();
    void printUnsorted();
    void sort();

    void sortVector(int begin, int end);
    void mergeVector(int begin, int half, int end);
    void insertionVector();
    void printVector();

    void sortDeque(int begin, int end);
    void mergeDeque(int begin, int half, int end);
    void insertionDeque();
    void printDeque();
};

void error();
