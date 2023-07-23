/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:49:25 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/22 13:01:23 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// static Members :
const int Fixed::_fractional_bits = 8;

//Constructors : 
Fixed::Fixed ( void ) : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( Fixed const& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Destructor :
Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

// Assignment Operator :
Fixed& Fixed::operator=( Fixed const& other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return (*this);
}

// Member Functions :
int Fixed::getRawBits (void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}