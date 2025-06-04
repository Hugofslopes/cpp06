/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:09:55 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 18:30:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base * Base::generate(void){
    std::srand(std::time(NULL)); 
    int n = std::rand() % 3 + 1; 
    Base* new_;
    
    if (n == 1)
        new_ = new A();
    else if (n == 2)
        new_ = new B();
    else
        new_ = new C();
    return (new_);
}

void Base::identify(Base* p){

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void Base::identify(Base& p){
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(&p))
    std::cout << "C" << std::endl;
}
