/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:34:34 by tde-melo          #+#    #+#             */
/*   Updated: 2023/10/22 18:10:37 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

int main()
{
    std::cout << "---------- PDF main --------\n\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n------------- Constructors / Operators tests ------------\n";
    MutantStack<int> a;
    a.push(3);
    a.push(5);
    a.push(6);

    MutantStack<int>::iterator myIt = a.begin();
    MutantStack<int>::iterator myIt2(myIt);
    MutantStack<int>::iterator myIt3;
    myIt3 = myIt2;
    MutantStack<int>::iterator myIte = a.end();

    if (myIt2 == myIt && myIt3 == myIt)
        std::cout << "\n== operator is working\n\n";

    std::cout << "Iterating using it\n";
    for (; myIt != myIte; myIt++)
        std::cout << *myIt << " ";
    std::cout << std::endl;
    
    std::cout << "Iterating using it2\n";
    for (; myIt2 != myIte; ++myIt2)
        std::cout << *myIt2 << " ";
    std::cout << std::endl;
    
    std::cout << "Iterating using it3\n";
    for (; myIt3 != myIte; myIt3++)
        std::cout << *myIt3 << " ";
    std::cout << std::endl;


    return 0;
}