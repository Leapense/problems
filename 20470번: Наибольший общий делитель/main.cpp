//=====================================================================
//   20470번:    Наибольший общий делитель                   
//   @date:   2024-10-15              
//   @link:   https://www.acmicpc.net/problem/20470  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> a(n);
    vector<int> indices;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % d == 0) {
            indices.push_back(i);
            a[i] /= d;
        } else {
            a[i] = -1; // Marking numbers not divisible by d
        }
    }

    if (indices.empty()) {
        cout << -1 << endl;
        return 0;
    }

    map<long long, vector<int>> gcd_map;

    for (int idx : indices) {
        long long num = a[idx];
        map<long long, vector<int>> temp_map = gcd_map;
        if (gcd_map.find(num) == gcd_map.end() || gcd_map[num].size() > 1) {
            gcd_map[num] = {idx};
        }
        for (auto &entry : temp_map) {
            long long current_gcd = gcd(entry.first, num);
            vector<int> current_subset = entry.second;
            current_subset.push_back(idx);
            if (gcd_map.find(current_gcd) == gcd_map.end() || gcd_map[current_gcd].size() > current_subset.size()) {
                gcd_map[current_gcd] = current_subset;
            }
        }
    }

    if (gcd_map.find(1) != gcd_map.end()) {
        vector<int> result_indices = gcd_map[1];
        cout << result_indices.size() << endl;
        for (int idx : result_indices) {
            cout << d * a[idx] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
