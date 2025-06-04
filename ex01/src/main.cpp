/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:29:56 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 17:50:14 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

#include <sstream>

int main()
{
    {
        Data a;
        a.file1 = "yelloooow";
        a.file = "H R YOU?";

        uintptr_t b = Serializer::serialize(&a);
        std::cout << "Serialized address (uintptr_t): " << b << std::endl;
        std::cout << "Address of a (&a): " << &a << std::endl;
        std::cout << "Address in hex: 0x" << std::hex << b << std::dec << std::endl;
    }
    std::cout <<std:: endl;
    {
        Data a;
        a.file = "Oposite now";

        uintptr_t raw = Serializer::serialize(&a);
        Data* ptr = Serializer::deserialize(raw);

        std::cout << "Original pointer: " << &a << std::endl;
        std::cout << "Deserialized pointer: " << ptr << std::endl;

        if (ptr == &a) {
            std::cout << "Pointer test passed!" << std::endl;
        } else {
            std::cout << "Pointer test FAILED!" << std::endl;
        }

        if (ptr->file == "Oposite now") {
            std::cout << "Value test passed!" << std::endl;
        } else {
            std::cout << "Value test FAILED!" << std::endl;
        }
    }
}
