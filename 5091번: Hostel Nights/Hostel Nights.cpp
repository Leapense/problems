#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Student {
    int room;
    string name;
    int count;
};

int main() {
    int W;
    cin >> W;
    for (int week = 1; week <= W; ++week) {
        vector<Student> students(20);
        for (int i = 0; i < 20; ++i) {
            cin >> students[i].room >> students[i].name;
            students[i].count = 0;
        }
        vector<char> elim1(5);
        vector<int> elim2(5);
        vector<char> elim3(5);
        for (int i = 0; i < 5; ++i) {
            cin >> elim1[i] >> elim2[i] >> elim3[i];
        }
        for (int night = 0; night < 5; ++night) {
            for (auto& student : students) {
                bool eliminated = false;
                // Criterion 1: Even or Odd room elimination
                if (elim1[night] == 'E' && student.room % 2 == 0) {
                    eliminated = true;
                } else if (elim1[night] == 'O' && student.room % 2 == 1) {
                    eliminated = true;
                }
                // Criterion 2: Multiple of n elimination
                if (student.room % elim2[night] == 0) {
                    eliminated = true;
                }
                // Criterion 3: Name starts with letter elimination
                if (student.name[0] == elim3[night]) {
                    eliminated = true;
                }
                if (!eliminated) {
                    student.count++;
                }
            }
        }
        // Find the maximum count
        int max_count = 0;
        for (auto& student : students) {
            if (student.count > max_count) {
                max_count = student.count;
            }
        }
        // Collect students with maximum count
        vector<Student> result;
        for (auto& student : students) {
            if (student.count == max_count) {
                result.push_back(student);
            }
        }
        // Sort the result by room number
        sort(result.begin(), result.end(), [](const Student& a, const Student& b) {
            return a.room < b.room;
        });
        // Output
        cout << "Week " << week << endl;
        for (auto& student : result) {
            cout << student.name << endl;
        }
    }
    return 0;
}