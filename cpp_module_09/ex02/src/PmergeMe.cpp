/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:26:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/12/27 21:00:49 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const char **unsorted) : unsorted(unsorted)
{
    parsing();
    sort();
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this == &copy)
        return *this;
    this->unsorted = copy.unsorted;
    std::vector<int>::const_iterator itVec;
    std::deque<int>::const_iterator itDeq;
    if (!this->vec.empty())
        this->vec.clear();
    for (itVec = copy.vec.begin(); itVec != copy.vec.end(); ++itVec)
        this->vec.push_back(*itVec);
    if (!this->deq.empty())
        this->deq.clear();
    for (itDeq = copy.deq.begin(); itDeq != copy.deq.end(); ++itDeq)
        this->deq.push_back(*itDeq);
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parsing()
{
    long num;
    int i = 0;
    while (this->unsorted[++i])
    {
        int j = -1;
        while (this->unsorted[i][++j])
        {
            if (!isdigit(this->unsorted[i][j]))
                error();
        }
        num = atoll(this->unsorted[i]);
        if (num > INT_MAX)
            error();
        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::printUnsorted()
{
    int i = 0;
    while (this->unsorted[++i])
        std::cout << unsorted[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::sort()
{
    clock_t start, end;
    double durationVec, durationDeq;

    start = clock();
    sortVector(0, this->vec.size() - 1);
    end = clock();
    durationVec = (end - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    sortDeque(0, this->vec.size() - 1);
    end = clock();
    durationDeq = (end - start) * 1000.0 / CLOCKS_PER_SEC;

    std::cout << GREEN << "Before: " << RESET;
    printUnsorted();
    std::cout << GREEN << "After:  " << RESET;
    printVector();
    std::cout << "time to process a range of " << GREEN << this->vec.size() << RESET 
    << " elements with " << GREEN << "std::vector<int>: " << RESET << std::fixed << std::setprecision(5) << durationVec << " us" << std::endl;
    
    std::cout << "time to process a range of " << GREEN << this->deq.size() << RESET 
    << " elements with " << GREEN << "std::deque<int>:  " << RESET << std::fixed << std::setprecision(5) << durationDeq << " us" << std::endl;
}

void error()
{
    std::cout << RED << "Error" << RESET << std::endl;
    exit(1);
}

// -------------------------------- //
// ------- VECTOR FUNCTIONS ------- //
// -------------------------------- //

void PmergeMe::sortVector(int begin, int end)
{
    if ((end - begin) + 1 > k)
    {
        int half = (begin + end) / 2;
        sortVector(begin, half);
        sortVector(half + 1, end);
        mergeVector(begin, half, end);
    }
    else
        insertionVector();
}

void PmergeMe::mergeVector(int begin, int half, int end)
{
    std::vector<int> tmp = this->vec;

    int i = begin;
    int j = half + 1;
    int k = begin;

    while (i <= half && j <= end)
    {
        if (this->vec[i] < this->vec[j])
            tmp[k++] = this->vec[i++];
        else
            tmp[k++] = this->vec[j++];
    }

    while (i <= half)
        tmp[k++] = this->vec[i++];

    while (j <= end)
        tmp[k++] = this->vec[j++];

    for (size_t i = 0; i < this->vec.size(); i++)
        this->vec[i] = tmp[i];
}

void PmergeMe::insertionVector()
{
    int key, j;
    for (size_t i = 0; i < this->vec.size(); i++)
    {
        key = this->vec[i];
        j = i - 1;

        while (j >= 0 && this->vec[j] > key)
        {
            this->vec[j + 1] = this->vec[j];
            j--;
        }
        this->vec[j + 1] = key;
    }
}

void PmergeMe::printVector()
{
    std::vector<int>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// ------------------------------- //
// ------- DEQUE FUNCTIONS ------- //
// ------------------------------- //

void PmergeMe::sortDeque(int begin, int end)
{
    if ((end - begin) + 1 > k)
    {
        int half = (begin + end) / 2;
        sortDeque(begin, half);
        sortDeque(half + 1, end);
        mergeDeque(begin, half, end);
    }
    else
        insertionDeque();
}

void PmergeMe::mergeDeque(int begin, int half, int end)
{
    std::deque<int> tmp = this->deq;

    int i = begin;
    int j = half + 1;
    int k = begin;

    while (i <= half && j <= end)
    {
        if (this->deq[i] < this->deq[j])
            tmp[k++] = this->deq[i++];
        else
            tmp[k++] = this->deq[j++];
    }

    while (i <= half)
        tmp[k++] = this->deq[i++];

    while (j <= end)
        tmp[k++] = this->deq[j++];

    for (size_t i = 0; i < this->deq.size(); i++)
        this->deq[i] = tmp[i];
}

void PmergeMe::insertionDeque()
{
    int key, j;
    for (size_t i = 0; i < this->deq.size(); i++)
    {
        key = this->deq[i];
        j = i - 1;

        while (j >= 0 && this->deq[j] > key)
        {
            this->deq[j + 1] = this->deq[j];
            j--;
        }
        this->deq[j + 1] = key;
    }
}

void PmergeMe::printDeque()
{
    std::deque<int>::const_iterator it;
    for (it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
