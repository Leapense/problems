//=====================================================================
//   28844번:    Ослабление флота                   
//   @date:   2024-11-03              
//   @link:   https://www.acmicpc.net/problem/28844  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
	int size;
	vector<int> tree;

	FenwickTree(int n) {
		size = n;
		tree.assign(n + 2, 0);
	}

	void update(int idx, int delta) {
		while (idx <= size) {
			tree[idx] += delta;
			idx += idx & (-idx);
		}
	}
	int query (int idx) const {
		int res = 0;
		int i = idx;
		while (i > 0) {
			res += tree[i];
			i -= i & (-i);
		}

		return res;
	}
	int find_kth(int k) const {
		int idx = 0;
		int bitMask = 1;

		while (bitMask <= size) bitMask <<= 1;
		bitMask >>= 1;

		while (bitMask > 0) {
			if (idx + bitMask <= size && tree[idx + bitMask] < k) {
				idx += bitMask;
				k -= tree[idx];
			}
			bitMask >>= 1;
		}

		return idx + 1;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> sorted_a = a;
	sort(sorted_a.begin(), sorted_a.end());
	sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

	auto get_index = [&](int x) -> int {
		return lower_bound(sorted_a.begin(), sorted_a.end(), x) - sorted_a.begin() + 1;
	};

	int unique_size = sorted_a.size();
	FenwickTree ft(unique_size);
	vector<int> freq(unique_size + 1, 0);
	for (auto x : a) {
		int idx = get_index(x);
		freq[idx]++;
		ft.update(idx, 1);
	}

	vector<int> result;
	result.reserve(n);

	int total = n;

	for (int i = 0; i < n; i++) {
		int m = total;
		int kth;

		if (m % 2 == 1) {
			kth = (m + 1) / 2;
		} else {
			kth = m / 2;
		}

		int compressed_idx = ft.find_kth(kth);
		int val = sorted_a[compressed_idx - 1];
		result.push_back(val);

		ft.update(compressed_idx, -1);
		total--;
	}

	for (int i = 0; i < result.size(); i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << result[i];
	}
}
