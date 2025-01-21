#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;

    while (getline(cin, line)) {
        if (line == "0") break;
        if (line.empty()) continue;

        int plen = stoi(line);
        getline(cin, line);
        int cnum = stoi(line);
        getline(cin, line);
        int width = stoi(line);
        getline(cin, line);
        int cspace = stoi(line);
        vector<string> input;

        while(getline(cin, line) && line != "?") {
            input.push_back(line);
        }

        vector<string> processed;

        for (auto &s : input) {
            if (s.empty()) {
                processed.emplace_back(string(width, '.'));
            } else {
                int len = s.size();
                int start = 0;
                while (start < len) {
                    string part = s.substr(start, width);
                    if (part.size() < width) {
                        part += string(width - part.size(), '.');
                    }
                    processed.emplace_back(part);
                    start += width;
                }
            }
        }

        if (!processed.empty()) {
            int total_columns = (processed.size() + plen - 1) / plen;
            int total_pages = (total_columns + cnum - 1) / cnum;
            for (int p = 0; p < total_pages; p++) {
                for (int l = 0; l < plen; l++) {
                    string out = "";
                    for (int c = 0; c < cnum; c++) {
                        int col = p * cnum + c;
                        if (col < total_columns) {
                            int idx = col * plen + l;
                            if (idx < processed.size()) {
                                string s = processed[idx];
                                out += s;
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