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