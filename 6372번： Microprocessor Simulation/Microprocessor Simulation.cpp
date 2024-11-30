#include <bits/stdc++.h>

using namespace std;

int hexToInt(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'F') return 10 + (c - 'A');
    if ('a' <= c && c <= 'f') return 10 + (c - 'a');

    return 0;
}

char intToHex(int x) {
    if (0 <= x && x <= 9) return x + '0';
    return 'A' + (x - 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;

    while(getline(cin, line)) {
        if (line.size() != 256) {
            line += string(256 - line.size(), '0');
        }

        if(line[0] == '8') break;

        vector<int> memory(256, 0);
        for (int i = 0; i < 256; ++i) {
            memory[i] = hexToInt(line[i]);
        }

        int A = 0, B = 0;
        int PC = 0;

        bool stopped = false;

        while(!stopped) {
            if (PC < 0 || PC >= 256) {
                break;
            }

            int code = memory[PC];

            int instr_size = 1;

            int arg = 0;
            bool has_arg = false;

            if(code == 0 || code == 1 || code == 6 || code == 7) {
                has_arg = true;

                if (PC + 2 >= 256) {
                    arg = 0;
                } else {
                    int high = memory[PC + 1];
                    int low = memory[PC + 2];
                    arg = high * 16 + low;
                }

                instr_size = 3;
            }

            switch(code) {
                case 0:
                if (arg >= 0 && arg < 256) {
                    A = memory[arg];
                } else {
                    A = 0;
                }
                break;
                case 1:
                if (arg >= 0 && arg < 256) {
                    memory[arg] = A;
                }
                break;
                case 2:
                swap(A, B);
                break;
                case 3:
                {
                    int sum = A + B;
                    A = sum & 0xF;
                    B = (sum >> 4) & 0xF;
                    break;
                }
                case 4:
                A = (A + 1) & 0xF;
                break;
                case 5:
                A = (A - 1) & 0xF;
                break;
                case 6:
                if (A == 0) {
                    PC = arg;
                    continue;
                }
                break;
                case 7:
                PC = arg;
                continue;
                case 8:
                stopped = true;
                break;
                default:
                break;
            }

            PC += instr_size;

            if (PC >= 256) {
                PC = PC % 256;
            }
        }

        string output = "";
        for (int i = 0; i < 256; ++i) {
            output += intToHex(memory[i]);
        }

        cout << output << "\n";
    }

    return 0;
}