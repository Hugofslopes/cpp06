/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:25:35 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/23 13:38:52 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include <unistd.h>

int main(){
    Base* ptr = Base::generate();

    std::cout << "Identify by pointer: ";
    Base::identify(ptr);
    delete ptr;
    usleep(270000);
    std::cout << std::endl;
    ptr = Base::generate();
    std::cout << "Identify by reference: ";
    Base::identify(*ptr);
    std::cout << "Identify by pointer: ";
    Base::identify(ptr);
    delete ptr;
    return 0;
}
