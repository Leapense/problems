#include <bits/stdc++.h>
using namespace std;

static string to_upper(string s)
{
    for (char &ch : s)
        ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
    return s;
}

static string capitalise(string s)
{
    if (!s.empty())
    {
        s[0] = static_cast<char>(toupper(static_cast<unsigned char>(s[0])));
    }

    return s;
}

struct Contraction
{
    string pat[3], sub[3];
};

static pair<string, string> parse_mapping_line(const string &line)
{
    size_t q1 = line.find('"');
    size_t q2 = line.find('"', q1 + 1);
    size_t q3 = line.find('"', q2 + 1);
    size_t q4 = line.find('"', q3 + 1);

    return {
        line.substr(q1 + 1, q2 - q1 - 1),
        line.substr(q3 + 1, q4 - q3 - 1)};
}

string Solve(istream &in)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t C, A;
    if (!(in >> C >> A))
        return {};
    string dummy;
    getline(in, dummy);

    vector<Contraction> contr;
    contr.reserve(C);

    for (size_t i = 0; i < C; ++i)
    {
        string line;
        getline(in, line);
        auto [c, e] = parse_mapping_line(line);

        Contraction item;
        item.pat[0] = c;
        item.sub[0] = e;
        item.pat[1] = to_upper(c);
        item.sub[1] = to_upper(e);
        item.pat[2] = capitalise(c);
        item.sub[2] = capitalise(e);
        contr.push_back(move(item));
    }

    struct Acr
    {
        string pat, exp;
    };
    vector<Acr> acr;
    acr.reserve(A);

    for (size_t i = 0; i < A; ++i)
    {
        string line;
        getline(in, line);
        auto [a, e] = parse_mapping_line(line);
        acr.push_back({a, e});
    }

    string line, out;
    vector<char> seen(A, 0);
    while (getline(in, line))
    {
        if (line == "#")
        {
            fill(seen.begin(), seen.end(), 0);
            out += "#\n";
            continue;
        }

        string newline;
        for (size_t pos = 0; pos < line.size();)
        {
            bool matched = false;
            string replacement;
            size_t consume = 0;

            for (size_t idx = 0; !matched && idx < contr.size(); ++idx)
            {
                for (int v = 0; !matched && v < 3; ++v)
                {
                    const auto &pat = contr[idx].pat[v];
                    if (pat.empty())
                        continue;
                    if (line.compare(pos, pat.size(), pat) == 0)
                    {
                        replacement = contr[idx].sub[v];
                        consume = pat.size();
                        matched = true;
                    }
                }
            }

            for (size_t idx = 0; !matched && idx < acr.size(); ++idx)
            {
                if (seen[idx])
                    continue;
                const auto &pat = acr[idx].pat;
                if (line.compare(pos, pat.size(), pat) == 0)
                {
                    replacement = acr[idx].exp + " (" + pat + ')';
                    consume = pat.size();
                    matched = true;
                    seen[idx] = 1;
                }
            }

            if (matched)
            {
                newline += replacement;
                pos += consume;
            }
            else
            {
                newline.push_back(line[pos++]);
            }
        }

        out += newline + '\n';
    }

    return out;
}

int main()
{
    cout << Solve(cin);
    return 0;
}