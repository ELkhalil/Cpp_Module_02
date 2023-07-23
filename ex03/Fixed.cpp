/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:49:25 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/23 15:01:02 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// static Members :
const int Fixed::_fractional_bits = 8;

// Constructors :
Fixed::Fixed(void) : _fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = (value << _fractional_bits);
}
Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << _fractional_bits));
}
Fixed::Fixed(Fixed const &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Destructor:
Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

// Assignment Operator :
Fixed &Fixed::operator=(Fixed const &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return (*this);
}

/*  operators overloading   */
// Arithmetic operators
Fixed Fixed::operator+(Fixed const &other)
{
    Fixed   tmp;

    tmp.setRawBits(this->getRawBits() + other.getRawBits());
    return (tmp);
}
Fixed Fixed::operator-(Fixed const &other)
{
    Fixed   tmp;

    tmp.setRawBits(this->getRawBits() - other.getRawBits());
    return (tmp);
}
Fixed Fixed::operator*(Fixed const &other)
{
    Fixed       tmp;
    int         tmp_value;

    tmp_value = this->getRawBits() * other.getRawBits();
    tmp.setRawBits(tmp_value >> _fractional_bits);
    return (tmp);
}
Fixed Fixed::operator/(Fixed const &other)
{
    if (other.getRawBits() == 0)
        return (Fixed(0));
    Fixed   tmp;
    int     tmp_value;

    tmp_value = this->getRawBits() / other.getRawBits();
    tmp.setRawBits(tmp_value << _fractional_bits);
    return (tmp);
}

// Comparison operators
bool Fixed::operator>(Fixed const other)
{
    return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator>=(Fixed const other)
{
    return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<(Fixed const other)
{
    return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator<=(Fixed const other)
{
    return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(Fixed const other)
{
    return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(Fixed const other)
{
    return (this->getRawBits() != other.getRawBits());
}

// Increment/Decrement operators
Fixed &Fixed::operator++( void )
{
    ++this->_fixedPointValue;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    tmp._fixedPointValue = this->_fixedPointValue++;
    return (tmp);
}
Fixed &Fixed::operator--( void )
{
    --this->_fixedPointValue;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    tmp._fixedPointValue = this->_fixedPointValue--;
    return (tmp);
}

// Member Functions :
int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}
int Fixed::toInt(void) const
{
    // std::cout << "toInt member function called" << std::endl;
    return (this->_fixedPointValue >> _fractional_bits);
}
float Fixed::toFloat(void) const
{
    // std::cout << "toFloat member function called" << std::endl;
    return (float(this->getRawBits()) / (1 << _fractional_bits));
}

const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}
const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

// Insertion Overload
std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}