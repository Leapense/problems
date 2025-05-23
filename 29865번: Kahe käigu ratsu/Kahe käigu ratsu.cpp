#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// 체스판 범위 검사 함수
bool isValid(int col, int row)
{
    return (col >= 0 && col < 8 && row >= 0 && row < 8);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string start;
    cin >> start;

    // 입력받은 좌표를 (col, row) 좌표로 변환
    // 'a'~'h' -> 0~7, '1'~'8' -> 0~7
    int startCol = start[0] - 'a';
    int startRow = start[1] - '1';

    // 나이트가 이동할 수 있는 8가지 방향
    vector<pair<int, int>> moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    // 두 번 이동 후 도달 가능한 좌표를 저장할 집합
    set<string> positions;

    // 첫 번째 이동
    for (auto move1 : moves)
    {
        int col1 = startCol + move1.first;
        int row1 = startRow + move1.second;
        if (!isValid(col1, row1))
            continue;

        // 두 번째 이동 (첫 번째 이동에서 구한 좌표에서)
        for (auto move2 : moves)
        {
            int col2 = col1 + move2.first;
            int row2 = row1 + move2.second;
            if (!isValid(col2, row2))
                continue;

            // 체스 좌표 형식으로 변환 (예: 0->'a', 0->'1')
            string pos = "";
            pos.push_back('a' + col2);
            pos.push_back('1' + row2);
            positions.insert(pos);
        }
    }

    // 결과 출력 (출력 순서는 상관없음)
    for (auto pos : positions)
    {
        cout << pos << "\n";
    }

    return 0;
}