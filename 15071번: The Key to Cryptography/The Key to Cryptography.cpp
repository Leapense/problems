#include <iostream>
#include <string>

using namespace std;

int main()
{
    string cipher, key;
    cin >> cipher >> key;
    string message = "";

    for (int i = 0; i < cipher.size(); i++)
    {
        int shift = key[i] - 'A';
        int plain = (cipher[i] - 'A' - shift + 26) % 26;
        char ch = plain + 'A';
        message.push_back(ch);
        key.push_back(ch);
    }

    cout << message << "\n";
    return 0;
}