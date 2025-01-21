#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string s;
        cin >> s;

        if (s == "0") break;
        int plen = stoi(s);
        int cnum, width, cspace;
        cin >> cnum >> width >> cspace;

        vector<string> input;
        while (cin >> ws, getline(cin, s) && s != "?") {
            input.push_back(s);
        }

        vector<string> processed;
        for (auto &line : input) {
            if (line.empty()) {
                processed.push_back(string(width, '.'));
                continue;
            }
            int len = line.size();
            int start = 0;

            while (start < len) {
                string part = line.substr(start, width);
                if (part.size() < width) {
                    part += string(width - part.size(), '.');
                }

                processed.push_back(part);
                start += width;
            }
        }

        if (!processed.empty()) {
            int total_columns = ceil((double)processed.size() / plen);
            int total_pages = ceil((double)total_columns / cnum);

            for (int p = 0; p < total_pages; p++) {
                for (int l = 0; l < plen; l++) {
                    string out = "";
                    for (int c = 0; c < cnum; c++) {
                        int col = p * cnum + c;
                        if (col < total_columns) {
                            int idx = col * plen + l;
                            if (idx < processed.size()) {
                                out += processed[idx];
                            } else {
                                out += string(width, '.');
                            }
                        } else {
                            out += string(width, '.');
                        }
                        if (c != cnum - 1) {
                            out += string(cspace, '.');
                        }
                    }

                    cout << out << "\n";
                }
                cout << "#\n";
            }
        }
        cout << "?\n";
    }

    return 0;
}