#include <catch2/catch_all.hpp>
#include <Solver.h>

TEST_CASE("edge cases are handled", "[Solver::get_partitions]") {
    Solver solver({}, 1);
    const auto result = solver.get_partitions();
    REQUIRE(result.partitions.empty());
    REQUIRE(result.optimal_max == 0);

    Solver solver2({1, 2, 3}, 0);
    const auto result2 = solver2.get_partitions();
    REQUIRE(result2.partitions.empty());
    REQUIRE(result2.optimal_max == 0);
}

TEST_CASE("count 2 and same value", "[Solver::get_partitions]") {
    Solver solver({10, 10, 10}, 2);
    auto result = solver.get_partitions();
    REQUIRE(result.optimal_max == 20);
    REQUIRE(result.partitions.size() == 2);
    REQUIRE(result.partitions[1][0] == 10);
    REQUIRE(result.partitions[1][1] == 10);
    REQUIRE(result.partitions[2][0] == 10);
}

TEST_CASE("count == numbers length", "[Solver::get_partitions]") {
    Solver solver({10, 10, 10}, 3);
    auto result = solver.get_partitions();
    REQUIRE(result.optimal_max == 10);
    REQUIRE(result.partitions.size() == 3);
    REQUIRE(result.partitions[1][0] == 10);
    REQUIRE(result.partitions[2][0] == 10);
    REQUIRE(result.partitions[3][0] == 10);
}

TEST_CASE("count 1 returns input", "[Solver::get_partitions]") {
    Solver solver({1, 2, 3}, 1);
    auto result = solver.get_partitions();
    REQUIRE(result.optimal_max == 6);
    REQUIRE(result.partitions.size() == 1);
    REQUIRE(!result.partitions[1].empty());
    REQUIRE(result.partitions[1][0] == 1);
    REQUIRE(result.partitions[1][1] == 2);
    REQUIRE(result.partitions[1][2] == 3);
}

TEST_CASE("normal operation 1", "[Solver::get_partitions]") {
    Solver solver({11, 16, 5, 5, 12, 10}, 3);
    auto result = solver.get_partitions();
    REQUIRE(result.optimal_max == 26);
    REQUIRE(result.partitions.size() == 3);
    REQUIRE(result.partitions[1][0] == 11);
    REQUIRE(result.partitions[2][0] == 16);
    REQUIRE(result.partitions[2][1] == 5);
    REQUIRE(result.partitions[2][2] == 5);
    REQUIRE(result.partitions[3][0] == 12);
    REQUIRE(result.partitions[3][1] == 10);
}

TEST_CASE("normal operation 2", "[Solver::get_partitions]") {
    Solver solver( {8, 4, 9, 2, 3, 7, 5}, 4);
    auto result = solver.get_partitions();
    REQUIRE(result.optimal_max == 12);
    REQUIRE(result.partitions.size() == 4);
    REQUIRE(result.partitions[1][0] == 8);
    REQUIRE(result.partitions[1][1] == 4);
    REQUIRE(result.partitions[2][0] == 9);
    REQUIRE(result.partitions[2][1] == 2);
    REQUIRE(result.partitions[3][0] == 3);
    REQUIRE(result.partitions[3][1] == 7);
    REQUIRE(result.partitions[4][0] == 5);
}

TEST_CASE("normal operation 3", "[Solver::get_partitions]") {
    Solver solver( {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3);
    auto result = solver.get_partitions();
    REQUIRE(result.optimal_max == 17);
    REQUIRE(result.partitions.size() == 3);
    REQUIRE(result.partitions[1][0] == 1);
    REQUIRE(result.partitions[1][1] == 2);
    REQUIRE(result.partitions[1][2] == 3);
    REQUIRE(result.partitions[1][3] == 4);
    REQUIRE(result.partitions[1][4] == 5);
    REQUIRE(result.partitions[2][0] == 6);
    REQUIRE(result.partitions[2][1] == 7);
    REQUIRE(result.partitions[3][0] == 8);
    REQUIRE(result.partitions[3][1] == 9);
}

TEST_CASE("normal operation 4", "[Solver::get_partitions]") {
    Solver solver( {10, 20, 30, 40, 50}, 2);
    auto result = solver.get_partitions();
    REQUIRE(result.optimal_max == 90);
    REQUIRE(result.partitions.size() == 2);
    REQUIRE(result.partitions[1][0] == 10);
    REQUIRE(result.partitions[1][1] == 20);
    REQUIRE(result.partitions[1][2] == 30);
    REQUIRE(result.partitions[2][0] == 40);
    REQUIRE(result.partitions[2][1] == 50);
}
