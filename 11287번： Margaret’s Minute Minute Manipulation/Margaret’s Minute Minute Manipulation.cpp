#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to convert a binary vector column to its decimal equivalent
int binaryToDecimal(const vector<int>& col) {
    int decimal = 0;
    for (int i = 0; i < 4; i++) {
        decimal += col[i] * pow(2, 3 - i);
    }
    return decimal;
}

// Function to convert a decimal digit to a binary column
vector<int> decimalToBinary(int value) {
    vector<int> binary(4, 0);
    for (int i = 3; i >= 0; i--) {
        binary[i] = value % 2;
        value /= 2;
    }
    return binary;
}

// Function to add time with overflow management
void addTime(int &hh, int &mm, int &ss, int delta_hh, int delta_mm, int delta_ss) {
    ss += delta_ss;
    mm += delta_mm + ss / 60;
    hh += delta_hh + mm / 60;

    ss %= 60;
    mm %= 60;
    hh %= 24;
}

int main() {
    vector<vector<int>> timeMatrix(4, vector<int>(6));
    vector<vector<int>> deltaMatrix(4, vector<int>(6));

    // Reading current time matrix
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> timeMatrix[i][j];

    // Reading delta time matrix
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> deltaMatrix[i][j];

    // Extracting current time in decimal
    int hh = binaryToDecimal({timeMatrix[0][0], timeMatrix[1][0], timeMatrix[2][0], timeMatrix[3][0]}) * 10 +
             binaryToDecimal({timeMatrix[0][1], timeMatrix[1][1], timeMatrix[2][1], timeMatrix[3][1]});
    int mm = binaryToDecimal({timeMatrix[0][2], timeMatrix[1][2], timeMatrix[2][2], timeMatrix[3][2]}) * 10 +
             binaryToDecimal({timeMatrix[0][3], timeMatrix[1][3], timeMatrix[2][3], timeMatrix[3][3]});
    int ss = binaryToDecimal({timeMatrix[0][4], timeMatrix[1][4], timeMatrix[2][4], timeMatrix[3][4]}) * 10 +
             binaryToDecimal({timeMatrix[0][5], timeMatrix[1][5], timeMatrix[2][5], timeMatrix[3][5]});

    // Extracting delta time in decimal
    int delta_hh = binaryToDecimal({deltaMatrix[0][0], deltaMatrix[1][0], deltaMatrix[2][0], deltaMatrix[3][0]}) * 10 +
                   binaryToDecimal({deltaMatrix[0][1], deltaMatrix[1][1], deltaMatrix[2][1], deltaMatrix[3][1]});
    int delta_mm = binaryToDecimal({deltaMatrix[0][2], deltaMatrix[1][2], deltaMatrix[2][2], deltaMatrix[3][2]}) * 10 +
                   binaryToDecimal({deltaMatrix[0][3], deltaMatrix[1][3], deltaMatrix[2][3], deltaMatrix[3][3]});
    int delta_ss = binaryToDecimal({deltaMatrix[0][4], deltaMatrix[1][4], deltaMatrix[2][4], deltaMatrix[3][4]}) * 10 +
                   binaryToDecimal({deltaMatrix[0][5], deltaMatrix[1][5], deltaMatrix[2][5], deltaMatrix[3][5]});

    // Adding delta to the current time
    addTime(hh, mm, ss, delta_hh, delta_mm, delta_ss);

    // Convert result back to binary format
    vector<int> hh1 = decimalToBinary(hh / 10);
    vector<int> hh2 = decimalToBinary(hh % 10);
    vector<int> mm1 = decimalToBinary(mm / 10);
    vector<int> mm2 = decimalToBinary(mm % 10);
    vector<int> ss1 = decimalToBinary(ss / 10);
    vector<int> ss2 = decimalToBinary(ss % 10);

    // Printing the resulting time matrix
    for (int i = 0; i < 4; ++i) {
        cout << hh1[i] << " " << hh2[i] << " " << mm1[i] << " " << mm2[i] << " " << ss1[i] << " " << ss2[i] << endl;
    }

    return 0;
}
