#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int length;
    bool isLarge;
    bool isBright;
};

bool isVowel(char c){
    char lower = tolower(c);
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u' || lower == 'y';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int len = s.length();
        if(len == 0){
            // 빈 목걸이는 처리하지 않음
            cout << "0 jasne\n0 jasne\n";
            continue;
        }
        // 벡터에 세그먼트 저장
        vector<Segment> segments;
        // 초기 세그먼트 설정
        Segment current;
        current.length = 1;
        current.isLarge = isupper(s[0]);
        current.isBright = isVowel(s[0]);
        // 순회 시작
        for(int i=1;i<len;i++){
            bool size = isupper(s[i]);
            bool bright = isVowel(s[i]);
            if(size == current.isLarge && bright == current.isBright){
                current.length++;
            }
            else{
                segments.push_back(current);
                current.length = 1;
                current.isLarge = size;
                current.isBright = bright;
            }
        }
        // 마지막 세그먼트 추가
        segments.push_back(current);
        // 원형 연결: 첫 세그먼트와 마지막 세그먼트가 동일하면 합침
        if(segments.size() > 1 && segments[0].isLarge == segments.back().isLarge && segments[0].isBright == segments.back().isBright){
            segments[0].length += segments.back().length;
            segments.pop_back();
        }
        // 이제 segments에는 모든 세그먼트가 저장됨
        // 최장과 최단 세그먼트 찾기
        // 초기값 설정
        Segment longest = segments[0];
        Segment shortest = segments[0];
        for(auto &seg: segments){
            // 최장 세그먼트 찾기
            if(seg.length > longest.length){
                longest = seg;
            }
            else if(seg.length == longest.length){
                // 우선순위 비교
                if(seg.isLarge > longest.isLarge){
                    longest = seg;
                }
                else if(seg.isLarge == longest.isLarge){
                    if(seg.isBright > longest.isBright){
                        longest = seg;
                    }
                }
            }
            // 최단 세그먼트 찾기
            if(seg.length < shortest.length){
                shortest = seg;
            }
            else if(seg.length == shortest.length){
                // 우선순위 비교
                if(seg.isLarge > shortest.isLarge){
                    shortest = seg;
                }
                else if(seg.isLarge == shortest.isLarge){
                    if(seg.isBright > shortest.isBright){
                        shortest = seg;
                    }
                }
            }
        }
        // 세그먼트 유형 문자열 생성
        auto getType = [&](Segment seg) -> string {
            string type = "";
            if(seg.isBright){
                type += "jasne";
            }
            else{
                type += "ciemne";
            }
            if(seg.isLarge){
                // 대문자일 때 대문자으로 변경
                for(auto &c:type){
                    if(c >= 'a' && c <= 'z') c = c - 'a' + 'A';
                }
            }
            return type;
        };
        // 최장 세그먼트 출력
        cout << longest.length << ' ' << getType(longest) << '\n';
        // 최단 세그먼트 출력
        cout << shortest.length << ' ' << getType(shortest) << '\n';
    }
}