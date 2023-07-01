/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:59:50 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/30 19:27:59 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int value;
    static const int fractional_bits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int raw);
};

#endif