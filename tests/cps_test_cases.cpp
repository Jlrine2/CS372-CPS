//
// Created by jlrine2 on 3/23/20.
//
#include "catch.hpp"
#include "cps.hpp"
#include <cmath>

TEST_CASE("Circle dimension calculations") {
    std::shared_ptr<Shape> c1= std::make_shared<Circle>(1.0);

    REQUIRE(c1 -> get_height() == Approx(2.0));
    REQUIRE(c1 -> get_width() == Approx(2.0));

    std::shared_ptr<Shape> c2= std::make_shared<Circle>(2.0);


    REQUIRE(c2 -> get_height() == Approx(4.0));
    REQUIRE(c2 -> get_width() == Approx(4.0));

}

TEST_CASE("Polygon dimension calculations") {
    std::shared_ptr<Shape> p1 = std::make_shared<Polygon>(1.0, 3);


    REQUIRE(p1 -> get_width() == Approx(1.0));
    REQUIRE(p1 -> get_height() == Approx(std::sqrt(0.75)));


    std::shared_ptr<Shape> p2 = std::make_shared<Polygon>(1.0, 6);

    REQUIRE(p2 -> get_width() == Approx(2.0));
    REQUIRE(p2 -> get_height() == Approx(std::sqrt(0.75)*2));

    std::shared_ptr<Shape> p3 = std::make_shared<Polygon>(1.0, 8);
    REQUIRE(p3 -> get_width() == Approx(2.4142135624));
    REQUIRE(p3 -> get_height() == Approx(2.4142135624));
}

TEST_CASE("Square dimension calculations") {
    std::shared_ptr<Shape> s1 = std::make_shared<Square>(1.0);

    REQUIRE(s1 -> get_width() == Approx(1.0));
    REQUIRE(s1 -> get_height() == Approx(1.0));

    std::shared_ptr<Shape> s2 = std::make_shared<Square>(2.0);

    REQUIRE(s2 -> get_width() == Approx(2.0));
    REQUIRE(s2 -> get_height() == Approx(2.0));
}

TEST_CASE("Triangle dimension calculations") {
    std::shared_ptr<Shape> t1 = std::make_shared<Triangle>(1.0);

    REQUIRE(t1 -> get_width() == Approx(1.0));
    REQUIRE(t1 -> get_height() == Approx(sqrt(0.75)));

    std::shared_ptr<Shape> t2 = std::make_shared<Triangle>(2.0);

    REQUIRE(t2 -> get_height() == Approx(sqrt(3)));
    REQUIRE(t2 -> get_width() == Approx(2.0));
}

TEST_CASE("Rectangle dimension calculations") {
    std::shared_ptr<Shape> r1 = std::make_shared<Rectangle>(1.0, 2.0);

    REQUIRE(r1 -> get_width() == Approx(1.0));
    REQUIRE(r1 -> get_height() == Approx(2.0));

    std::shared_ptr<Shape> r2 = std::make_shared<Rectangle>(2.0,2.0);

    REQUIRE(r2 -> get_width() == Approx(2.0));
    REQUIRE(r2 -> get_height() == Approx(2.0));
}