/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:12 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/23 12:47:57 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
public:
    Point   ( void );
    Point   ( const float n1, const float n2 );
    Point   ( Point const& other);
    ~Point  ( void );
    
    Point&   operator=( Point const& other );
    Fixed   getX( void ) const;
    Fixed   getY( void ) const;
private:  
    const   Fixed   _x;
    const   Fixed   _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif