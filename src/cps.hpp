//
// Created by jlrine2 on 3/23/20.
//

#ifndef CS372_CPS_CPS_HPP
#define CS372_CPS_CPS_HPP
#include <iostream>

class Shape {
public:
    virtual double get_height()=0;
    virtual double get_width()=0;
};
class Polygon: public Shape{


};
class Square: public Shape{

};
class Rectangle: public Shape{

};
class Triangle: public Shape{

};
class Circle: public Shape{
public:
    Circle(double r): radius(r){}
    ~Circle() {}
    double get_width() override;
    double get_height() override;
private:
    double radius;

};
class Spacer: public Shape{

};
#endif //CS372_CPS_CPS_HPP
