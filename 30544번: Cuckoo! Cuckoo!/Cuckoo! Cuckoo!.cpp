#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string time_str;
    int N;
    std::cin >> time_str >> N;

    int HH = std::stoi(time_str.substr(0, 2));
    int MM = std::stoi(time_str.substr(3, 2));
    
    int total_minutes = HH * 60 + MM;
    int count = 0;
    
    // Initial sound count if starting exactly at a cuckoo time
    if (MM % 15 == 0) {
        if (MM == 0) {
            count += HH == 12 ? 12 : HH;  // Full hour sound
        } else {
            count += 1;  // Quarter, half, or three-quarter hour sound
        }
    }
    
    while (count < N) {
        // Determine next cuckoo time
        if (MM < 15) {
            MM = 15;
        } else if (MM < 30) {
            MM = 30;
        } else if (MM < 45) {
            MM = 45;
        } else if (MM < 60) {
            MM = 0;
            HH = HH % 12 + 1;
        }

        // Add cuckoo sounds
        if (MM == 0) {
            int times = (HH == 12 ? 12 : HH);
            if (count + times > N) break;  // Prevent over-counting
            count += times;
        } else {
            if (count + 1 > N) break;  // Prevent over-counting
            count += 1;
        }

        // Adjust total minutes
        total_minutes = HH * 60 + MM;
    }
    
    std::cout << std::setw(2) << std::setfill('0') << HH << ":";
    std::cout << std::setw(2) << std::setfill('0') << MM << std::endl;
    
    return 0;
}
