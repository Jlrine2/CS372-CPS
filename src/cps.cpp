//
// Created by jlrine2 on 3/23/20.
//

#include "cps.hpp"
#include <cmath>


double Circle::get_height() {
    return 2.0 * radius;
}

double Circle::get_width() {
    return 2.0 * radius;
}

void Circle::createPostScript(std::ostream &os) const {

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
    double pi = 3.14159265358979323846;
    if (sides % 4 == 0) {
        return (sideLength * std::cos(pi / sides)) / (std::sin(pi / sides));
    }
    if (sides % 2 == 0) {
        return sideLength / std::sin(pi / sides);
    }
    return sideLength * std::sin(pi * (sides - 1) / (2 * sides)) / (std::sin(pi / sides));
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
    double pi = 3.14159265358979323846;
    if (sides % 2 == 0) {
        return (sideLength * std::cos(pi / sides)) / (std::sin(pi / sides));
    }
    return sideLength * (1 + std::cos(pi / sides)) / (2 * std::sin(pi / sides));
}

void Polygon::createPostScript(std::ostream &os) const {

}

double Square::get_width() {
    return sideLength;
}

double Square::get_height() {
    return sideLength;
}

void Square::createPostScript(std::ostream &os) const {

}

double Triangle::get_height() {
    return sqrt(std::pow(sideLength, 2) - std::pow(sideLength / 2, 2));
}

double Triangle::get_width() {
    return sideLength;
}

void Triangle::createPostScript(std::ostream &os) const {

}

double Rectangle::get_width() {
    return width;
}

double Rectangle::get_height() {
    return height;
}

void Rectangle::createPostScript(std::ostream &os) const {

}

double Spacer::get_width() {
    return width;
}

double Spacer::get_height() {
    return height;
}

void Spacer::createPostScript(std::ostream &os) const {

}


double Rotated::get_width() {
    return 0;
}

double Rotated::get_height() {
    return 0;
}

void Rotated::createPostScript(std::ostream &os) const {

}

Scaled::Scaled(std::shared_ptr<Shape> shape, double fx, double fy) {

}

double Scaled::get_width() {
    return 0;
}

double Scaled::get_height() {
    return 0;
}

void Scaled::createPostScript(std::ostream &os) const {

}

double Layered::get_width() {
    return 0;
}

double Layered::get_height() {
    return 0;
}

void Layered::createPostScript(std::ostream &os) const {

}

Layered::Layered(std::initializer_list<std::shared_ptr<Shape>> shapes) {

}

Vertical::Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes) {

}

double Vertical::get_width() {
    return 0;
}

double Vertical::get_height() {
    return 0;
}

void Vertical::createPostScript(std::ostream &os) const {

}

Horizontal::Horizontal(std::initializer_list<std::shared_ptr<Shape>> shapes) {

}

double Horizontal::get_width() {
    return 0;
}

double Horizontal::get_height() {
    return 0;
}

void Horizontal::createPostScript(std::ostream &os) const {

}
