#include <bits/stdc++.h>
using namespace std;

struct Guess {
    int digits[4];
    int counts[10];
    int A;
    int B;
};

struct Secret {
    int digits[4];
    int counts[10];
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Guess> guesses(N);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 4; j++) {
            guesses[i].digits[j] = s[j] - '0';
        }
        fill(guesses[i].counts, guesses[i].counts + 10, 0);

        for (int j = 0; j < 4; j++) {
            guesses[i].counts[guesses[i].digits[j]]++;
        }

        cin >> guesses[i].A >> guesses[i].B;
    }

    sort(guesses.begin(), guesses.end(), [&](const Guess& a, const Guess& b) -> bool {
        if (a.A != b.A) return a.A < b.A;
        return a.B < b.B;
    });

    vector<string> possible_secrets;

    for (int secret_num = 0; secret_num <= 9999; secret_num++) {
        int temp = secret_num;
        int secret_digits[4];
        int secret_counts[10];

        fill(secret_counts, secret_counts + 10, 0);

        for (int j = 3; j >= 0; j--) {
            secret_digits[j] = temp % 10;
            secret_counts[secret_digits[j]]++;
            temp /= 10;
        }

        bool valid = true;
        for (int i = 0; i < N; i++) {
            int B = 0;
            for (int j = 0; j < 4; j++) {
                if (secret_digits[j] == guesses[i].digits[j]) {
                    B++;
                }
            }
            if(B != guesses[i].B) {
                valid = false;
                break;
            }

            int A = 0;

            for (int d = 0; d < 10; d++) {
                A += min(secret_counts[d], guesses[i].counts[d]);
            }
            if (A != guesses[i].A) {
                valid = false;
                break;
            }
        }

        if (valid) {
            string s = to_string(secret_num);
            while(s.size() < 4) s = "0" + s;
            possible_secrets.push_back(s);
        }
    }

    cout << possible_secrets.size() << "\n";
    for (auto &s : possible_secrets) {
        cout << s << "\n";
    }
    
    return 0;
}