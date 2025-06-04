/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:56:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 18:30:41 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
#include <cstdlib>
#include <ctime>

class Base{
    public:
        virtual ~Base(){}
    
        static Base * generate(void);
        static void identify(Base* p);
        static void identify(Base& p);
};
class A : public Base {};
class B : public Base {};
class C : public Base {};
#endif