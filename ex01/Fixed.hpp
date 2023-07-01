/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:59:50 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/01 14:27:37 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    float toFloat() const;
    int toInt() const;
    int getRawBits() const;
    void setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif