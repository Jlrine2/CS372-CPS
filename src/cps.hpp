//
// Created by jlrine2 on 3/23/20.
//

#ifndef CS372_CPS_CPS_HPP
#define CS372_CPS_CPS_HPP
#include <iostream>

class Shape {
    public:
    ~Shape();
    Shape();
    virtual std::iostream draw()=0;  
};
class Polygon: Shape{

};
class Square: Shape{

};
class Rectangle: Shape{

};
class Triangle: Shape{

};
class Circle: Shape{

};
class Spacer: Shape{

};
#endif //CS372_CPS_CPS_HPP
