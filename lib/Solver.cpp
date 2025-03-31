//
// Created by SStern on 30.03.2025.
//

#include "Solver.h"
#include <numeric>
#include <algorithm>

Solver::Solver(const std::vector<unsigned> &numbers, unsigned int partition_count)
    : _numbers(numbers), _partition_count(partition_count) {
}

std::map<unsigned int,std::vector<unsigned int>> Solver::get_partitions() {
    if (_numbers.empty() || _partition_count == 0) {
        return {};
    }

    if (_partition_count == 1) {
        return { {1, _numbers} };
    }

    return partition(_numbers, _partition_count, find_optimum(_numbers, _partition_count));
}

bool Solver::can_be_partitioned(
    const std::vector<unsigned> &numbers,
    unsigned int partition_count,
    unsigned int max_value) {

    unsigned int count = 1;
    unsigned int sum = 0;

    for (const auto num : numbers) {
        if (sum + num > max_value) {
            count++;
            sum = num;
            if (count > partition_count) {
                return false;
            }
        } else {
            sum += num;
        }
    }
    return true;
}

unsigned int Solver::find_optimum(
    const std::vector<unsigned> &numbers,
    unsigned int partition_count) {

    unsigned int left = *std::ranges::max_element(numbers);
    unsigned int right = std::accumulate(numbers.begin(), numbers.end(), 0u);
    unsigned int optimum = right;

    while (left <= right) {
        const auto mid = left + (right - left) / 2;
        if (can_be_partitioned(numbers, partition_count, mid)) {
            optimum = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return optimum;
}

std::map<unsigned int,std::vector<unsigned int>>Solver::partition(
    const std::vector<unsigned int> &numbers,
    unsigned int partition_count,
    unsigned int max_value) {

    std::map<unsigned int, std::vector<unsigned int>> result;
    std::vector<unsigned int> current;
    unsigned int sum = 0;
    unsigned int remaining_partitions = partition_count;
    unsigned int segment_index = 1;

    for (auto num : numbers) {
        if (sum + num > max_value) {
            result[segment_index++] = current;
            current.clear();
            sum = 0;
            --remaining_partitions;
        }

        current.push_back(num);
        sum += num;
    }

    if (!current.empty()) {
        result[segment_index] = current;
    }
    return result;
}


