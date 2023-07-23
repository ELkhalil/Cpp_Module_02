/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:38 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/23 13:11:06 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static Fixed    ft_abs(Fixed num) 
{
    if( num < 0)
        return (num * -1);
    return (num);
}

static Fixed    area_triangle(Point a, Point b, Point c)
{
    Fixed   x1 =  a.getX() * (b.getY() - c.getY());
    Fixed   x2 =  b.getX() * (c.getY() - a.getY());
    Fixed   x3 =  c.getX() * (a.getY() - b.getY());

    return (ft_abs((x1 + x2 + x3) / Fixed(2)));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area_triangle(a, b, c);

    Fixed areaAPC = area_triangle(a, point, c);
    Fixed areaPCB = area_triangle(point, c, b);
    Fixed areaAPB = area_triangle(a, point, b);

    return (areaABC == areaAPC + areaPCB + areaAPB);
}
