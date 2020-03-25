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
class Polygon: public Shape{

};
class Square: public Shape{

};
class Rectangle: public Shape{

};
class Triangle: public Shape{

};
class Circle: public Shape{

};
class Spacer: public Shape{

};
#endif //CS372_CPS_CPS_HPP
