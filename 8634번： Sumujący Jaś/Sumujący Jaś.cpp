#include <bits/stdc++.h>
using namespace std;

// Function to remove leading zeros, ensure at least one digit
string remove_leading_zeros(const string& s) {
    int i = 0;
    while (i < s.size()-1 && s[i] == '0') i++;
    return s.substr(i);
}

// Function to remove trailing zeros, can result in empty string
string remove_trailing_zeros(const string& s) {
    int i = s.size()-1;
    while (i >=0 && s[i] == '0') i--;
    return s.substr(0, i+1);
}

// Compare two digit strings a and b
// Returns 1 if a > b, 0 if a == b, -1 if a < b
int compare_digits(const string& a, const string& b){
    if(a.size() > b.size()) return 1;
    if(a.size() < b.size()) return -1;
    for(int i=0;i<a.size();i++){
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return -1;
    }
    return 0;
}

// Add two positive digit strings
string add_digits(const string& a, const string& b){
    string result;
    int carry = 0;
    int i = a.size()-1, j = b.size()-1;
    while(i >=0 || j >=0 || carry){
        int digit_a = (i >=0) ? (a[i]-'0') : 0;
        int digit_b = (j >=0) ? (b[j]-'0') : 0;
        int total = digit_a + digit_b + carry;
        carry = total / 10;
        result += (total % 10) + '0';
        i--; j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Subtract two positive digit strings, assuming a >= b
string subtract_digits(const string& a, const string& b){
    string result;
    int borrow = 0;
    int i = a.size()-1, j = b.size()-1;
    while(i >=0){
        int digit_a = a[i]-'0' - borrow;
        int digit_b = (j >=0) ? (b[j]-'0') : 0;
        if(digit_a < digit_b){
            digit_a += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        int current = digit_a - digit_b;
        result += (current + '0');
        i--; j--;
    }
    // Remove leading zeros
    while(result.size() >1 && result.back() == '0') result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}

struct BigInt {
    string digits; // always positive
    bool negative;

    BigInt() : digits("0"), negative(false) {}

    BigInt(string s, bool neg) : digits(s), negative(neg) {
        if(digits.empty()) {
            digits = "0";
            negative = false;
        }
        // Remove leading zeros
        digits = remove_leading_zeros(digits);
        if(digits == "0") negative = false;
    }

    // Add another BigInt to this BigInt
    void add(const BigInt& other){
        if(this->negative == other.negative){
            // Same sign, add digits
            this->digits = add_digits(this->digits, other.digits);
            // Sign remains
        }
        else{
            // Different signs, subtract smaller abs from larger abs
            int cmp = compare_digits(this->digits, other.digits);
            if(cmp == 0){
                // Result is zero
                this->digits = "0";
                this->negative = false;
            }
            else if(cmp > 0){
                // this > other in abs
                this->digits = subtract_digits(this->digits, other.digits);
                // Sign remains
            }
            else{
                // other > this in abs
                this->digits = subtract_digits(other.digits, this->digits);
                this->negative = other.negative;
            }
        }
    }

    // For debugging
    void print() const{
        if(negative) cout << "-";
        cout << digits;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    struct Number {
        bool negative;
        string integer_part;
        string fractional_part;
    };
    vector<Number> numbers(N);
    int max_frac = 0;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        size_t pos = 0;
        // Parse sign
        if(s[0] == '-'){
            numbers[i].negative = true;
            pos = 1;
        }
        else{
            numbers[i].negative = false;
            if(s[0] == '+') pos = 1;
            else pos = 0;
        }
        // Find comma
        size_t comma = s.find(',', pos);
        if(comma == string::npos){
            // No fractional part
            numbers[i].integer_part = s.substr(pos);
            numbers[i].fractional_part = "";
        }
        else{
            numbers[i].integer_part = s.substr(pos, comma - pos);
            numbers[i].fractional_part = s.substr(comma +1);
            max_frac = max(max_frac, (int)numbers[i].fractional_part.size());
        }
    }
    // Now, pad fractional parts to max_frac
    for(int i=0;i<N;i++){
        while(numbers[i].fractional_part.size() < max_frac){
            numbers[i].fractional_part += "0";
        }
    }
    // Convert each number to BigInt
    // Each BigInt represents the number scaled by 10^max_frac
    vector<BigInt> bigNumbers;
    bigNumbers.reserve(N);
    for(int i=0;i<N;i++){
        string combined = numbers[i].integer_part;
        if(max_frac >0){
            combined += numbers[i].fractional_part;
        }
        // Remove leading zeros
        combined = remove_leading_zeros(combined);
        if(combined.empty()) combined = "0";
        bigNumbers.emplace_back(BigInt(combined, numbers[i].negative));
    }
    // Sum all BigInts
    BigInt sum;
    for(int i=0;i<N;i++){
        sum.add(bigNumbers[i]);
    }
    // Now, insert comma at max_frac digits from the end
    string sum_digits = sum.digits;
    bool is_negative = sum.negative;
    if(max_frac ==0){
        // No fractional part
    }
    else{
        // Ensure sum_digits has at least max_frac digits
        while(sum_digits.size() < max_frac){
            sum_digits = "0" + sum_digits;
        }
    }
    string integer_part, fractional_part;
    if(max_frac ==0){
        integer_part = sum_digits;
        fractional_part = "";
    }
    else{
        if(sum_digits.size() <= max_frac){
            integer_part = "0";
            fractional_part = string(max_frac - sum_digits.size(), '0') + sum_digits;
        }
        else{
            integer_part = sum_digits.substr(0, sum_digits.size() - max_frac);
            fractional_part = sum_digits.substr(sum_digits.size() - max_frac);
        }
    }
    // Remove leading zeros from integer_part
    integer_part = remove_leading_zeros(integer_part);
    // Remove trailing zeros from fractional_part
    if(max_frac >0){
        fractional_part = remove_trailing_zeros(fractional_part);
    }
    // Handle zero case
    bool is_zero = (integer_part == "0") && (fractional_part.empty());
    // Build the output
    string output = "";
    if(is_zero){
        output = "0";
    }
    else{
        if(is_negative){
            output += "-";
        }
        output += integer_part;
        if(!fractional_part.empty()){
            output += ",";
            output += fractional_part;
        }
    }
    cout << output;
}