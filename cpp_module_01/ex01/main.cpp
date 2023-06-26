/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:04:39 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/26 12:50:23 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 10;
    Zombie *zombie = zombieHorde(N, "Walker");
    for (int i = 0; i < N; i++) {
        zombie[i].announce();
    }
    delete [] zombie;
}