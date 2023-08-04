#include "catch.hpp"
#include "../src/Board.h"

TEST_CASE("Constructor", "Board")
{
    Board b;
    REQUIRE(b.IsEndState());
    REQUIRE(b.IsValid());
    REQUIRE(b.GetManhattanHeuristicValue() == 0);
}

TEST_CASE("DoSliding_v1", "Board")
{
    Board b;
    REQUIRE_THROWS(b.DoSliding(DOWN));
    REQUIRE_THROWS(b.DoSliding(RIGHT));

    b.DoSliding(UP);
    REQUIRE(b.GetManhattanHeuristicValue() == 1);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(DOWN);
    REQUIRE(b.GetManhattanHeuristicValue() == 0);
    REQUIRE(b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(LEFT);
    REQUIRE(b.GetManhattanHeuristicValue() == 1);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(RIGHT);
    REQUIRE(b.GetManhattanHeuristicValue() == 0);
    REQUIRE(b.IsEndState());
    REQUIRE(b.IsValid());
}

TEST_CASE("DoSliding_v2", "Board")
{
    Board b;

    b.DoSliding(UP);
    REQUIRE(b.GetManhattanHeuristicValue() == 1);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(UP);
    REQUIRE(b.GetManhattanHeuristicValue() == 2);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(LEFT);
    REQUIRE(b.GetManhattanHeuristicValue() == 3);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(DOWN);
    REQUIRE(b.GetManhattanHeuristicValue() == 4);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(RIGHT);
    REQUIRE(b.GetManhattanHeuristicValue() == 5);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    //Invert
    b.DoSliding(LEFT);
    REQUIRE(b.GetManhattanHeuristicValue() == 4);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(UP);
    REQUIRE(b.GetManhattanHeuristicValue() == 3);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(RIGHT);
    REQUIRE(b.GetManhattanHeuristicValue() == 2);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(DOWN);
    REQUIRE(b.GetManhattanHeuristicValue() == 1);
    REQUIRE(!b.IsEndState());
    REQUIRE(b.IsValid());

    b.DoSliding(DOWN);
    REQUIRE(b.GetManhattanHeuristicValue() == 0);
    REQUIRE(b.IsEndState());
    REQUIRE(b.IsValid());
}