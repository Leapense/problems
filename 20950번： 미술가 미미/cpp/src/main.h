#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Color
{
    int r, g, b;
};

int computeMinDifference(const vector<Color> &colors, const Color &target);

#endif