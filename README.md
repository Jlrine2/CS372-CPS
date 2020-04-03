# CS372-CPS

Code for CS 372 project 2 c++ to postscript
![CI](https://github.com/Jlrine2/CS372-CPS/workflows/CI/badge.svg)

This project describes a shape language that is used to output shapes to a postscript script. 

## Usage
To use this library you will need bot the cps.cpp file and the cps.hpp file included in your project.

The first step to usage is to create shapes. Shapes can be created by calling one of these 
factory functions which all return a std::shared_ptr<Shape>:
* `getCircle(double radius);`
* `getSquare(double sideLength);`
* `getRectangle(double width, double height);`
* `getTriangle(double sidelength);`
* `getSpacer(double width, double height);`
* `getPolygon(double sideLength, double numberOfSides);`


you can apply transformations and composition by creating the following shapes:
* `getRotated(std::shared_ptr<Shape> shape, int rotationAngle);`
* `getVertical(std::initializer_list<std::shared_ptr<Shape>> shapes);`
* `getHorizontal(std::initializer_list<std::shared_ptr<Shape>> shapes);`
* `getLayered(std::initializer_list<std::shared_ptr<Shape>> shapes);`

Once you are happy with your shape you can get the PostScript for it by calling 
`Shape -> createPostScript(std::ostream & os)` which takes an output stream like `std::cout`

If you want an actual page that you can compile or print, you instead need to call
`getPostScriptPage(std::ostream &os, std::shared_ptr<Shape> shape)`

## tests
All of our test_cases live in the file `tests/cps_test_cases` this file shows examples of other ways to create and use shapes.

