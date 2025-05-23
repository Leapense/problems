#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); // To ignore the newline after the integer input

    std::string output; // To store the final output
    for (int i = 0; i < N; ++i) {
        std::string line;
        std::getline(std::cin, line); // Read the entire line

        // Extract the text inside the quotes
        size_t start = line.find('"') + 1; // Find first quote
        size_t end = line.rfind('"'); // Find last quote

        if (start < end) {
            std::string text = line.substr(start, end - start); // Get the text inside quotes

            // Process the text to handle the newline instructions
            for (size_t j = 0; j < text.length(); ++j) {
                if (text[j] == '\\' && j + 1 < text.length() && text[j + 1] == 'n') {
                    // If we find a \n sequence, we add a newline character to output
                    output += '\n';
                    j++; // Skip the 'n' character
                } else {
                    // Otherwise, add the current character to output
                    output += text[j];
                }
            }
        }
    }

    std::cout << output; // Print the final output
    return 0;
}
