/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:21 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/23 12:18:20 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) 
{
    // std::cout << "Default Point Constructor" << std::endl;
}

Point::Point( const float n1, const float n2 ) : _x(n1), _y(n2) 
{
    // std::cout << "Parametrized Point Constructor" << std::endl;
}

Point::Point( Point const& other) : _x(other.getX()), _y(other.getY())
{
    // std::cout << "Copy Constructor Point" << std::endl;
}

Point::~Point( void ) 
{
    // std::cout << "Point Destructor " << std::endl;
}

Point& Point::operator=( Point const& other )
{
    // std::cout << "Point assignement operator" << std::endl;
    if(this != &other)
    {
        (Fixed)this->_x = other.getX();
        (Fixed)this->_y = other.getY();
    }
    return (*this);
}

Fixed   Point::getX( void ) const
{
    // std::cout << "Point getX member function" << std::endl;
    return (this->_x);
}

Fixed   Point::getY( void ) const
{
    // std::cout << "Point getY member function" << std::endl;
    return (this->_y);
}