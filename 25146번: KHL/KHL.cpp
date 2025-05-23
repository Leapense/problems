#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N;
    cin >> N;
    cin.ignore();

    int total_points = 0;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        vector<string> parts;
        stringstream ss(line);

        string part;

        while (getline(ss, part, '/')) {
            parts.push_back(part);
        }

        bool is_home = (i % 2 == 0);

        int medvescak_score = 0;
        int opponent_score = 0;

        for (int j = 0; j < 3; ++j) {
            stringstream period_ss(parts[j]);
            string score_str;

            getline(period_ss, score_str, ':');
            int D = stoi(score_str);
            
            getline(period_ss, score_str);
            int G = stoi(score_str);

            if (is_home) {
                medvescak_score += D;
                opponent_score += G;
            } else {
                medvescak_score += G;
                opponent_score += D;
            }
        }

        if (medvescak_score > opponent_score) {
            total_points += 3;
        } else if (medvescak_score < opponent_score) {

        } else {
            if (parts.size() >= 4) {
                stringstream overtime_ss(parts[3]);
                string score_str;
                getline(overtime_ss, score_str, ':');
                int Dp = stoi(score_str);

                getline(overtime_ss, score_str);
                int Gp = stoi(score_str);

                int medvescak_ot_score = is_home ? Dp : Gp;
                int opponent_ot_score = is_home ? Gp : Dp;

                if (medvescak_ot_score > opponent_ot_score) {
                    total_points += 2;
                } else if (medvescak_ot_score < opponent_ot_score) {
                    total_points += 1;
                } else {
                    if (parts.size() >= 5) {
                        stringstream penalty_ss(parts[4]);
                        string score_str;

                        getline(penalty_ss, score_str, ':');
                        int Dk = stoi(score_str);

                        getline(penalty_ss, score_str);
                        int Gk = stoi(score_str);

                        int medvescak_penalty_score = is_home ? Dk : Gk;

                        int opponent_penalty_score = is_home ? Gk : Dk;

                        if (medvescak_penalty_score > opponent_penalty_score) {
                            total_points += 1;
                        } else {

                        }
                    }
                }
            }
        }
    }

    cout << total_points << endl;
    return 0;
}