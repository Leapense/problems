#ifndef MAIN_H
#define MAIN_H

#include <cstdint>
#include <vector>
#include <algorithm>
#include <cstdlib>

struct Segment
{
    int64_t start;
    int64_t end;
    int64_t startTime;
};

class DeliveryRoute
{
public:
    DeliveryRoute();
    int64_t solveQuery(int64_t x) const;

private:
    std::vector<Segment> segments;
};

#endif