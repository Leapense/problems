#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore(); // 개행 문자 제거

    vector<string> records;             // 모든 입력 기록
    vector<string> studyRecords;        // 일반 학습 기록
    vector<pair<int, string>> bojLinks; // 백준 문제 링크: (문제 번호, 원본 문자열)

    // 입력 기록 읽기
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        records.push_back(line);
    }

    // 각 기록을 분류: 백준 링크 여부 판별
    for (const auto &record : records)
    {
        // 만약 record가 "boj.kr/"로 시작하면 백준 문제 링크로 처리
        if (record.size() >= 7 && record.substr(0, 7) == "boj.kr/")
        {
            // "boj.kr/" 뒤에 있는 숫자 문자열을 정수로 변환
            string numStr = record.substr(7);
            int num = stoi(numStr);
            bojLinks.push_back({num, record});
        }
        else
        {
            studyRecords.push_back(record);
        }
    }

    // 일반 학습 기록 정렬:
    // 1. 문자열 길이 오름차순, 2. 길이가 같으면 사전 순(아스키 코드 순)
    sort(studyRecords.begin(), studyRecords.end(), [](const string &a, const string &b)
         {
        if(a.size() == b.size())
            return a < b;
        return a.size() < b.size(); });

    // 백준 문제 링크 정렬: 문제 번호 오름차순
    sort(bojLinks.begin(), bojLinks.end(), [](const pair<int, string> &a, const pair<int, string> &b)
         { return a.first < b.first; });

    // 출력: 먼저 일반 학습 기록, 그 다음 백준 문제 링크
    for (const auto &s : studyRecords)
        cout << s << "\n";
    for (const auto &p : bojLinks)
        cout << p.second << "\n";

    return 0;
}