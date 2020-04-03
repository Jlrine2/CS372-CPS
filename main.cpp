//
// Created by jlrine2 on 4/2/20.

#import "cps.hpp"
#import <iostream>

int main() {
    std::shared_ptr<Shape> sPtr = std::make_shared<Polygon>(5,7);
    Scaled r(sPtr, 2,4);


    std::cout << "newpath 306 396 moveto ";

    r.createPostScript(std::cout);

    return 0;
}