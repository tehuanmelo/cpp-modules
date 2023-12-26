/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:09:07 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/12/26 22:33:43 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int ac, const char **av)
{
    if (ac >= 3)
    {
        PmergeMe mergeMe(av);
    }
    else   
        error();
    
    return 0;
}