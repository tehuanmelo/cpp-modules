/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:10:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/13 18:58:02 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base* generate(void) {
    int sd = time(NULL);
    std::srand(sd);
    int num = rand() % 3;

    if (num == 0)
        return new A;
    else if (num == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "The object has type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The object has type B" << std::endl;
    else
        std::cout << "The object has type C" << std::endl;
}

void identify(Base& p) {
    
    try
    {
        A* a = &dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Object has type A" << std::endl;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    
    try
    {
        B* b = &dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Object has type B" << std::endl;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    
    try
    {
        C* c = &dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Object has type C" << std::endl;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    
}


int main() {
    Base* obj;
    Base* obj1;
    
    obj = generate();
    obj1 = generate();
    
    std::cout << std::endl;
    
    identify(obj);
    identify(*obj1);
    
    std::cout << std::endl;

    delete obj;
    delete obj1;
    
    return 0;
}