//
// Created by jlrine2 on 3/23/20.
//

#include "cps.hpp"

double Circle::get_height() {
    return 2.0 * radius;
}

double Circle::get_width() {
    return 2.0 * radius;
}


/*
 * Width of a regular polygon is defined as:
 *   (l*sin(pi(n-1)/(2n)) / (sin(pi/n))
 *     if n is odd
 *   (l*cos(pi/n)) / (sin(pi/n))
 *     if n is divisible by 4
 *   l/sin(pi/n)
 *     if n is divisible by 2 but not 4
 * Where n is the number of sides and l is the length of each side
 */
double Polygon::get_width() {
    if (sides % 4 == 0) {

    }
    if (sides % 2 == 0) {

    }

}

/*
 * Width of a regular polygon is defined as:
 *   l*(1+cos(pi/n)) / (2*sin(pi/n))
 *     if n is odd
 *   (l*cos(pi/n)) / (sin(pi/n))
 *     if n is divisible by 2
 * Where n is the number of sides and l is the length of each side
 */
double Polygon::get_height() {
    return sideLength;
}
