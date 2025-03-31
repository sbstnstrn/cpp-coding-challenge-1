#include <catch2/catch_all.hpp>
#include <Solver.h>

TEST_CASE("edge cases are handled", "[Solver::get_partitions]") {
    Solver solver({}, 1);
    REQUIRE(solver.get_partitions().empty());

    Solver solver2({1, 2, 3}, 0);
    REQUIRE(solver2.get_partitions().empty());
}

TEST_CASE("count 2 and same value", "[Solver::get_partitions]") {
    Solver solver({10, 10, 10}, 2);
    auto result = solver.get_partitions();
    REQUIRE(result.size() == 2);
    REQUIRE(result[1][0] == 10);
    REQUIRE(result[1][1] == 10);
    REQUIRE(result[2][0] == 10);
}

TEST_CASE("count == numbers length", "[Solver::get_partitions]") {
    Solver solver({10, 10, 10}, 3);
    auto result = solver.get_partitions();
    REQUIRE(result.size() == 3);
    REQUIRE(result[1][0] == 10);
    REQUIRE(result[2][0] == 10);
    REQUIRE(result[3][0] == 10);
}

TEST_CASE("count 1 returns input", "[Solver::get_partitions]") {
    Solver solver({1, 2, 3}, 1);
    auto result = solver.get_partitions();
    REQUIRE(result.size() == 1);
    REQUIRE(!result[1].empty());
    REQUIRE(result[1][0] == 1);
    REQUIRE(result[1][1] == 2);
    REQUIRE(result[1][2] == 3);
}

TEST_CASE("normal operation 1", "[Solver::get_partitions]") {
    Solver solver({11, 16, 5, 5, 12, 10}, 3);
    auto result = solver.get_partitions();
    REQUIRE(result.size() == 3);
    REQUIRE(result[1][0] == 11);
    REQUIRE(result[2][0] == 16);
    REQUIRE(result[2][1] == 5);
    REQUIRE(result[2][2] == 5);
    REQUIRE(result[3][0] == 12);
    REQUIRE(result[3][1] == 10);
}

TEST_CASE("normal operation 2", "[Solver::get_partitions]") {
    Solver solver( {8, 4, 9, 2, 3, 7, 5}, 4);
    auto result = solver.get_partitions();
    REQUIRE(result.size() == 4);
    REQUIRE(result[1][0] == 8);
    REQUIRE(result[1][1] == 4);
    REQUIRE(result[2][0] == 9);
    REQUIRE(result[2][1] == 2);
    REQUIRE(result[3][0] == 3);
    REQUIRE(result[3][1] == 7);
    REQUIRE(result[4][0] == 5);
}

TEST_CASE("normal operation 3", "[Solver::get_partitions]") {
    Solver solver( {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3);
    auto result = solver.get_partitions();
    REQUIRE(result.size() == 3);
    REQUIRE(result[1][0] == 1);
    REQUIRE(result[1][1] == 2);
    REQUIRE(result[1][2] == 3);
    REQUIRE(result[1][3] == 4);
    REQUIRE(result[1][4] == 5);
    REQUIRE(result[2][0] == 6);
    REQUIRE(result[2][1] == 7);
    REQUIRE(result[3][0] == 8);
    REQUIRE(result[3][1] == 9);
}

TEST_CASE("normal operation 4", "[Solver::get_partitions]") {
    Solver solver( {10, 20, 30, 40, 50}, 2);
    auto result = solver.get_partitions();
    REQUIRE(result.size() == 2);
    REQUIRE(result[1][0] == 10);
    REQUIRE(result[1][1] == 20);
    REQUIRE(result[1][2] == 30);
    REQUIRE(result[2][0] == 40);
    REQUIRE(result[2][1] == 50);
}
