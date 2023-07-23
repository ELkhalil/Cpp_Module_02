/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:49:20 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/22 13:00:19 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed   ( void );
    Fixed   ( const int value );
    Fixed   ( const float value );
    Fixed   ( Fixed const& other );

    ~Fixed  ( void );

    Fixed&  operator=( Fixed const& other );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    int     toInt( void ) const;
    float   toFloat( void ) const;
private:
    static  const int   _fractional_bits;
    int                 _fixedPointValue;
};

std::ostream& operator <<(std::ostream& o, Fixed const& rhs);

#endif