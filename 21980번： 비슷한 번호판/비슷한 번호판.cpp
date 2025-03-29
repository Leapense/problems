#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <string>
#include <tuple>
#include <functional>

using namespace std;

struct PlateKey
{
    array<int, 26> freq{};
    int upperCount = 0;

    bool operator==(const PlateKey &other) const
    {
        return freq == other.freq && upperCount == other.upperCount;
    }
};

struct PlateKeyHash
{
    size_t operator()(const PlateKey &key) const
    {
        size_t hashVal = 0;
        hash<int> intHasher;

        for (int cnt : key.freq)
        {
            hashVal ^= intHasher(cnt) + 0x9e3779b97f4a7c15ULL + (hashVal << 6) + (hashVal >> 2);
        }

        hashVal ^= intHasher(key.upperCount) + 0x9e3779b97f4a7c15ULL + (hashVal << 6) + (hashVal >> 2);

        return hashVal;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;

        vector<string> plates(n);
        for (int i = 0; i < n; i++)
        {
            cin >> plates[i];
        }

        unordered_map<PlateKey, long long, PlateKeyHash> freqMap;

        for (const auto &plate : plates)
        {
            PlateKey key;
            for (char ch : plate)
            {
                char lower = tolower(ch);
                key.freq[lower - 'a']++;
                if (isupper(ch))
                {
                    key.upperCount++;
                }
            }
            freqMap[key]++;
        }

        long long result = 0;
        for (const auto &entry : freqMap)
        {
            long long count = entry.second;
            if (count > 1)
            {
                result += count * (count - 1) / 2;
            }
        }

        cout << result << "\n";
    }

    return 0;
}