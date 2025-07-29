#include <bits/stdc++.h>
using namespace std;

struct Fact {
    string name;
    vector<string> args;
};

static bool is_name_char(char c) {
    return isalnum(static_cast<unsigned char>(c)) || c == '_';
}

static void skip_ws(const string& s, size_t& i) {
    while (i < s.size() && isspace(static_cast<unsigned char>(s[i]))) ++i;
}

static string parse_name(const string& s, size_t& i) {
    size_t b = i;
    while (i < s.size() && is_name_char(s[i])) ++i;
    return s.substr(b, i - b);
}

static vector<string> parse_args(const string& s, size_t& i) {
    vector<string> a;
    skip_ws(s, i);
    ++i;
    while (true) {
        skip_ws(s, i);
        a.push_back(parse_name(s, i));
        skip_ws(s, i);
        if (s[i] == ',') {
            ++i;
            continue;
        }
        if (s[i] == ')') {
            ++i;
            break;
        }
    }
    return a;
}

static Fact parse_fact(const string& s, size_t& i) {
    skip_ws(s, i);
    string name = parse_name(s, i);
    vector<string> args = parse_args(s, i);
    return {move(name), move(args)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Fact> facts;
    string line;
    while (getline(cin, line)) {
        if (ranges::all_of(line, [](unsigned char c) { return std::isspace(c); })) break;
        size_t pos = 0;
        while (true) {
            skip_ws(line, pos);
            if (pos >= line.size()) break;
            facts.push_back(parse_fact(line, pos));
        }
    }
    unordered_map<string, vector<const Fact*>> idx;
    for (const Fact& f : facts) idx[f.name + '#' + to_string(f.args.size())].push_back(&f);
    while (getline(cin, line)) {
        size_t pos = 0;
        Fact q = parse_fact(line, pos);
        const auto& cand = idx[q.name + '#' + to_string(q.args.size())];
        long long ans = 0;
        for (const Fact* fp : cand) {
            unordered_map<string, string> map_var;
            bool ok = true;
            for (size_t k = 0; k < q.args.size() && ok; ++k) {
                const string& qa = q.args[k];
                const string& fa = fp->args[k];
                if (!qa.empty() && qa[0] == '_') {
                    if (qa.size() == 1) continue;
                    auto [it, inserted] = map_var.try_emplace(qa, fa);
                    if (!inserted && it->second != fa) ok = false;
                } else if (qa != fa) ok = false;
            }
            if (ok) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
