#include <iostream>
#include <string>
#include <map>
#include <bitset>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to convert binary string to float according to EDSAC fixed-point format
double bin_to_float(const string& s) {
    string bin_str = s;
    double result = 0.0;
    bool minus = true;
    if (bin_str[0] == '0') {
        minus = false;
    }
    // Powers of 2 for each bit position
    double pow_arr[16] = {
        2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0,
        512.0, 1024.0, 2048.0, 4096.0, 8192.0, 16384.0, 32768.0, 65536.0
    };
    if (!minus) {
        // For positive numbers, sum the fractional parts
        for (size_t i = 1; i < bin_str.size(); ++i) {
            if (bin_str[i] == '1') {
                result += 1.0 / pow_arr[i - 1];
            }
        }
        return result;
    } else {
        // For negative numbers, compute two's complement
        string tmp_s = "";
        size_t i;
        for (i = bin_str.size() - 1; i != (size_t)(-1); --i) {
            if (bin_str[i] == '1') {
                tmp_s += '0';
                bin_str = bin_str.substr(0, i);
                for (int j = tmp_s.size() - 1; j >= 0; --j) {
                    bin_str += tmp_s[j];
                }
                break;
            }
            tmp_s += '1';
        }
        // Sum the fractional parts
        for (size_t i = 1; i < bin_str.size(); ++i) {
            if (bin_str[i] == '0') {
                result += 1.0 / pow_arr[i - 1];
            }
        }
        return -result;
    }
}

int main() {
    // Mapping from characters to their 5-bit binary codes
    string letters = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";
    map<char, string> dic;
    for (size_t v = 0; v < letters.size(); ++v) {
        char k = letters[v];
        string bin_code = bitset<5>(v).to_string();
        dic[k] = bin_code;
    }

    int p;
    cin >> p;
    for (int tc = 0; tc < p; ++tc) {
        string c, s_type;
        int d;
        cin >> c >> d >> s_type;
        if (c == "?" && d == 0 && s_type == "F") {
            cout << "-1.0" << endl;
            continue;
        }
        // Build the 17-bit binary string
        string tmp = dic[c[0]] + bitset<11>(d).to_string();
        if (s_type == "D") {
            tmp += "1";
        } else {
            tmp += "0";
        }
        // Convert binary string to float
        double val = bin_to_float(tmp);

        // Format the result with 16 decimal places
        ostringstream oss;
        oss << fixed << setprecision(16) << val;
        string answer = oss.str();

        // Remove unnecessary trailing zeros
        string new_answer = "";
        bool zero_checker = true;
        for (int i = answer.size() - 1; i > 0; --i) {
            if (answer[i - 1] == '.') {
                new_answer += answer[i];
                continue;
            }
            if (zero_checker) {
                if (answer[i] == '0') {
                    continue;
                } else {
                    new_answer += answer[i];
                    zero_checker = false;
                }
            } else {
                new_answer += answer[i];
            }
        }
        new_answer += answer[0];

        // Reverse the string to get the correct order
        for (int i = new_answer.size() - 1; i >= 0; --i) {
            cout << new_answer[i];
        }
        cout << endl;
    }
    return 0;
}
