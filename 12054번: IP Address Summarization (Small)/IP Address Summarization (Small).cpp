#include <bits/stdc++.h>
using namespace std;

uint32_t ipToUint(const string &ip) {
    int A, B, C, D;
    sscanf(ip.c_str(), "%d.%d.%d.%d", &A, &B, &C, &D);

    return ((uint32_t)A << 24) | ((uint32_t)B << 16) |
           ((uint32_t)C << 8)  | ((uint32_t)D);
}

string uintToIp(uint32_t ipUint) {
    int A = (ipUint >> 24) & 0xFF;
    int B = (ipUint >> 16) & 0xFF;
    int C = (ipUint >> 8)  & 0xFF;
    int D = ipUint & 0xFF;
    char buf[32];
    sprintf(buf, "%d.%d.%d.%d", A, B, C, D);
    return string(buf);
}

pair<uint32_t, uint32_t> parseSubnet(const string &subnet) {
    auto slashPos = subnet.find('/');
    string ipPart = subnet.substr(0, slashPos);
    int prefix = stoi(subnet.substr(slashPos+1));

    uint32_t ipValue = ipToUint(ipPart);
    uint64_t mask = 0;
    if (prefix == 0) {
        mask = 0x00000000;
    } else {
        mask = 0xFFFFFFFFULL << (32 - prefix);
    }

    uint32_t start = (uint32_t)(ipValue & mask);
    uint64_t size = (prefix == 0) ? (1ULL << 32) : (1ULL << (32 - prefix));
    uint32_t end = start + (uint32_t)(size - 1);

    return { start, end };
}

vector<pair<uint32_t,int>> splitIntoSubnets(uint32_t start, uint32_t end) {
    vector<pair<uint32_t,int>> result; // (ipValue, prefix)
    uint32_t current = start;

    while (current <= end) {
        uint32_t lowestSetBit = current & (- (int32_t)current);
        if (lowestSetBit == 0) {
            lowestSetBit = 1U << 31; 
        }

        uint64_t blockSize = (uint64_t)lowestSetBit;  
        uint64_t remaining = (uint64_t)end - current + 1;

        while (blockSize > remaining) {
            blockSize >>= 1;
        }
        int prefix = 32 - (int)log2((long double)blockSize);
        result.push_back({current, prefix});

        current += (uint32_t)blockSize;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        int N;
        cin >> N;

        vector<pair<uint32_t,uint32_t>> intervals;
        intervals.reserve(N);
        for(int i=0; i<N; i++){
            string subnet;
            cin >> subnet;
            auto range = parseSubnet(subnet);
            intervals.push_back(range);
        }

        sort(intervals.begin(), intervals.end());

        vector<pair<uint32_t,uint32_t>> merged;
        for(auto &iv : intervals){
            if(merged.empty()){
                merged.push_back(iv);
            } else {
                auto &last = merged.back();
                if(iv.first <= last.second + 1){
                    last.second = max(last.second, iv.second);
                } else {
                    merged.push_back(iv);
                }
            }
        }

        vector<pair<uint32_t,int>> finalSubnets; // (startIp, prefix)
        for(auto &m : merged){
            auto subBlocks = splitIntoSubnets(m.first, m.second);
            for(auto &sb : subBlocks){
                finalSubnets.push_back(sb);
            }
        }

        sort(finalSubnets.begin(), finalSubnets.end(), 
             [](auto &a, auto &b){
                 return a.first < b.first; 
             }
        );

        cout << "Case #" << tc << ":\n";
        for(auto &fs : finalSubnets){
            cout << uintToIp(fs.first) << "/" << fs.second << "\n";
        }
    }

    return 0;
}