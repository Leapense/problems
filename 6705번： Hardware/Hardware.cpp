#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cin.ignore();

    while(n--) {
        string road_name;
        getline(cin, road_name);

        string buildings_line;
        getline(cin, buildings_line);


        int k;
        
        stringstream ss(buildings_line);
        ss >> k;

        int digit_counts[10] = {0};
        int total_processed = 0;

        while (total_processed < k) {
            string spec_line;
            getline(cin, spec_line);

            if (spec_line.empty()) continue;

            if (spec_line[0] == '+') {
                int first, last, interval;
                char plus;
                stringstream ss(spec_line);

                ss >> plus >> first >> last >> interval;


                for(int num = first; num <= last; num += interval) {
                    int temp = num;
                    if (temp == 0) {
                        digit_counts[0]++;
                    }

                    while (temp > 0) {
                        int digit = temp % 10;
                        digit_counts[digit]++;
                        temp /= 10;
                    }

                    total_processed++;
                    if(total_processed == k) break;
                }
            } else {
                int num;
                stringstream ss(spec_line);
                ss >> num;

                int temp = num;

                if (temp == 0) {
                    digit_counts[0]++;
                }

                while(temp > 0) {
                    int digit = temp % 10;
                    digit_counts[digit]++;
                    temp /= 10;
                }

                total_processed++;
            }
        }

        int total_digits = 0;
        for (int i = 0; i < 10; i++) {
            total_digits += digit_counts[i];
        }

        cout << road_name << "\n";
        cout << buildings_line << "\n";
        for (int i = 0; i < 10; i++) {
            cout << "Make " << digit_counts[i] << " digit " << i << "\n";
        }
        cout << "In total " << total_digits << " digit" << (total_digits > 1 ? "s" : "") << "\n";
    }

    return 0;
}