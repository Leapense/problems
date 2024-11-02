#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // k장의 카드를 뒤집고 이동
    for (int i = 0; i < k; ++i) {
        cout << "Reverse" << endl;
        cout.flush();

        cout << "Move" << endl;
        cout.flush();

        int face_down_count;
        cin >> face_down_count; // 반환값은 사용하지 않음
    }

    // 작업 완료
    cout << "Finish" << endl;
    cout.flush();

    return 0;
}