#include <iostream>
#include <vector>
#include <map>

int main()
{
    int n, d;
    std::cin >> n >> d;

    int integer_part = n / d;
    int remainder = n % d;

    std::vector<int> digits;
    std::map<int, int> remainder_positions;

    bool first_digit_checked = false;

    std::string result;

    int first_digit = -1;

    int max_iterations = 100000;
    int iterations = 0;

    while (true) {
        if (iterations++ > max_iterations) {
            result = "throw out";
            break;
        }

        if (remainder_positions.find(remainder) != remainder_positions.end()) {
            result = "throw out";
            break;
        } else {
            remainder_positions[remainder] = digits.size();
        }

        remainder *= 10;
        int digit = remainder / d;
        remainder %= d;

        if (!first_digit_checked) {
            first_digit = digit;
            first_digit_checked = true;

            if (digit == 0) {
                result = "0";
                break;
            } else if (digit == 9) {
                result = "1";
                break;
            } else {
                digits.push_back(digit);
            }
        } else {
            if (digit == 0 or digit == 9) {
                bool round_up = (digit == 9);
                if (round_up) {
                    int idx = digits.size() - 1;
                    digits[idx]++;

                    while (digits[idx] == 10) {
                        digits[idx] = 0;
                        idx--;

                        if (idx < 0) {
                            integer_part++;
                            break;
                        } else {
                            digits[idx]++;
                        }
                    }
                }

                result = std::to_string(integer_part) + ".";
                for (int num : digits) {
                    result += std::to_string(num);
                }

                break;
            } else {
                digits.push_back(digit);
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}