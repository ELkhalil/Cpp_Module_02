/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:59:56 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/01 15:05:33 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _value( n << fractionalBits ) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _value( std::roundf( n * ( 1 << fractionalBits ) ) ) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs ) {
    // std::cout << "Copy constructor called" << std::endl;
    // this->setRawBits(rhs.getRawBits());
    *this = rhs;
}

Fixed& Fixed::operator=( const Fixed &rhs ) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &rhs )
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->_value;
}

void    Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << fractionalBits );
}

int     Fixed::toInt( void ) const {
    return this->_value >> fractionalBits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

//----------------- Comparison operators -----------------//

bool    Fixed::operator>( const Fixed &rhs ) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<( const Fixed &rhs ) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=( const Fixed &rhs ) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=( const Fixed &rhs ) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==( const Fixed &rhs ) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=( const Fixed &rhs ) const {
    return this->getRawBits() != rhs.getRawBits();
}

//------------------ Arithmetic operators ------------------//

Fixed   Fixed::operator+( const Fixed &rhs ) const {
    return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &rhs ) const {
    return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &rhs ) const {
    return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &rhs ) const {
    return Fixed( this->toFloat() / rhs.toFloat() );
}

//------------------ Increment/Decrement operators ------------------//

Fixed&   Fixed::operator++( void ) {
    ++this->_value;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._value = this->_value++;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --this->_value;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._value = this->_value--;
    return tmp;
}

//----------------------- Max and Min ----------------------//

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}