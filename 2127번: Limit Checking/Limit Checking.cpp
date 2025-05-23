#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct CustomerLimits {
    double iatMaxInstruction;
    double iatDailyLimit;
    double paymentMaxInstruction;
    double paymentDailyLimit;
};

struct DailyRecord {
    double iatTotal = 0.0;
    double paymentTotal = 0.0;
};

int main() {
    map<string, CustomerLimits> customerLimits;
    map<string, string> accountOwners; // Maps account number to owner's name
    map<string, map<string, DailyRecord>> dailyTransactions;
    string line;
    int instructionCount = 0;

    while (getline(cin, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens[0] == "1") {
            CustomerLimits limits;
            limits.iatMaxInstruction = stod(tokens[2]);
            limits.iatDailyLimit = stod(tokens[3]);
            limits.paymentMaxInstruction = stod(tokens[4]);
            limits.paymentDailyLimit = stod(tokens[5]);
            customerLimits[tokens[1]] = limits;
        } else if (tokens[0] == "2") {
            accountOwners[tokens[2]] = tokens[1];
        } else if (tokens[0] == "5") {
            instructionCount++;
            string date = tokens[1].substr(0, 8);
            string customer = tokens[2];
            string sourceAccount = tokens[3];
            double amount = stod(tokens[4]);
            string destAccount = tokens[5];

            if (accountOwners[sourceAccount] != customer) {
                cout << "INSTRUCTION " << instructionCount << ": NOT OWNER\n";
                continue;
            }

            bool isIAT = (accountOwners[sourceAccount] == accountOwners[destAccount]);
            CustomerLimits& limits = customerLimits[customer];
            DailyRecord& dailyRecord = dailyTransactions[date][customer];

            if (isIAT) {
                if (amount > limits.iatMaxInstruction) {
                    cout << "INSTRUCTION " << instructionCount << ": IAT MAX EXCEEDED\n";
                    continue;
                }
                if (dailyRecord.iatTotal + amount > limits.iatDailyLimit) {
                    cout << "INSTRUCTION " << instructionCount << ": IAT DEL EXCEEDED\n";
                    continue;
                }
                dailyRecord.iatTotal += amount;
                cout << "INSTRUCTION " << instructionCount << ": IAT OK\n";
            } else {
                if (amount > limits.paymentMaxInstruction) {
                    cout << "INSTRUCTION " << instructionCount << ": PAYMENT MAX EXCEEDED\n";
                    continue;
                }
                if (dailyRecord.paymentTotal + amount > limits.paymentDailyLimit) {
                    cout << "INSTRUCTION " << instructionCount << ": PAYMENT DEL EXCEEDED\n";
                    continue;
                }
                dailyRecord.paymentTotal += amount;
                cout << "INSTRUCTION " << instructionCount << ": PAYMENT OK\n";
            }
        } else if (tokens[0] == "9") {
            break;
        }
    }
    return 0;
}
