#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <iomanip>

const int MINUTES_IN_DAY = 24 * 60;

struct TimePoint
{
    int h, m;

    int to_minutes() const
    {
        return h * 60 + m;
    }
};

struct BusRoute
{
    std::string from_city;
    std::string to_city;
    TimePoint departure_tp;
    TimePoint arrival_tp;
    int id; // for debugging or specific selection if needed

    // Duration passenger is on this bus (in minutes)
    int get_on_board_duration() const
    {
        int dep_m = departure_tp.to_minutes();
        int arr_m = arrival_tp.to_minutes();
        if (arr_m >= dep_m)
        {
            return arr_m - dep_m + 1;
        }
        else
        {
            return (arr_m + MINUTES_IN_DAY) - dep_m + 1;
        }
    }
};

TimePoint minutes_to_timepoint(int total_minutes)
{
    if (total_minutes < 0)
        total_minutes = 0; // Should not happen with correct logic
    return {total_minutes / 60, total_minutes % 60};
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::ws(std::cin);

    std::vector<BusRoute> zagreb_graz_routes;
    std::vector<BusRoute> graz_wroclaw_routes;

    for (int i = 0; i < n; ++i)
    {
        std::string line;
        std::getline(std::cin, line);

        std::string route_part, times_part;
        size_t first_space = line.find(' ');
        route_part = line.substr(0, first_space);
        times_part = line.substr(first_space + 1);

        std::string dep_city_str, arr_city_str;
        size_t dash_route = route_part.find('-');
        dep_city_str = route_part.substr(0, dash_route);
        arr_city_str = route_part.substr(dash_route + 1);

        TimePoint dep_tp, arr_tp;
        sscanf(times_part.c_str(), "%d:%d--%d:%d", &dep_tp.h, &dep_tp.m, &arr_tp.h, &arr_tp.m);

        BusRoute current_route = {dep_city_str, arr_city_str, dep_tp, arr_tp, i};

        if (dep_city_str == "Zagreb" && arr_city_str == "Graz")
        {
            zagreb_graz_routes.push_back(current_route);
        }
        else if (dep_city_str == "Graz" && arr_city_str == "Wroclaw")
        {
            graz_wroclaw_routes.push_back(current_route);
        }
    }

    long long min_total_duration = std::numeric_limits<long long>::max();

    if (zagreb_graz_routes.empty() || graz_wroclaw_routes.empty())
    {
        std::cout << "NEMOGUCE" << std::endl;
        return 0;
    }

    for (const auto &zg_route : zagreb_graz_routes)
    {
        int zg_dep_tod_minutes = zg_route.departure_tp.to_minutes();
        int l_zg = zg_route.get_on_board_duration();

        long long time_free_after_zg_abs = static_cast<long long>(zg_dep_tod_minutes) + l_zg;

        for (const auto &gw_route : graz_wroclaw_routes)
        {
            int gw_dep_tod_minutes = gw_route.departure_tp.to_minutes();
            int l_gw = gw_route.get_on_board_duration();

            long long day_index_of_free_time = (time_free_after_zg_abs - 1) / MINUTES_IN_DAY; // -1 because time_free_after_zg_abs is start of next minute
                                                                                              // if free at 1440 (start of day 1), day_index is 1. (1439)/1440 = 0. (1440-1)/1440=0 if zg_dep=0, L_ZG=1440
                                                                                              // if free at 1440 (exactly 24:00 of day 0 / 00:00 of day 1) day_index should be 1 for gw_dep_tod

            if (time_free_after_zg_abs > 0 && (time_free_after_zg_abs % MINUTES_IN_DAY == 0))
            {
                // If time_free_after_zg_abs is 1440, 2880, etc. (exactly end of a day)
                // It means free at 00:00 of (day_index_of_free_time + 1)
                // The day_index_of_free_time computed above would be (1440/1440)-1 = 0 if we use floor( (T-1)/M ).
                // Simpler: floor (T/M) if T is start of minute. T is start of minute here.
                // if T = 1440 (start of day 1, 00:00), day_index = 1440 / 1440 = 1 (correct for day 1)
                // if T = 1439 (start of day 0, 23:59), day_index = 1439 / 1440 = 0 (correct for day 0)
                day_index_of_free_time = time_free_after_zg_abs / MINUTES_IN_DAY;
                if (time_free_after_zg_abs % MINUTES_IN_DAY == 0 && time_free_after_zg_abs != 0 && zg_dep_tod_minutes + l_zg == time_free_after_zg_abs)
                {
                    // This case happens if L_ZG makes it exactly to midnight.
                    // e.g. dep 00:00, L_ZG=1440. free_abs=1440. day_index=1. tod_free=0.
                    // e.g. dep 10:00, L_ZG= X, free_abs = 1440. day_index=1. tod_free=0.
                    // this day_index logic seems tricky.
                }
            }
            day_index_of_free_time = (time_free_after_zg_abs - 1) / MINUTES_IN_DAY;

            long long actual_gw_dep_time_abs;
            long long current_day_gw_dep_abs = day_index_of_free_time * MINUTES_IN_DAY + gw_dep_tod_minutes;

            if (current_day_gw_dep_abs >= time_free_after_zg_abs)
            {
                actual_gw_dep_time_abs = current_day_gw_dep_abs;
            }
            else
            {
                actual_gw_dep_time_abs = (day_index_of_free_time + 1) * MINUTES_IN_DAY + gw_dep_tod_minutes;
            }

            long long l_w = actual_gw_dep_time_abs - time_free_after_zg_abs;
            if (l_w < 0)
            {             // Should not happen with correct logic above
                continue; // Or handle as error
            }

            long long current_total_duration = static_cast<long long>(l_zg) + l_w + l_gw;
            min_total_duration = std::min(min_total_duration, current_total_duration);
        }
    }

    if (min_total_duration == std::numeric_limits<long long>::max())
    {
        std::cout << "NEMOGUCE" << std::endl;
    }
    else
    {
        TimePoint result_tp = minutes_to_timepoint(min_total_duration);
        std::cout << result_tp.h << ":" << std::setw(2) << std::setfill('0') << result_tp.m << std::endl;
    }

    return 0;
}