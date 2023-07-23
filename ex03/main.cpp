/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:49:15 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/23 13:02:51 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    // inside Triangle test
    {
        Point a(0, 0);
        Point b(4, 0);
        Point c(2, 4);
        Point point(2, 2);

        if (bsp(a, b, c, point))
            std::cout << "The point is inside the triangle" << std::endl;
        else
            std::cout << "The point is outside the triangle" << std::endl;
    }
    // outside Triangle test
    {
        Point a(0, 0);
        Point b(4, 0);
        Point c(2, 4);
        Point point(5, 5);
        if (bsp(a, b, c, point))
            std::cout << "The point is inside the triangle" << std::endl;
        else
            std::cout << "The point is outside the triangle" << std::endl;
    }
    return 0;
}