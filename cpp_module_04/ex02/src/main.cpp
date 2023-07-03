/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:35:45 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/03 15:12:33 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main()
{
    Animal a;
    
    std::cout << MAGENTA << "\n\n############## PDF TEST #############\n\n" << RESETCOLOR;
    
    const Animal* j = new Dog(); 
    const Animal* i = new Cat();
    std::cout << "\n\n";
    delete j;//should not create a leak 
    delete i;

    std::cout << MAGENTA << "\n\n############## ANIMAL TEST #############\n\n" << RESETCOLOR;

    Animal* animal[100]; 
    for (int i = 0; i < 50; i++)
        animal[i] = new Dog();   
    for (int i = 50; i < 100; i++)
        animal[i] = new Cat();   
    for (int i = 0; i < 100; i++) {
            std::cout << i << ": "; 
            animal[i]->makeSound();
    }
    for (int i = 0; i < 100; i++)
        delete animal[i];
    
    std::cout << MAGENTA << "\n\n############## BRAIN TEST #############\n\n" << RESETCOLOR;
    
    Brain* brain = new Brain();
    for (int i = 25; i < 55; i++)
        brain->setIdeas(i, "Got an idea...");
    for (int i = 0; i < 100; i++)
        std::cout << YELLOW << "Idea " << i << ": " << brain->getIdea(i) << RESETCOLOR << std::endl;
    delete brain;

    std::cout << MAGENTA << "\n\n############## DOG/CAT BRAIN TEST #############\n\n" << RESETCOLOR;
    
    Dog dog;
    Cat cat;

    for (int i = 10; i < 20; i++) 
        dog.setIdeas(i, "Want bark...");
    for (int i = 0; i < 20; i++)
        std::cout << GREEN << "Idea " << i << ": " YELLOW << dog.getIdea(i) << RESETCOLOR << std::endl;
    
    for (int i = 10; i < 20; i++) 
        cat.setIdeas(i, "Want play...");
    for (int i = 0; i < 20; i++)
        std::cout << RED << "Idea " << i << ": " BLUE << cat.getIdea(i) << RESETCOLOR << std::endl;
        
    

    
        
    return 0;
}