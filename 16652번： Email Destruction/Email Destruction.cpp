#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cin.ignore();

    unordered_map<string, int> chainMax;

    for (int i = 0; i < k; i++)
    {
        string subject;
        getline(cin, subject);

        int countRe = 0;

        const string prefix = "Re: ";
        while (subject.rfind(prefix, 0) == 0)
        {
            countRe++;
            subject = subject.substr(prefix.size());
        }

        if (chainMax.find(subject) == chainMax.end())
        {
            chainMax[subject] = countRe;
        }
        else
        {
            chainMax[subject] = max(chainMax[subject], countRe);
        }
    }

    int minEmails = 0;
    for (const auto &[base, maxCount] : chainMax)
    {
        minEmails += (maxCount + 1);
    }

    cout << (minEmails <= n ? "YES" : "NO") << "\n";

    return 0;
}