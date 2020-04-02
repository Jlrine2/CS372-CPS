//
// Created by jlrine2 on 3/23/20.
//

#ifndef CS372_CPS_CPS_HPP
#define CS372_CPS_CPS_HPP

#include <ostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual double get_height() = 0;
    virtual double get_width() = 0;
    virtual void createPostScript(std::ostream &os) const = 0;

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

    void createPostScript(std::ostream &os) const override;

private:
    double sideLength;
    int sides;
};


class Square : public Shape {
public:
    explicit Square(double l) : sideLength(l) {}

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;

private:
    double sideLength;
};

// -- Rectangle --

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;

private:
    double height;
    double width;
};

// --- Triangle ---

class Triangle : public Shape {
public:
    explicit Triangle(double l) : sideLength(l) {}

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;

private:
    double sideLength;
};

// --- Circle ---

class Circle : public Shape {
public:
    explicit Circle(double r) : radius(r) {}

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;
private:
    double radius;

};


class Spacer : public Shape {
public:
    Spacer(double w, double h) : width(w), height(h) {}

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;
private:
    double height;
    double width;
};

// --- Rotated Shape ---

class Rotated : public Shape {
public:
    Rotated(std::shared_ptr<Shape> shape, int rotationAngle) : shape(shape), rotation(rotationAngle) {}

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;
private:
    std::shared_ptr<Shape> shape;
    int rotation;
};

// --- Scaled Shape ---

class Scaled : public Shape {
public:
    Scaled(std::shared_ptr<Shape> shape, double fx, double fy);

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;
private:
    std::shared_ptr<Shape> shape;
    double x;
    double y;
};

// --- Layered Shape --- INCOMPLETE

class Layered : public Shape {
public:
    Layered(std::initializer_list<std::shared_ptr<Shape>> shapes);

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;
private:
    std::vector<std::shared_ptr<Shape>> shapes;
};

// --- Vertical Shape --- INCOMPLETE

class Vertical : public Shape {
public:
    Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes);

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;
private:
    std::vector<std::shared_ptr<Shape>> shapes;
};

// --- Horizontal Shape --- INCOMPLETE

class Horizontal : public Shape {
public:
    Horizontal(std::initializer_list<std::shared_ptr<Shape>> shapes);

    double get_width() override;
    double get_height() override;

    void createPostScript(std::ostream &os) const override;
private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

#endif //CS372_CPS_CPS_HPP
