//
// Created by jlrine2 on 4/2/20.

#import "cps.hpp"
#import <iostream>

int main() {
    std::shared_ptr<Shape> sPtr = std::make_shared<Polygon>(60,7);
    Rotated r(sPtr, 90);


    std::cout << "newpath 306 396 moveto ";

    sPtr->createPostScript(std::cout);
    return 0;
}