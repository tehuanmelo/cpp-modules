/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:04:39 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/09 23:16:43 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 10;
    Zombie *zombie = zombieHorde(N, "Walker");
    for (int i = 0; i < N; i++) {
        zombie[i].announce();
    }
    delete zombie;
}