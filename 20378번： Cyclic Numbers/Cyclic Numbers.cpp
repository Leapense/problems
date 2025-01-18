#include <bits/stdc++.h>
using namespace std;

string multiply(string num, int k) {
    string result = "";
    int carry = 0;

    for (int i = num.size() - 1; i >= 0; i--) {
        int temp = (num[i] - '0') * k + carry;
        carry = temp / 10;
        result += (temp % 10) + '0';
    }

    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool is_cyclic_permutation(string original, string product) {
    if (product.size() < original.size()) {
        product = string(original.size() - product.size(), '0') + product;
    }

    if (product.size() != original.size()) {
        return false;
    }

    string doubled = original + original;
    return doubled.find(product) != string::npos;
}

int main() {
    string num;
    while (cin >> num) {
        int n = num.size();
        bool cyclic = true;
        for (int k = 1; k <= n; k++) {
            string product = multiply(num, k);
            if (!is_cyclic_permutation(num, product)) {
                cyclic = false;
                break;
            }
        }
        if (cyclic) {
            cout << num << " is cyclic\n";
        } else {
            cout << num << " is not cyclic\n";
        }
    }

    return 0;
}