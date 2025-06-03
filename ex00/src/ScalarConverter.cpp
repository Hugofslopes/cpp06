/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:27:56 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 18:56:57 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
	if (this != &other)
		*this = other;
	return (*this);
}


static bool isCharLiteral(const std::string& str) {
    return str.length() == 3 && str.front() == '\'' && str.back() == '\'';
}

static bool isPseudoLiteral(const std::string& str) {
    return str == "nan" || str == "nanf" ||
    str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff";
}


bool isPseudoLiteral(const std::string& str) {
    return str == "nan" || str == "nanf" ||
    str == "+inf" || str == "+inff" ||
    str == "-inf" || str == "-inff";
}

bool isNan(const std::string& str) {
    return str == "nan" || str == "nanf";
}

bool isInf(const std::string& str) {
    return str == "+inf" || str == "-inf" ||
    str == "+inff" || str == "-inff";
}

bool isPositiveInf(const std::string& str) {
    return str == "+inf" || str == "+inff";
}

bool isNegativeInf(const std::string& str) {
    return str == "-inf" || str == "-inff";
}

static void print_int(bool pseudo, double value) {
	std::cout << "int: ";
    if (pseudo || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() 
	|| std::isnan(value)) {
        std::cout << "impossible" << std::endl;
    } 
	else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

static void print_float(bool pseudo, double value) {
	std::cout << "float: ";
    float f = static_cast<float>(value);
    if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision((f == static_cast<int>(f)) ? 1 : 6) 
		<< f << "f" << std::endl;
}

static void print_char(bool pseudo, double value) {
    std::cout << "char: ";
    if (pseudo || value < 0 || value > 127 || std::isnan(value)) {
        std::cout << "impossible" << std::endl;
    } else if (std::isprint(static_cast<int>(value))) {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
}

static void print_double(bool pseudo, double value) {
std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision((value == static_cast<int>(value)) ? 1 : 6) 
		<< value << std::endl;
}

void ScalarConverter::convert(const std::string literal) {
    double	value = 0.0;
    bool 	isFloat = false;
    bool 	pseudo = false;


    if (isCharLiteral(literal)) {
        char c = literal[1];
        value = static_cast<double>(c);
    }
    else if (isPseudoLiteral(literal)) {
        pseudo = true;
        if (literal == "nan" || literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
        if (literal.back() == 'f') isFloat = true;
    }
    else {
        char* end;
        errno = 0;
        value = std::strtod(literal.c_str(), &end);

        if (errno || (*end != '\0' && *end != 'f')) {
            std::cerr << "Invalid literal: " << literal << std::endl;
            return;
        }

        if (*end == 'f') isFloat = true;
    }

	print_char(pseudo, value);

	print_int(pseudo, value);

	print_float(pseudo, value);

	print_double(pseudo, value);
}

