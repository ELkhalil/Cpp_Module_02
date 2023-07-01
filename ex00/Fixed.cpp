/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:59:56 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/30 19:32:50 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        value = other.value;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}