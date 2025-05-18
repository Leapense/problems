#include <bits/stdc++.h>

using namespace std;

struct Word
{
    string text;
    int link_to;
};

void run(istream &in, ostream &out)
{
    int K;
    in >> K;

    for (int ds = 1; ds <= K; ds++)
    {
        int m, n;
        in >> m >> n;
        vector<string> queries(m);
        for (auto &q : queries)
            in >> q;

        vector<vector<Word>> pages(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int L;
            in >> L;
            pages[i].clear();
            string line;
            getline(in, line);

            for (int l = 0; l < L; l++)
            {
                getline(in, line);
                istringstream ss(line);
                string token;
                while (ss >> token)
                {
                    Word w;
                    w.link_to = 0;
                    if (token.size() >= 4 && token.front() == '[' && token.back() == ']')
                    {
                        auto comma = token.find(',', 1);
                        w.text = token.substr(1, comma - 1);
                        int tgt = stoi(token.substr(comma + 1, token.size() - comma - 2));
                        w.link_to = tgt;
                    }
                    else
                    {
                        w.text = token;
                    }

                    pages[i].push_back(move(w));
                }
            }
        }

        out << "Data Set " << ds << ":\n";
        vector<long long> score(n + 1);
        for (auto &q : queries)
        {
            fill(score.begin(), score.end(), 0LL);

            for (int i = 1; i <= n; i++)
            {
                for (auto &w : pages[i])
                {
                    if (w.text == q)
                        score[i]++;
                }
            }

            for (int i = 1; i <= n; i++)
            {
                auto &pg = pages[i];
                int sz = pg.size();
                for (int j = 0; j < sz; j++)
                {
                    int tgt = pg[j].link_to;
                    if (tgt == 0)
                        continue;
                    for (int d = -3; d <= 3; d++)
                    {
                        int idx = j + d;
                        if (idx < 0 || idx >= sz)
                            continue;
                        int dist = abs(d);
                        if (dist < 4 && pg[idx].text == q)
                        {
                            score[tgt] += 4 - dist;
                        }
                    }
                }
            }

            long long best = *max_element(score.begin() + 1, score.end());
            bool first = true;

            for (int i = 1; i <= n; i++)
            {
                if (score[i] == best)
                {
                    if (!first)
                        out << ' ';
                    out << i;
                    first = false;
                }
            }

            out << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run(cin, cout);
    return 0;
}