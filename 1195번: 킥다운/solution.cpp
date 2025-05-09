#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int calculate_min_length(const std::string &s1, const std::string &s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    int min_total_length = len1 + len2;

    for (int shift = 1 - len2; shift <= len1 - 1; ++shift)
    {
        bool possible_to_mesh = true;
        for (int i2 = 0; i2 < len2; ++i2)
        {
            int s1_equivalent_idx = shift + i2;

            if (s1_equivalent_idx >= 0 && s1_equivalent_idx < len1)
            {
                if (s1[s1_equivalent_idx] == '2' && s2[i2] == '2')
                {
                    possible_to_mesh = false;
                    break;
                }
            }
        }

        if (possible_to_mesh)
        {
            int combined_assembly_start_coord = std::min(0, shift);
            int combined_assembly_end_coord_plus_1 = std::max(len1, shift + len2);
            int current_length = combined_assembly_end_coord_plus_1 - combined_assembly_start_coord;
            min_total_length = std::min(min_total_length, current_length);
        }
    }

    return min_total_length;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1_gear, s2_gear;
    std::cin >> s1_gear >> s2_gear;

    std::cout << calculate_min_length(s1_gear, s2_gear) << std::endl;

    return 0;
}