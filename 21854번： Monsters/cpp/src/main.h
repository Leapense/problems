#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <cstdint>

constexpr int64_t MOD = 1'000'000'007LL;

int64_t power(int64_t base, int64_t exp);
int64_t calculate_total_sum(const std::vector<int64_t> &k_values);

#endif