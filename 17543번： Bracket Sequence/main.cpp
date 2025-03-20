#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

constexpr long long MOD = 1'000'000'007;

enum class Operation
{
    ADD,
    MUL
};

struct Frame
{
    Operation op;
    long long value;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<Frame> st;

    Frame current = {Operation::ADD, 0};

    for (int i = 0; i < n; i++)
    {
        string token;
        cin >> token;

        if (token == "(")
        {
            st.push(current);
            Operation newOp = (current.op == Operation::ADD ? Operation::MUL : Operation::ADD);

            long long init = (newOp == Operation::ADD ? 0 : 1);
            current = {newOp, init};
        }
        else if (token == ")")
        {
            long long groupVal = current.value;
            current = st.top();
            st.pop();

            if (current.op == Operation::ADD)
            {
                current.value = (current.value + groupVal) % MOD;
            }
            else
            {
                current.value = (current.value * groupVal) % MOD;
            }
        }
        else
        {
            long long num = stoll(token);
            if (current.op == Operation::ADD)
            {
                current.value = (current.value + num) % MOD;
            }
            else
            {
                current.value = (current.value * num) % MOD;
            }
        }
    }

    cout << current.value << "\n";
    return 0;
}