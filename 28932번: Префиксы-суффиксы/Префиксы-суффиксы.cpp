#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 함수: 주어진 숫자의 모든 프리픽스를 구함
vector<string> getPrefixes(const string &num) {
    vector<string> prefixes;
    for (size_t i = 1; i <= num.length(); ++i) {
        prefixes.push_back(num.substr(0, i));
    }
    return prefixes;
}

// 함수: 주어진 숫자의 모든 서픽스를 구함
vector<string> getSuffixes(const string &num) {
    vector<string> suffixes;
    for (size_t i = 0; i < num.length(); ++i) {
        suffixes.push_back(num.substr(i, num.length() - i));
    }
    return suffixes;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < n; ++i) {
        vector<string> prefixes = getPrefixes(numbers[i]);
        for (int j = 0; j < n; ++j) {
            vector<string> suffixes = getSuffixes(numbers[j]);
            for (const string &prefix : prefixes) {
                for (const string &suffix : suffixes) {
                    if (prefix == suffix) {
                        cout << (i + 1) << " " << (j + 1) << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}
