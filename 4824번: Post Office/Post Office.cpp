#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isBetween(double value, double min, double max) {
    return min <= value && value <= max;
}

int main() {
    double a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        // Identify dimensions: length is the largest, height is the middle, thickness is the smallest
        double dimensions[] = {a, b, c};
        sort(dimensions, dimensions + 3);
        double thickness = dimensions[0];
        double height = dimensions[1];
        double length = dimensions[2];

        // Check if it is a letter
        if (isBetween(length, 125, 290) && isBetween(height, 90, 155) && isBetween(thickness, 0.25, 7)) {
            cout << "letter" << endl;
            continue;
        }

        // Check if it is a packet
        bool packet_minimum_conditions = length >= 125 && height >= 90 && thickness >= 0.25;
        bool packet_exceeds_letter_max = length > 290 || height > 155 || thickness > 7;
        bool packet_max_conditions = length <= 380 && height <= 300 && thickness <= 50;

        if (packet_minimum_conditions && packet_exceeds_letter_max && packet_max_conditions) {
            cout << "packet" << endl;
            continue;
        }

        // Check if it is a parcel
        bool parcel_minimum_conditions = length >= 125 && height >= 90 && thickness >= 0.25;
        bool parcel_exceeds_packet_max = length > 380 || height > 300 || thickness > 50;
        double girth = 2 * (height + thickness);
        bool parcel_max_girth = length + girth <= 2100;

        if (parcel_minimum_conditions && parcel_exceeds_packet_max && parcel_max_girth) {
            cout << "parcel" << endl;
            continue;
        }

        // Not mailable
        cout << "not mailable" << endl;
    }

    return 0;
}