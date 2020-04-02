//
// Created by jlrine2 on 3/23/20.
//

#ifndef CS372_CPS_CPS_HPP
#define CS372_CPS_CPS_HPP

class Shape {
public:
    virtual double get_height() = 0;

    virtual double get_width() = 0;
};

class Polygon : public Shape {
public:
    Polygon(double sLen, unsigned int sides) : sideLength(sLen), sides(sides) {}

    double get_width() override;

    double get_height() override;

private:
    double sideLength;
    int sides;
};

class Square : public Shape {
public:
    Square(double l) : sideLength(l) {}

    double get_width() override;

    double get_height() override;

private:
    double sideLength;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double get_width() override;

    double get_height() override;

private:
    double height;
    double width;
};

class Triangle : public Shape {
public:
    Triangle(double l) : sideLength(l) {}

    double get_width() override;

    double get_height() override;

private:
    double sideLength;
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    ~Circle() {}

    double get_width() override;

    double get_height() override;

private:
    double radius;

};

class Spacer : public Shape {
public:
    Spacer(double w, double h) : width(w), height(h) {}

    double get_width() override;

    double get_height() override;

private:
    double height;
    double width;
};

class RotationAngle {
public:
    explicit RotationAngle(int a);
    int get_angle();
private:
    int angle;
};



class Rotated : public Shape {
public:
    Rotated(Shape s, RotationAngle angle);

    double get_width() override;

    double get_height() override;
private:
    Shape* shape;
    RotationAngle angle;
};

#endif //CS372_CPS_CPS_HPP
