//=====================================================================
//   23391번:    Escalator                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/23391  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> people(N); // {arrival time, direction}
    
    for (int i = 0; i < N; i++) {
        cin >> people[i].first >> people[i].second;
    }

    int current_time = 0;            // Current time of the escalator
    int last_direction = -1;         // -1 means escalator is stopped initially
    int last_time_leave = 0;         // Time when the last person leaves the escalator
    
    for (int i = 0; i < N; i++) {
        int arrival_time = people[i].first;
        int direction = people[i].second;
        
        // If escalator is stopped or moving in the desired direction
        if (last_direction == -1 || last_direction == direction) {
            // If the escalator is stopped or moving in the right direction
            if (arrival_time > current_time) {
                current_time = arrival_time;  // Person can get on immediately
            }
        } else {
            // If the escalator is moving in the opposite direction
            if (current_time + 10 > arrival_time) {
                // Person has to wait until the escalator stops
                current_time += 10;  // It takes 10 seconds for the escalator to stop and change direction
            } else {
                // Escalator already stopped when they arrived
                current_time = arrival_time;
            }
        }

        // The person now boards the escalator at current_time and finishes at current_time + 10
        last_time_leave = current_time + 10;
        current_time = last_time_leave;  // Update current time to when they leave
        last_direction = direction;      // Update the escalator's direction
    }

    // Output the last time the escalator stops
    cout << last_time_leave << endl;

    return 0;
}
