//
// Created by jlrine2 on 3/23/20.
//

#ifndef CS372_CPS_CPS_HPP
#define CS372_CPS_CPS_HPP

#include <string>
using std::string;
// --- Shape to Postscript file ---

void shapeToPostScriptFile(const string & postScript, const string & filename);

// --- Shape ---

class Shape {
public:
    virtual double get_height() = 0;
    virtual double get_width() = 0;
    // -----
    virtual void set_width(double width);
    virtual void set_height(double height);
    // -----
    virtual string createPostScript() const = 0;

private:
    double _height;
    double _width;
};

// --- Polygon ---

class Polygon : public Shape {
public:
    Polygon(double sLen, unsigned int sides) : sideLength(sLen), sides(sides) {}

    double get_width() override;
    double get_height() override;

    string createPostScript() const override;

private:
    double sideLength;
    int sides;
};

// -- Square --

class Square : public Shape {
public:
    Square(double l) : sideLength(l) {}

    double get_width() override;
    double get_height() override;

    string createPostScript() const override;

private:
    double sideLength;
};

// -- Rectangle --

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double get_width() override;
    double get_height() override;

    string createPostScript() const override;

private:
    double height;
    double width;
};

// --- Triangle ---

class Triangle : public Shape {
public:
    Triangle(double l) : sideLength(l) {}

    double get_width() override;
    double get_height() override;

    string createPostScript() const override;

private:
    double sideLength;
};

// --- Circle ---

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    ~Circle() {}

    double get_width() override;
    double get_height() override;

    string createPostScript() const override;
private:
    double radius;

};

// --- Spacer --- INCOMPLETE

class Spacer : public Shape {
public:
    Spacer(double w, double h) : width(w), height(h) {}

    double get_width() override;
    double get_height() override;

    string createPostScript() const override;
private:
    double height;
    double width;
};

// --- Rotated Shape --- INCOMPLETE

class RotatedShape : public Shape {
public:
    Rotated(Shape shape, int rotationAngle) : _shape(shape), _rotation(rotationAngle) {}

    string createPostScript() const override;
private:
    Shape _shape;
    int _rotation;
};

// --- Scaled Shape --- INCOMPLETE

class ScaledShape : public Shape {
public:
    Scaled(Shape shape, double fx, double fy) : _shape(shape), _x(fx), _y(fy);

    string createPostScript() const override;
private:
    Shape _shape;
    double _x;
    double _y;
};

// --- Layered Shape --- INCOMPLETE

class LayeredShape : public Shape {
public:
    Layered(Shape ... shapes) : _shapes(shapes);

    string createPostScript() const override;
private:
    Shape _shapes;
};

// --- Vertical Shape --- INCOMPLETE

class VerticalShape : public Shape {
public:
    Vertical(Shape ... shapes) : _shapes(shapes);

    string createPostScript() const override;
private:
    Shape _shapes;
};

// --- Horizontal Shape --- INCOMPLETE

class HorizontalShape : public Shape {
public:
    Horizontal(Shape ... shapes) : _shapes(shapes);

    string createPostScript() const override;
private:
    Shape _shapes;
};

#endif //CS372_CPS_CPS_HPP
