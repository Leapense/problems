#include <bits/stdc++.h>
using namespace std;

/**
 * IP 주소(A.B.C.D)를 32비트 정수로 변환한다.
 * 예) 10.0.0.1 -> 0x0A000001
 */
uint32_t ipToUint(const string &ip) {
    // A.B.C.D
    int A, B, C, D;
    sscanf(ip.c_str(), "%d.%d.%d.%d", &A, &B, &C, &D);
    // 32비트 정수로 변환(상위 8비트부터 A, B, C, D 순으로).
    // (A << 24) | (B << 16) | (C << 8) | D
    return ((uint32_t)A << 24) | ((uint32_t)B << 16) |
           ((uint32_t)C << 8)  | ((uint32_t)D);
}

/**
 * 32비트 정수를 다시 A.B.C.D 문자열로 변환한다.
 */
string uintToIp(uint32_t ipUint) {
    // 상위 8비트부터 A, B, C, D 순으로 추출
    int A = (ipUint >> 24) & 0xFF;
    int B = (ipUint >> 16) & 0xFF;
    int C = (ipUint >> 8)  & 0xFF;
    int D = ipUint & 0xFF;
    char buf[32];
    sprintf(buf, "%d.%d.%d.%d", A, B, C, D);
    return string(buf);
}

/**
 * 주어진 서브넷 A.B.C.D/P를
 * [start, end] (포함 구간) 형태로 변환한다.
 *  - start는 P 비트 뒤를 0으로 세팅(정규화)
 *  - end = start + (2^(32-P) - 1)
 */
pair<uint32_t, uint32_t> parseSubnet(const string &subnet) {
    // "A.B.C.D/P" 형태에서 P 분리
    // 서브넷 부분 잘라내기
    auto slashPos = subnet.find('/');
    string ipPart = subnet.substr(0, slashPos);
    int prefix = stoi(subnet.substr(slashPos+1));

    // IP -> 32비트
    uint32_t ipValue = ipToUint(ipPart);

    // prefix가 0이면 전체 주소를 다 커버, start=0, end=최대
    // prefix가 32이면 단일 주소
    // prefix가 그 사이면 뒤 (32 - prefix)비트만큼 mask
    // 예) prefix=8 -> (0xFF000000)만 남기고 나머지 0
    //     즉, ipValue & (mask) 수행.
    // mask = 0xFFFFFFFF << (32 - prefix), 단 prefix=0일 때 예외 처리
    uint64_t mask = 0;
    if (prefix == 0) {
        // 어떤 비트도 고정 안 함 (start=0, end=0xFFFFFFFF)
        mask = 0x00000000;
    } else {
        mask = 0xFFFFFFFFULL << (32 - prefix);
    }

    uint32_t start = (uint32_t)(ipValue & mask);
    // end = start + (2^(32 - prefix) - 1)
    // prefix=0이면 2^32 - 1 = 4294967295
    uint64_t size = (prefix == 0) ? (1ULL << 32) : (1ULL << (32 - prefix));
    uint32_t end = start + (uint32_t)(size - 1);

    return { start, end };
}

/**
 * [start, end] 구간을 IP 주소 블록(A.B.C.D/P)의 목록으로 쪼갠다.
 * 예) [start, end]에서 start부터 가능한 가장 큰 2^k 블록을 취하며 진행
 */
vector<pair<uint32_t,int>> splitIntoSubnets(uint32_t start, uint32_t end) {
    vector<pair<uint32_t,int>> result; // (ipValue, prefix)
    uint32_t current = start;

    while (current <= end) {
        // 남은 범위: [current, end]
        // 1) current가 몇 비트까지 0으로 끝나는지(lowest set bit 위치) 확인
        // 2) 남은 구간 크기에 비해 너무 큰 블록이면 조정

        // current의 lowest set bit 찾기
        // ex) current=0b10100000... 이면 LSB=5번째
        // 즉 blockSize = 2^lsb
        uint32_t lowestSetBit = current & (- (int32_t)current);
        // 만약 current=0이면 lowestSetBit=0 이므로 특수 처리
        if (lowestSetBit == 0) {
            lowestSetBit = 1U << 31; 
            // 최악의 경우(0일때)는 최대 블록으로 가정
            // (사실상 current=0이면 2^32 블록도 가능하나,
            //  어차피 뒤에서 end와 비교해 줄어들 것)
        }

        // 이 블록의 prefix = 32 - log2(blockSize)
        // blockSize = lowestSetBit
        // 그러나 end - current + 1 개보다 커지면 안 되므로 줄여야 함
        uint64_t blockSize = (uint64_t)lowestSetBit;  
        // 남은 공간
        uint64_t remaining = (uint64_t)end - current + 1;

        // blockSize가 remaining보다 크면 smaller로
        while (blockSize > remaining) {
            blockSize >>= 1;
        }

        // prefix 계산 (blockSize = 2^(32 - prefix))
        // => prefix = 32 - log2(blockSize)
        int prefix = 32 - (int)log2((long double)blockSize);

        // 결과 추가
        result.push_back({current, prefix});

        // current 갱신
        current += (uint32_t)blockSize;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 테스트 케이스 수
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        int N; // 서브넷 개수
        cin >> N;

        // 모든 subnet을 [start, end] 형태로 저장
        vector<pair<uint32_t,uint32_t>> intervals;
        intervals.reserve(N);
        for(int i=0; i<N; i++){
            string subnet;
            cin >> subnet;
            auto range = parseSubnet(subnet);
            intervals.push_back(range);
        }

        // 1) start 기준 오름차순 정렬
        sort(intervals.begin(), intervals.end());

        // 2) 인터벌 병합(겹치거나 붙어있으면 병합)
        vector<pair<uint32_t,uint32_t>> merged;
        for(auto &iv : intervals){
            if(merged.empty()){
                merged.push_back(iv);
            } else {
                auto &last = merged.back();
                // 현재 iv가 last와 겹치거나 바로 붙어 있으면 병합
                if(iv.first <= last.second + 1){
                    // 병합 구간의 끝을 더 큰 쪽으로
                    last.second = max(last.second, iv.second);
                } else {
                    // 아니면 새 구간
                    merged.push_back(iv);
                }
            }
        }

        // 3) 병합된 구간들을 다시 서브넷 목록으로 쪼개기
        vector<pair<uint32_t,int>> finalSubnets; // (startIp, prefix)
        for(auto &m : merged){
            auto subBlocks = splitIntoSubnets(m.first, m.second);
            // subBlocks를 finalSubnets에 이어 붙이기
            for(auto &sb : subBlocks){
                finalSubnets.push_back(sb);
            }
        }

        // 4) 문제에서 요구하는 오름차순(A.B.C.D) 정렬
        //    => 32비트 주소가 오름차순이면 A.B.C.D도 오름차순
        sort(finalSubnets.begin(), finalSubnets.end(), 
             [](auto &a, auto &b){
                 return a.first < b.first; 
             }
        );

        // 출력
        cout << "Case #" << tc << ":\n";
        for(auto &fs : finalSubnets){
            // fs.first -> IP, fs.second -> prefix
            cout << uintToIp(fs.first) << "/" << fs.second << "\n";
        }
    }

    return 0;
}