/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:49:15 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/23 15:07:55 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void    testingArithmeticOperators( void )
{
    Fixed   a(15);
    Fixed   b(42.42f);
    
    std::cout << "***Testing Arithmetic operators ***" << std::endl;
    
    std::cout << "--> testing the \" + \" operator" << std::endl;
    std::cout << a + b << std::endl;
    
    std::cout << "--> testing the \" - \" operator" << std::endl;
    std::cout << a - b << std::endl;
    
    std::cout << "--> testing the \" * \" operator" << std::endl;
    std::cout << a * b << std::endl;
    
    std::cout << "--> testing the \" / \" operator" << std::endl;
    std::cout << a / b << std::endl;
}
void    testingComparisonOperators( void )
{
    Fixed   a(100);
    Fixed   c(200);
    Fixed   b(42.42f);
    
    std::cout << "***Testing: Comparison operators ***" << std::endl;
    
    std::cout << "--> testing the \" > \" operator" << std::endl;
    if (a > b && a < c)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (a != b) 
        std::cout << "yes a is not equal b" << std::endl;

}
void    testingIncrementDecrement ( void )
{
    Fixed a(105);
    Fixed b(42.42f);

    std::cout << "A -> before inrement: " << a << std::endl;
    a++;
    std::cout << "A -> after inrement: " << a << std::endl;
    
    std::cout << "B -> before inrement " << b << std::endl;
    b++;
    std::cout << "B -> after inrement: " << b << std::endl;
    std::cout << "Prefix tests: ++a = " << ++a << " | ++b = " << ++b << std::endl;
}

int main( void ) 
{
    testingArithmeticOperators();
    // testingComparisonOperators();
    // testingIncrementDecrement();
    {
        /*  Subject Main.cpp    */
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        // 1292 * 512 = 661504

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
    return 0;
}