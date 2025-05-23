#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isOpening(const string &s, int i)
{
    return s[i] == '<' && s[i + 1] == '<';
}

bool isClosing(const string &s, int i)
{
    return s[i] == '>' && s[i + 1] == '>';
}

int main()
{
    string s;
    cin >> s;

    stack<int> st;
    vector<char> res(s.size(), ' ');

    for (size_t i = 0; i < s.size(); i += 2)
    {
        if (isOpening(s, i))
        {
            st.push(i);
        }
        else if (isClosing(s, i))
        {
            if (!st.empty() && isOpening(s, st.top()))
            {
                res[st.top()] = '[';
                res[i] = ']';
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        else
        {
            cout << "Keine Loesung";
            return 0;
        }
    }

    stack<int> rev;
    while (!st.empty())
    {
        int idx = st.top();
        st.pop();
        if (!rev.empty() && ((isOpening(s, idx) && isClosing(s, rev.top())) || (isClosing(s, idx) && isOpening(s, rev.top()))))
        {
            res[idx] = '[';
            res[rev.top()] = ']';
            rev.pop();
        }
        else
        {
            rev.push(idx);
        }
    }

    if (!rev.empty())
    {
        cout << "Keine Loesung";
        return 0;
    }

    for (char c : res)
        if (c != ' ')
            cout << c;

    return 0;
}
