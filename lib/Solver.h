#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <map>

class Solver {
public:

    struct Result {
        std::map<unsigned int,std::vector<unsigned int>> partitions;
        unsigned int optimal_max = 0;
    };

    Solver(const std::vector<unsigned int> &numbers, unsigned int partition_count);
    Result get_partitions();

private:
    static bool can_be_partitioned(
        const std::vector<unsigned int> &numbers,
        unsigned int partition_count,
        unsigned int max_value);

    static unsigned int find_optimal_max(
        const std::vector<unsigned int> &numbers,
        unsigned int partition_count);

    static std::map<unsigned int,std::vector<unsigned int>> partition(
        const std::vector<unsigned int> &numbers,
        unsigned int partition_count,
        unsigned int max_value);

    std::vector<unsigned int> _numbers;
    unsigned int _partition_count;
};


#endif //SOLVER_H
