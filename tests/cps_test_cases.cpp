//
// Created by jlrine2 on 3/23/20.
//
#include "catch.hpp"
#include "cps.hpp"


TEST_CASE("Circle dimention calculations") {
    Circle c1(1.0);
    Shape* c1base = &c1;

    REQUIRE(c1base -> get_height() == 2.0);
    REQUIRE(c1base -> get_width() == 2.0);

    Circle c2(2.0);
    Shape* c2base = &c2;

    REQUIRE(c2base -> get_height() == 4.0);
    REQUIRE(c2base -> get_width() == 4.0);

}

TEST_CASE("Polygon dimention calculations") {
    Polygon p1(1.0, 3);
    Shape* p1base = &p1;

    REQUIRE(p1base -> get_width() == 1.0);
    REQUIRE(p1base -> get_height() == sqrt(0.75));


    Polygon p2(1.0, 5);
    Shape* p2base = &p2;
    REQUIRE(p2base -> get_width() == 1.0);
    REQUIRE(p2base -> get_height() == sqrt(0.75));
}