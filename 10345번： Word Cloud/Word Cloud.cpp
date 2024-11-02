#include <bits/stdc++.h>
using namespace std;

/* void process_mem_usage(double& vm_usage, double& resident_set)
{
    vm_usage = 0.0;
    resident_set = 0.0;

    unsigned long vsize;
    long rss;

    {
        std::string ignore;
        std::ifstream ifs("/proc/self/stat", std::ios_base::in);
        ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> vsize >> rss;
    }

    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024;
    vm_usage = vsize / 1024.0;
    resident_set = rss * page_size_kb;
} */

struct Word {
    string text;
    int count;
    int fontSize;
    int width;
};

int calculateFontSize(int cw, int cmax) {
    return 8 + ceil(40.0 * (cw - 4) / (cmax - 4));
}

int calculateWidth(int t, int P) {
    return ceil((9.0 / 16) * t * P);
}

int main()
{
    //double vm, rss;

    //process_mem_usage(vm, rss);
    //cout << "[Before] VM: " << vm << " KB; RSS: " << rss << endl;

    ios::sync_with_stdio(false);
    cin.tie(0);

    int W, N;
    int test_case = 1;

    while (cin >> W >> N, W != 0 && N != 0) {
        vector<Word> words(N);
        int maxCount = 0;

        for (int i = 0; i < N; ++i) {
            cin >> words[i].text >> words[i].count;
            maxCount = max(maxCount, words[i].count);
        }

        for (int i = 0; i < N; ++i) {
            words[i].fontSize = calculateFontSize(words[i].count, maxCount);
            words[i].width = calculateWidth(words[i].text.length(), words[i].fontSize);
        }

        int currentWidth = 0;
        int currentHeight = 0;
        int totalHeight = 0;
        int maxHeightInRow = 0;

        for (const auto& word : words) {
            if (currentWidth + word.width > W) {
                totalHeight += maxHeightInRow;
                currentWidth = 0;
                maxHeightInRow = 0;
            }
            currentWidth += word.width + 10;
            maxHeightInRow = max(maxHeightInRow, word.fontSize);
        }

        totalHeight += maxHeightInRow;
        cout << "CLOUD " << test_case++ << ": " << totalHeight << endl;
    }

    //process_mem_usage(vm, rss);
    //cout << "[After] VM: " << vm << " KB; RSS: " << rss << endl;

    return 0;
}