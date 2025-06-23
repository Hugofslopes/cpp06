/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:27:56 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 11:31:26 by hfilipe-         ###   ########.fr       */
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

ScalarConverter::~ScalarConverter(){}

bool isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" ||
    str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff");
}

int string_to_int(const std::string& str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    return (result);
}

void print_int(bool pseudo, double value, std::string literal) {
	std::cout << "int: ";
    if (pseudo || value >  std::numeric_limits<int>::max() || \
    value  < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
	else
    {
        int n = string_to_int(literal);
        std::cout << n << std::endl;
    }
}

void print_float(double value) {
	std::cout << "float: ";
    return static_cast<void>(std::cout << static_cast<float>(value)
        << "f" << std::endl);
}

bool isPrint(int value)
{
    return (value >= 32 && value <= 126);
}

bool isAscII(int value)
{
    return (value >= 0 && value <= 127);
}

void print_char(bool pseudo, double value) {
    std::cout << "char: ";
    if (pseudo)
        return (static_cast<void>((std::cout << "impossible" << std::endl)));
    if (!(isAscII(static_cast<int>(value))))
        std::cout << "Out of ASCII table range" << std::endl;
    else if (isPrint(static_cast<int>(value)))
        std::cout << static_cast<char>(value)  << std::endl;
    else 
        std::cout << "Non displayable" << std::endl;
}

void print_double(double value) {
    std::cout << "double: ";
    std::cout << value << std::endl;
}

int getValueCheckParameters(const std::string literal, double *value, bool *pseudo)
{
    if (isPseudoLiteral(literal))
    {    
        *pseudo = true;
        if (literal == "nan" || literal == "nanf")
            *value = std::numeric_limits<double>::quiet_NaN();
        if  (literal == "+inf" || literal == "+inff") 
            *value = std::numeric_limits<double>::infinity();
        if (literal == "-inf" || literal == "-inff")
            *value = -std::numeric_limits<double>::infinity();
    }
    else {
        char* end;
        errno = 0;
        
        *value = std::strtod(literal.c_str(), &end);
        if (errno || (*end != '\0' && *end != 'f') || (end[0] != '\0' && end[1])) {
            std::cerr << "Invalid literal: " << literal << std::endl;
            return (1);
        }
    }
    return (0);
}

void ScalarConverter::convert(const std::string literal) {
    double	value = 0.0;
    bool 	pseudo = false;

    if (getValueCheckParameters(literal, &value, &pseudo)){
        return ;}
	print_char(pseudo, value);
	print_int(pseudo, value, literal);
	print_float(value);
	print_double(value);
}
