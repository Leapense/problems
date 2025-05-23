#pragma GCC optimize ("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N;
    cin >> N;

    map<string, pair<string, int>> birthdayMap;

    for (int i = 0; i < N; ++i) {
        string name;
        int likeability;
        string birthday;

        cin >> name >> likeability >> birthday;

        if (birthdayMap.find(birthday) != birthdayMap.end()) {
            if (likeability > birthdayMap[birthday].second) {
                birthdayMap[birthday] = {name, likeability};
            }
        } else {
            birthdayMap[birthday] = {name, likeability};
        }
    }

    vector<string> rememberedFriends;

    for (auto& entry : birthdayMap) {
        rememberedFriends.push_back(entry.second.first);
    }

    sort(rememberedFriends.begin(), rememberedFriends.end());

    cout << rememberedFriends.size() << endl;
    for (const string& name : rememberedFriends) {
        cout << name << endl;
    }

    return 0;
}