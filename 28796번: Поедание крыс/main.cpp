//=====================================================================
//   28796번:    Поедание крыс                   
//   @date:   2024-11-03              
//   @link:   https://www.acmicpc.net/problem/28796  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Reading input
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Initializing variables to track the sums eaten by Kratos and Atreus
    int kratos_sum = 0, atreus_sum = 0;
    int max_lead = 0;

    // Traverse through the protocol and simulate the process
    for (int i = 0; i < n; ++i) {
        // Assign the current step alternately to Kratos or Atreus for simulation
        if (i % 2 == 0) {
            kratos_sum += a[i];
        } else {
            atreus_sum += a[i];
        }

        // Calculate the current lead of Kratos
        int current_lead = kratos_sum - atreus_sum;

        // Update the maximum lead if Kratos is in the lead and lead is higher
        if (current_lead > max_lead) {
            max_lead = current_lead;
        }
    }

    // Output the result: the maximum lead Kratos had
    cout << max_lead << endl;

    return 0;
}