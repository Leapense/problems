#include <bits/stdc++.h>

struct Point
{
    std::string id;
    double flex;
    double cond;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t n;
    if (!(std::cin >> n))
        return 0;

    std::vector<Point> a;
    a.reserve(n);
    for (std::size_t i = 0; i < n; ++i)
    {
        Point p;
        std::cin >> p.id >> p.flex >> p.cond;
        a.emplace_back(std::move(p));
    }

    // Sort by descending flexibility, but keep stable order inside equal groups (not strictly required)
    std::sort(a.begin(), a.end(), [](const Point &lhs, const Point &rhs)
              {
                  if (lhs.flex != rhs.flex)
                      return lhs.flex > rhs.flex; // larger flexibility first
                  return lhs.cond > rhs.cond;     // tie‑break to speed up scan
              });

    const double NEG_INF = -std::numeric_limits<double>::infinity();
    double max_cond_so_far = NEG_INF; // best conductivity among points with *greater* flexibility
    std::vector<std::string> dominant_ids;
    dominant_ids.reserve(n / 8); // heuristic

    std::size_t i = 0;
    while (i < a.size())
    {
        // group of equal flexibility
        std::size_t j = i;
        double group_max_cond = NEG_INF;
        while (j < a.size() && a[j].flex == a[i].flex)
        {
            if (a[j].cond > max_cond_so_far)
            {
                dominant_ids.push_back(a[j].id);
            }
            group_max_cond = std::max(group_max_cond, a[j].cond);
            ++j;
        }
        // update prefix maximum conductivity with the best from this group
        max_cond_so_far = std::max(max_cond_so_far, group_max_cond);
        i = j;
    }

    // Output IDs in alphanumeric (lexicographic) order
    std::sort(dominant_ids.begin(), dominant_ids.end());

    for (std::size_t k = 0; k < dominant_ids.size(); ++k)
    {
        if (k)
            std::cout << ' ';
        std::cout << dominant_ids[k];
    }
    std::cout << '\n';
    return 0;
}
