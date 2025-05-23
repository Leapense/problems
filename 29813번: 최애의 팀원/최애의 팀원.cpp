#include <iostream>
#include <deque>
#include <string>

using namespace std;

struct Student
{
    string initial;
    int number;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    deque<Student> dq;

    for (int i = 0; i < N; i++)
    {
        Student s;
        cin >> s.initial >> s.number;
        dq.push_back(s);
    }

    while (dq.size() > 1)
    {
        Student curr = dq.front();
        dq.pop_front();

        int passes = curr.number - 1;
        for (int i = 0; i < passes; i++)
        {
            Student temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }

        dq.pop_front();
    }

    cout << dq.front().initial << "\n";

    return 0;
}