#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <string>
#include <optional>

struct Move
{
    int x, y;
    int flipCount;
};

std::optional<Move> find_best_move(const std::vector<std::string> &board);

#endif