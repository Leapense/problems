#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    string rack;
    cin >> rack;

    int rack_counts[26] = {0};
    int wildcards = 0;

    // Bessie's 랙에 있는 글자들의 빈도수 계산
    for (char c : rack) {
        if (c == '#') {
            wildcards++;
        } else {
            rack_counts[c - 'A']++;
        }
    }

    ifstream infile("scrbl.txt");
    if (!infile) {
        cerr << "scrbl.txt 파일을 열 수 없습니다." << endl;
        return 1;
    }

    string word;
    int words_read = 0;
    while (getline(infile, word) && words_read < D) {
        words_read++;

        int word_counts[26] = {0};
        // 단어의 각 글자 빈도수 계산
        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                word_counts[c - 'A']++;
            }
        }

        int shortage = 0;
        // 필요한 글자 수와 랙에 있는 글자 수 비교
        for (int i = 0; i < 26; ++i) {
            if (word_counts[i] > rack_counts[i]) {
                shortage += word_counts[i] - rack_counts[i];
            }
        }

        // 부족한 글자 수가 와일드카드 수 이하인 경우 출력
        if (shortage <= wildcards) {
            cout << word << endl;
        }
    }

    infile.close();

    return 0;
}
