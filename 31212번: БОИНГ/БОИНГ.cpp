#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Number of sold tickets
    int n;
    cin >> n;

    // Reserved seat
    string reserved;
    cin >> reserved;

    // Map seat row and column based on plane seating
    vector<vector<string>> seats = {
        {"1D", "1E", "1F"},                  // Row 1
        {"2A", "2B", "2C", "2D", "2E", "2F"},// Row 2
        {"3A", "3B", "3C", "3D", "3E", "3F"},// Row 3
        {"4A", "4B", "4C", "4D", "4E", "4F"},// Row 4
        {"5A", "5B", "5C", "5D", "5E", "5F"},// Row 5
        {"6A", "6B", "6C", "6D", "6E", "6F"},// Row 6
        {"7A", "7B", "7C", "7D", "7E", "7F"},// Row 7
        {"8A", "8B", "8C", "8D", "8E", "8F"},// Row 8
        {"9A", "9B", "9C", "9D", "9E", "9F"},// Row 9
        {"10A", "10B", "10C", "10D", "10E", "10F"}, // Row 10
        {"11A", "11B", "11C", "11D", "11E", "11F"}, // Row 11
        {"12A", "12B", "12C", "12D", "12E", "12F"}, // Row 12
        {"13A", "13B", "13C", "13D", "13E", "13F"}, // Row 13
        {"14A", "14B", "14C", "14D", "14E", "14F"}, // Row 14
        {"15A", "15B", "15C", "15D", "15E", "15F"}, // Row 15
        {"16A", "16B", "16C", "16D", "16E", "16F"}, // Row 16
        {"17A", "17B", "17C", "17D", "17E", "17F"}, // Row 17
        {"18A", "18B", "18C", "18D", "18E", "18F"}, // Row 18
        {"19A", "19B", "19C", "19D", "19E", "19F"}, // Row 19
        {"20A", "20B", "20C", "20D", "20E", "20F"}, // Row 20
        {"21D", "21E"} // Row 21
    };

    int totalSeats = 118;
    int reservedIndex = -1;

    // Find the index of the reserved seat
    int seatCounter = 0;
    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {
            if (seats[i][j] == reserved) {
                reservedIndex = seatCounter;
                break;
            }
            seatCounter++;
        }
    }

    // Count forward through the seats
    int seatIndex = 0;
    seatCounter = 0;
    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {
            if (seatCounter != reservedIndex) {
                if (seatIndex == n) {
                    cout << seats[i][j] << endl;
                    return 0;
                }
                seatIndex++;
            }
            seatCounter++;
        }
    }

    cout << "full" << endl;
    return 0;
}
