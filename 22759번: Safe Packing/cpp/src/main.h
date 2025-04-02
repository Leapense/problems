#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <cstdint>

using namespace std;

vector<unsigned long long> generateFibonacci(unsigned long long S);

int maxPackableItems(int W, int F, unsigned long long S, const vector<unsigned long long>& items, const vector<unsigned long long>& fib);

#endif
