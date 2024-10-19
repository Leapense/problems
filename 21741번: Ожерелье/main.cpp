//=====================================================================
//   21741번:    Ожерелье                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/21741  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> necklace(N);
    for(auto &x : necklace) cin >> x;
    vector<pair<int, int>> operations;

    for(int i=0; i<N; ++i){
        int desired = i+1;
        // Find current position of the desired ring
        int pos = -1;
        for(int j=0; j<N; ++j){
            if(necklace[j] == desired){
                pos = j;
                break;
            }
        }
        if(pos == -1){
            cout << -1;
            return 0;
        }
        if(pos == i){
            continue;
        }
        if(i == 0){
            // Move desired to position 0
            // Find a ring B such that |desired - B| >1
            int B = -1;
            for(auto &ring : necklace){
                if(abs(desired - ring) >1){
                    B = ring;
                    break;
                }
            }
            if(B == -1){
                cout << -1;
                return 0;
            }
            // Perform move: move desired through B
            // Remove desired from pos and insert after B
            necklace.erase(necklace.begin() + pos);
            // Find the new position of B
            int posB = -1;
            for(int j=0; j<N-1; ++j){
                if(necklace[j] == B){
                    posB = j;
                    break;
                }
            }
            if(posB == -1){
                cout << -1;
                return 0;
            }
            necklace.insert(necklace.begin() + posB +1, desired);
            operations.emplace_back(desired, B);
        }
        else{
            // Move desired to position i
            int B = necklace[i-1];
            if(abs(desired - B) >1){
                // Perform move: move desired through B
                necklace.erase(necklace.begin() + pos);
                // Find the new position of B
                int posB = -1;
                for(int j=0; j<N-1; ++j){
                    if(necklace[j] == B){
                        posB = j;
                        break;
                    }
                }
                if(posB == -1){
                    cout << -1;
                    return 0;
                }
                necklace.insert(necklace.begin() + posB +1, desired);
                operations.emplace_back(desired, B);
            }
            else{
                // Find another B' such that |desired - B'| >1
                int B_prime = -1;
                for(auto &ring : necklace){
                    if(abs(desired - ring) >1 && ring != B){
                        B_prime = ring;
                        break;
                    }
                }
                if(B_prime == -1){
                    cout << -1;
                    return 0;
                }
                // Move desired through B_prime
                necklace.erase(necklace.begin() + pos);
                // Find the new position of B_prime
                int posB_prime = -1;
                for(int j=0; j<N-1; ++j){
                    if(necklace[j] == B_prime){
                        posB_prime = j;
                        break;
                    }
                }
                if(posB_prime == -1){
                    cout << -1;
                    return 0;
                }
                necklace.insert(necklace.begin() + posB_prime +1, desired);
                operations.emplace_back(desired, B_prime);
                // Now, perform move through B
                // Find the new position of desired
                pos = -1;
                for(int j=0; j<N; ++j){
                    if(necklace[j] == desired){
                        pos = j;
                        break;
                    }
                }
                if(pos == -1){
                    cout << -1;
                    return 0;
                }
                necklace.erase(necklace.begin() + pos);
                // Find the position of B
                int posB_new = -1;
                for(int j=0; j<N-1; ++j){
                    if(necklace[j] == B){
                        posB_new = j;
                        break;
                    }
                }
                if(posB_new == -1){
                    cout << -1;
                    return 0;
                }
                necklace.insert(necklace.begin() + posB_new +1, desired);
                operations.emplace_back(desired, B);
            }
        }
        if(operations.size() > 50000){
            cout << -1;
            return 0;
        }
    }
    // Check if the necklace is sorted in some rotation
    bool sorted_flag = false;
    for(int shift=0; shift<N; ++shift){
        bool ok = true;
        for(int i=0; i<N; ++i){
            if(necklace[(shift + i)%N] != i+1){
                ok = false;
                break;
            }
        }
        if(ok){
            sorted_flag = true;
            break;
        }
    }
    if(!sorted_flag){
        cout << -1;
        return 0;
    }
    for(auto &[a, b] : operations){
        cout << a << " " << b << "\n";
    }
    cout << "0";
}
