#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    int startPos = pattern.find('*');
    string prefix = pattern.substr(0, startPos);
    string suffix = pattern.substr(startPos + 1);

    for (int i = 0; i < N; i++)
    {
        string fileName;
        cin >> fileName;

        if (fileName.length() < prefix.length() + suffix.length())
        {
            cout << "NE" << endl;
        }
        else
        {
            if (fileName.substr(0, prefix.length()) == prefix && fileName.substr(fileName.length() - suffix.length()) == suffix) {
                cout << "DA" << endl;
            } else {
                cout << "NE" << endl;
            }
        }
    }

    return 0;
}