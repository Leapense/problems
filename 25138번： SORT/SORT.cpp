#include <bits/stdc++.h>
using namespace std;

struct Word
{
    string s;
    vector<int> letters;
};

vector<int> parse_word(const string &word, const int single_letter_order[26])
{
    vector<int> letters;
    int pos = 0;
    int n = word.size();

    while (pos < n)
    {
        if (word[pos] == 'l' && pos + 1 < n && word[pos + 1] == 'j')
        {
            letters.push_back(13);
            pos += 2;
        }
        else if (word[pos] == 'n' && pos + 1 < n && word[pos + 1] == 'j')
        {
            letters.push_back(16);
            pos += 2;
        }
        else
        {
            int idx = word[pos] - 'a';
            letters.push_back(single_letter_order[idx]);
            pos += 1;
        }
    }

    return letters;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int single_letter_order[26];
    for (int i = 0; i < 26; i++)
        single_letter_order[i] = 0;

    single_letter_order['a' - 'a'] = 1;
    single_letter_order['b' - 'a'] = 2;
    single_letter_order['c' - 'a'] = 3;
    single_letter_order['d' - 'a'] = 4;
    single_letter_order['e' - 'a'] = 5;
    single_letter_order['f' - 'a'] = 6;
    single_letter_order['g' - 'a'] = 7;
    single_letter_order['h' - 'a'] = 8;
    single_letter_order['i' - 'a'] = 9;
    single_letter_order['j' - 'a'] = 10;
    single_letter_order['k' - 'a'] = 11;
    single_letter_order['l' - 'a'] = 12;
    single_letter_order['m' - 'a'] = 14;
    single_letter_order['n' - 'a'] = 15;
    single_letter_order['o' - 'a'] = 17;
    single_letter_order['p' - 'a'] = 18;
    single_letter_order['r' - 'a'] = 19;
    single_letter_order['s' - 'a'] = 20;
    single_letter_order['t' - 'a'] = 21;
    single_letter_order['u' - 'a'] = 22;
    single_letter_order['v' - 'a'] = 23;
    single_letter_order['z' - 'a'] = 24;

    int N;
    cin >> N;

    vector<Word> words(N);
    words.reserve(N);

    for (int i = 0; i < N; i++)
    {
        cin >> words[i].s;
        words[i].letters = parse_word(words[i].s, single_letter_order);
    }

    auto cmp = [&](const Word &a, const Word &b)
    {
        int len_a = a.letters.size();
        int len_b = b.letters.size();
        int min_len = min(len_a, len_b);

        for (int i = 0; i < min_len; i++)
        {
            if (a.letters[i] != b.letters[i])
                return a.letters[i] < b.letters[i];
        }

        return len_a < len_b;
    };

    sort(words.begin(), words.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << words[i].s << "\n";

    return 0;
}