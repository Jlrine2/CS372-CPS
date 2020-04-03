//
// Created by jlrine2 on 3/23/20.
//

#include "cps.hpp"
#include <cmath>


std::string gotoCenter() {
    return " 306 396 moveto ";
}

double Circle::get_height() const {
    return 2.0 * radius;
}

double Circle::get_width() const {
    return 2.0 * radius;
}

void Circle::createPostScript(std::ostream &os) const {
    int originX = 306;
    int originY = 396;
    os << gotoCenter() << "gsave newpath " << originX << " " << originY << " " << radius << " 0 360 arc closepath stroke grestore ";
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
double Polygon::get_width() const {
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
double Polygon::get_height() const {
    double pi = 3.14159265358979323846;
    if (sides % 2 == 0) {
        return (sideLength * std::cos(pi / sides)) / (std::sin(pi / sides));
    }
    return sideLength * (1 + std::cos(pi / sides)) / (2 * std::sin(pi / sides));
}

void Polygon::createPostScript(std::ostream &os) const {
    int interiorAngle = 180 - (((sides - 2) * 180) / sides);
    int originX = 306;
    int originY = 396;
    os << gotoCenter() << "1 1 " << sides << " { "
    << sideLength << " 0 rlineto " << interiorAngle << " rotate } for stroke grestore ";
}

double Square::get_width() const {
    return sideLength;
}

double Square::get_height() const {
    return sideLength;
}

void Square::createPostScript(std::ostream &os) const {
    Polygon p(sideLength, 4);
    p.createPostScript(os);
}

double Triangle::get_height() const {
    return sqrt(std::pow(sideLength, 2) - std::pow(sideLength / 2, 2));
}

double Triangle::get_width() const {
    return sideLength;
}

void Triangle::createPostScript(std::ostream &os) const {
    Polygon p(sideLength, 3);
    p.createPostScript(os);
}

double Rectangle::get_width() const {
    return width;
}

double Rectangle::get_height() const {
    return height;
}

void Rectangle::createPostScript(std::ostream &os) const {
    int originX = 306;
    int originY = 396;
    os << gotoCenter() << "0 " << get_height() << " rlineto " << get_width()
       << " 0 rlineto 0 -" << get_height() << " rlineto -" << get_width() << " 0 rlineto"
       << " stroke ";
}

double Spacer::get_width() const {
    return width;
}

double Spacer::get_height() const {
    return height;
}

void Spacer::createPostScript(std::ostream &os) const {}


double Rotated::get_width() const {
    return 0;
}

double Rotated::get_height() const {
    return 0;
}

void Rotated::createPostScript(std::ostream &os) const {
    os << gotoCenter() << "gsave " << rotation << " rotate ";
    shape->createPostScript(os);
    os << "grestore ";
}

Scaled::Scaled(std::shared_ptr<Shape> shape, double fx, double fy): shape(shape) {
    x = shape -> get_width() * 2;
    y = shape -> get_height() * 2;
}

double Scaled::get_width() const {
    return shape ->get_width()*2;
}

double Scaled::get_height() const {
    return shape ->get_height()*2;
}

void Scaled::createPostScript(std::ostream &os) const {
    os << "gsave " << x << " " << y << " scale ";
    shape->createPostScript(os);
    os << "grestore ";
}

double Layered::get_width() const {
    return 0;
}

double Layered::get_height() const {
    return 0;
}

void Layered::createPostScript(std::ostream &os) const {
    //Need Help
}

Layered::Layered(std::initializer_list<std::shared_ptr<Shape>> shapes) {

}

Vertical::Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes) {
    _shapes = shapes;
}

double Vertical::get_width() const {
    double largest = 0.0;
    for(auto s : _shapes){
        if(largest < s->get_width())
            largest = s->get_width();

    }
    return largest;
}

double Vertical::get_height() const {
    double height = 0.0;
    for(auto s : _shapes){
        height+=s->get_height();
    }
    return height;
}

void Vertical::createPostScript(std::ostream &os) const {
    for (int i = 1; i <= _shapes.size(); ++i){
           os << "gsave 0 " << _shapes[i-1]->get_height() * i << " translate ";
           _shapes[i-1]->createPostScript(os);
           os << " grestore ";
    }
}

Horizontal::Horizontal(std::initializer_list<std::shared_ptr<Shape>> shapes) {
    _shapes = shapes;
}

double Horizontal::get_width() const {
    double width = 0.0;
    for(auto s : _shapes){
        width+=s->get_width();
    }
    return width;
}

double Horizontal::get_height() const {
    double largest = 0.0;
    for(auto s : _shapes){
        if(largest < s->get_height())
            largest = s->get_height();

    }
    return largest;
}

void Horizontal::createPostScript(std::ostream &os) const {
    for (int i = 1; i <= _shapes.size(); ++i){
        os << "gsave " << _shapes[i-1]->get_width() * i << " 0 translate ";
        _shapes[i-1]->createPostScript(os);
        os << " grestore ";
    }
}
