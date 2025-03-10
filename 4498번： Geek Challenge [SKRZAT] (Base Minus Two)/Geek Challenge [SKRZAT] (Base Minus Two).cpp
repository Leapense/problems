#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long binaryToDecimal(string binary)
{
    long long decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(-2, power);
        }
        power++;
    }
    return decimal;
}

string decimalToBinary(long long decimal)
{
    if (decimal == 0)
    {
        return "0";
    }
    string binary = "";
    while (decimal != 0)
    {
        int remainder = decimal % -2;
        decimal /= -2;
        if (remainder < 0)
        {
            remainder += 2;
            decimal += 1;
        }
        binary += (remainder + '0');
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        char type = line[0];
        string number = line.substr(2);
        if (type == 'b')
        {
            long long result = binaryToDecimal(number);
            cout << "From binary: " << number << " is " << result << endl;
        }
        else if (type == 'd')
        {
            long long decimal = stoll(number);
            string result = decimalToBinary(decimal);
            cout << "From decimal: " << decimal << " is " << result << endl;
        }
    }
    return 0;
}