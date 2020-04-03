//
// Created by jlrine2 on 4/2/20.

#import "cps.hpp"
#import <iostream>

int main() {
    std::shared_ptr<Shape> sPtr = std::make_shared<Rectangle>(5,7);
    std::shared_ptr<Shape> sPtr1 = std::make_shared<Rectangle>(5,7);
    std::shared_ptr<Shape> sPtr2 = std::make_shared<Rectangle>(5,7);

    Horizontal a {sPtr, sPtr1, sPtr2};


    std::cout << "newpath ";

    a.createPostScript(std::cout);


    return 0;
}