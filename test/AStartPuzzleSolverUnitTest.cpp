#include "catch.hpp"
#include "../src/AStarPuzzleSolver.h"

TEST_CASE("Test_v1", "AStarPuzzleSolver")
{
    AStarPuzzleSolver solver;
    REQUIRE_THROWS(solver.Run());
    REQUIRE(solver.GetSolutionPath().empty());
}

TEST_CASE("Test_v2", "AStarPuzzleSolver")
{
    AStarPuzzleSolver solver;
    solver.Initialize(Board());
    solver.Run();
    REQUIRE(solver.GetSolutionPath().size() == 1);
}

TEST_CASE("Test_v3", "AStarPuzzleSolver")
{
    AStarPuzzleSolver solver;
    Board b;

    b.DoSliding(LEFT);
    b.DoSliding(UP);
    b.DoSliding(LEFT);

    solver.Initialize(b);
    solver.Run();
    REQUIRE(solver.GetSolutionPath().size() == 4);
}