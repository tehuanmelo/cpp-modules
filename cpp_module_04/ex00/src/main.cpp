/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:35:45 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/01 16:31:26 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
    std::cout << MAGENTA << "\n\n####### PDF TEST ######\n\n" << RESETCOLOR;

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound! 
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\n\n";

     delete i;
     delete j;
     delete meta;

    std::cout << MAGENTA << "\n\n####### HEAP TEST ######\n\n" << RESETCOLOR;

    Animal *animal1 = new Dog();
    Animal *animal2 = new Cat();

    std::cout << animal1->getType() << std::endl;
    animal1->makeSound();

    std::cout << animal2->getType() << std::endl;
    animal2->makeSound();

    std::cout << "\n\n";

    delete animal2;
    delete animal1;
    
    std::cout << MAGENTA << "\n\n####### STACK TEST ######\n\n" << RESETCOLOR;

    Animal animal;
    Dog dog;
    Cat cat;

    std::cout << animal.getType() << std::endl;
    animal.makeSound();

    std::cout << dog.getType() << std::endl;
    dog.makeSound();

    std::cout << cat.getType() << std::endl;
    cat.makeSound();

     std::cout << "\n\n";

    return 0;
}