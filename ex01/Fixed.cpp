/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:59:56 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/01 14:43:34 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(std::roundf(value * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
       this->_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->getRawBits()) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return this->_value >> fractionalBits;
}

int Fixed::getRawBits() const {
    return this->_value;
}

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
