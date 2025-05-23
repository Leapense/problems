#include <bits/stdc++.h>
using namespace std;

int main(){
    // Read input
    string known_plain;
    string known_cipher;
    string target_cipher;
    getline(cin, known_plain);
    getline(cin, known_cipher);
    getline(cin, target_cipher);
    
    // Initialize mapping and reverse mapping
    unordered_map<char, char> cipher_to_plain;
    unordered_map<char, bool> cipher_mapped;
    unordered_map<char, bool> plain_mapped;
    
    // Set of all possible characters: 'A'-'Z' and ' '
    vector<char> all_chars;
    for(char c='A'; c<='Z'; c++) all_chars.push_back(c);
    all_chars.push_back(' ');
    
    // Populate the mapping from known_plain and known_cipher
    int n = known_plain.size();
    for(int i=0; i<n; i++){
        char c_cipher = known_cipher[i];
        char c_plain = known_plain[i];
        // Assign mapping
        cipher_to_plain[c_cipher] = c_plain;
        cipher_mapped[c_cipher] = true;
        plain_mapped[c_plain] = true;
    }
    
    // Find unmapped ciphertext and plaintext characters
    vector<char> unmapped_cipher;
    vector<char> unmapped_plain;
    for(auto c: all_chars){
        if(cipher_mapped.find(c) == cipher_mapped.end()){
            unmapped_cipher.push_back(c);
        }
        if(plain_mapped.find(c) == plain_mapped.end()){
            unmapped_plain.push_back(c);
        }
    }
    
    // If exactly one unmapped cipher and one unmapped plain, assign
    if(unmapped_cipher.size() == 1 && unmapped_plain.size() == 1){
        cipher_to_plain[unmapped_cipher[0]] = unmapped_plain[0];
        // Not necessary to mark them as mapped since no further use
    }
    
    // Now, map the target_cipher
    string result = "";
    for(auto c: target_cipher){
        if(cipher_to_plain.find(c) != cipher_to_plain.end()){
            result += cipher_to_plain[c];
        }
        else{
            result += '.';
        }
    }
    
    cout << result;
}