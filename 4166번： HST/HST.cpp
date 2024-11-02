#include <bits/stdc++.h>

using namespace std;

struct Category {
    string name;
    long long pst;
    long long gst;
    long long hst;
};

long long parse_percentage(const string& s) {
    size_t len = s.size();
    string num = s.substr(0, len-1);
    size_t dot = num.find('.');

    long long integer_part = 0;
    long long fractional_part = 0;

    if (dot == string::npos) {
        integer_part = stoll(num);
    } else {
        string int_str = num.substr(0, dot);

        if (!int_str.empty()) {
            integer_part = stoll(int_str);
        } else {
            integer_part = 0;
        }

        string frac_str = num.substr(dot+1);
        if (frac_str.size() == 0) {
            fractional_part = 0;
        } else if (frac_str.size() == 1) {
            fractional_part = stoll(frac_str) * 10;
        } else {
            fractional_part = stoll(frac_str.substr(0, 2));
        }
    }

    return integer_part * 100 + fractional_part;
}

long long parse_price(const string& s) {
    string num = s.substr(1);
    size_t dot = num.find('.');

    long long integer_part = 0;
    long long fractional_part = 0;

    if (dot == string::npos) {
        integer_part = stoll(num);
    } else {
        string int_str = num.substr(0, dot);

        if (!int_str.empty()) {
            integer_part = stoll(int_str);
        } else {
            integer_part = 0;
        }
        string frac_str = num.substr(dot+1);
        if (frac_str.size() == 0) {
            fractional_part = 0;
        } else if (frac_str.size() == 1) {
            fractional_part = stoll(frac_str) * 10;
        } else {
            fractional_part = stoll(frac_str.substr(0, 2));
        }
    }

    return integer_part * 100 + fractional_part;
}

long long compute_tax(long long price_cents, long long rate_scaled_percent) {
    return (price_cents * rate_scaled_percent + 5000) / 10000;
}

string format_difference(long long diff_cents) {
    string result = "";

    if (diff_cents < 0) {
        result += "-";
        diff_cents = -diff_cents;
    }

    long long dollars = diff_cents / 100;
    long long cents = diff_cents % 100;

    result += to_string(dollars) + ".";

    if (cents < 10) {
        result += "0" + to_string(cents);
    } else {
        result += to_string(cents);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int N, M;
        cin >> N >> M;

        vector<Category> categories(N);

        for(int i = 0; i < N; i++) {
            string cat_name, pst_str, gst_str, hst_str;
            cin >> cat_name >> pst_str >> gst_str >> hst_str;

            categories[i].name = cat_name;
            categories[i].pst = parse_percentage(pst_str);
            categories[i].gst = parse_percentage(gst_str);
            categories[i].hst = parse_percentage(hst_str);
        }

        sort(categories.begin(), categories.end(), [&](const Category& a, const Category& b) -> bool {
            return a.name < b.name;
        });

        long long total_HST = 0;
        long long total_PST = 0;
        long long total_GST = 0;

        for (int i = 0; i < M; i++) {
            string purchase_cat, price_str;
            cin >> purchase_cat >> price_str;

            int left = 0, right = N - 1;
            int found = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if (categories[mid].name == purchase_cat) {
                    found = mid;
                    break;
                } else if (categories[mid].name < purchase_cat) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (found == -1) {
                continue;
            }


            long long price_cents = parse_price(price_str);

            long long HST = compute_tax(price_cents, categories[found].hst);
            long long PST = compute_tax(price_cents, categories[found].pst);
            long long GST = compute_tax(price_cents, categories[found].gst);

            total_HST += HST;
            total_PST += PST;
            total_GST += GST;
        }

        long long difference_cents = total_HST - (total_PST + total_GST);

        string output = format_difference(difference_cents);

        cout << output << "\n";
    }

    return 0;
}