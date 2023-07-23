/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:49:20 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/22 13:00:24 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed ( void );
    Fixed ( Fixed const& other );

    ~Fixed ( void );

    Fixed& operator=( Fixed const& other );

    int getRawBits( void ) const;
    void setRawBits( int const raw );

private:
    static  const int   _fractional_bits;
    int                 _fixedPointValue;
};

#endif