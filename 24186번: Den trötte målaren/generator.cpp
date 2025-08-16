#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

struct Line {
    bool isRow;
    int index;
    char color;
};

static bool equalsIgnoreCase(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); i++) {
        if (std::tolower(static_cast<unsigned char>(a[i])) != std::tolower(static_cast<unsigned char>(b[i]))) {
            return false;
        }
    }

    return true;
}

static bool isAutoSpec(const std::string& s) {
    return equalsIgnoreCase(s, "auto");
}

static int parseInt(const std::string& s) {
    return std::stoi(s);
}

static int pickInRangeSpec(const std::string& spec, int lo, int hi) {
    size_t pos = spec.find("..");
    if (pos == std::string::npos) {
        int v = parseInt(spec);
        if (v < lo) v = lo;
        if (v > hi) v = hi;
        return v;
    }
    int a = parseInt(spec.substr(0, pos));
    int b = parseInt(spec.substr(pos + 2));
    int L = std::min(a, b);
    int R = std::max(a, b);
    if (R < lo) R = lo;
    if (L > hi) L = hi;
    int left = std::max(L, lo);
    int right = std::min(R, hi);
    if (left > right) left = right;
    return rnd.next(left, right);
}

static std::vector<int> chooseUniqueIndices(int n, int k) {
    std::vector<int> all(n);
    for (int i = 0; i < n; i++) all[i] = i;
    shuffle(all.begin(), all.end());
    if (k < 0) k = 0;
    if (k > n) k = n;
    return std::vector<int>(all.begin(), all.begin() + k);
}

static char pickColor(int probS) {
    int x = rnd.next(0, 99);
    return (x < probS) ? 'S' : 'V';
}

static void fillGrid(int n, const std::vector<Line>& lines, std::vector<std::string>& grid) {
    grid.assign(n, std::string(n, '.'));
    std::vector<Line> order = lines;
    shuffle(order.begin(), order.end());
    for (const auto& ln : order) {
        if (ln.isRow) {
            for (int j = 0; j < n; j++) grid[ln.index][j] = ln.color;
        } else {
            for (int i = 0; i < n; i++) grid[i][ln.index] = ln.color;
        }
    }
}

static void computeCountsRnd(int n, const std::string& lSpec, int& rowCnt, int& colCnt) {
    int L;
    if (isAutoSpec(lSpec)) {
        L = rnd.next(0, 2 * n);
    } else {
        int v = pickInRangeSpec(lSpec, 0, 2 * n);
        L = v;
    }

    int rMin = std::max(0, L - n);
    int rMax = std::min(L, n);
    rowCnt = rnd.next(rMin, rMax);
    colCnt = L - rowCnt;
}

static void computeCountsSparse(int n, const std::string& lSpec, int& rowCnt, int& colCnt) {
    int maxL = 2 * n - 2;
    if (maxL < 0) maxL = 0;
    int L;
    if (isAutoSpec(lSpec)) {
        rowCnt = rnd.next(0, std::max(0, n - 1));
        colCnt = rnd.next(0, std::max(0, n - 1));
        if (n >= 2 && rowCnt == 0 && colCnt == 0) {
            if (rnd.next(0, 1) == 0) rowCnt = 1; else colCnt = 1;
        }
        return;
    } else {
        L = pickInRangeSpec(lSpec, 0, maxL);
    }

    int rMin = 0;
    int rMax = std::min(L, n - 1);
    int cMin = L - rMax;
    if (cMin < 0) cMin = 0;
    int cMax = std::min(L, n - 1);
    if (cMin > cMax) {
        rowCnt = std::min(n - 1, L);
        colCnt = L - rowCnt;
        if (colCnt > n - 1) colCnt = n - 1;
        return;
    }

    rowCnt = rnd.next(std::max(0, L - (n - 1)), std::min(L, n - 1));
    colCnt = L - rowCnt;
}

static void computeCountsForced(int n, const std::string& lSpec, int& rowCnt, int& colCnt) {
    int maxL = 2 * n - 2;
    int minL = std::min(2, std::max(0, 2 * n - 2));
    if (n == 1) {
        rowCnt = 0;
        colCnt = 0;
        return;
    }
    int L;
    if (isAutoSpec(lSpec)) {
        rowCnt = rnd.next(1, n - 1);
        colCnt = rnd.next(1, n - 1);
        return;
    } else {
        L = pickInRangeSpec(lSpec, minL, maxL);
    }

    int rMin = std::max(1, L - (n - 1));
    int rMax = std::min(n - 1, L - 1);
    if (rMin > rMax) {
        rowCnt = std::min(n - 1, std::max(1, L / 2));
        colCnt = L - rowCnt;
        if (colCnt < 1) { colCnt = 1; rowCnt = L - 1; }
        if (colCnt > n - 1) { colCnt = n - 1; rowCnt = L - colCnt; }
        if (rowCnt < 1) rowCnt = 1;
        if (rowCnt > n - 1) rowCnt = n - 1;
        return;
    }
    rowCnt = rnd.next(rMin, rMax);
    colCnt = L - rowCnt;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int nonSeedArgs = argc - 1;
    std::string mode = nonSeedArgs >= 2 ? std::string(argv[1]) : std::string("rnd");
    std::string nSpec = nonSeedArgs >= 3 ? std::string(argv[2]) : std::string("1..9");
    std::string lSpec = nonSeedArgs >= 4 ? std::string(argv[3]) : std::string("auto");
    int probS = nonSeedArgs >= 5 ? parseInt(argv[4]) : 50;
    int distinct = nonSeedArgs >= 6 ? parseInt(argv[5]) : 0;

    int n = pickInRangeSpec(nSpec, 1, 9);
    int rowCnt = 0;
    int colCnt = 0;

    if (equalsIgnoreCase(mode, "max")) {
        rowCnt = n;
        colCnt = n;
    } else if (equalsIgnoreCase(mode, "rows")) {
        int L = isAutoSpec(lSpec) ? rnd.next(0, n) : pickInRangeSpec(lSpec, 0, n);
        rowCnt = L;
        colCnt = 0;
    } else if (equalsIgnoreCase(mode, "cols")) {
        int L = isAutoSpec(lSpec) ? rnd.next(0, n) : pickInRangeSpec(lSpec, 0, n);
        rowCnt = 0;
        colCnt = L;
    } else if (equalsIgnoreCase(mode, "sparse")) {
        computeCountsSparse(n, lSpec, rowCnt, colCnt);
    } else if (equalsIgnoreCase(mode, "forced")) {
        computeCountsForced(n, lSpec, rowCnt, colCnt);
    } else {
        computeCountsRnd(n, lSpec, rowCnt, colCnt);
    }

    if (rowCnt < 0) rowCnt = 0;
    if (rowCnt > n) rowCnt = n;
    if (colCnt < 0) colCnt = 0;
    if (colCnt > n) colCnt = n;

    if (equalsIgnoreCase(mode, "sparse") || equalsIgnoreCase(mode, "forced")) {
        if (n >= 2) {
            if (rowCnt == n) rowCnt = n - 1;
            if (colCnt == n) colCnt = n - 1;
            if (equalsIgnoreCase(mode, "forced")) {
                if (rowCnt == 0) rowCnt = 1;
                if (colCnt == 0) colCnt = 1;
            }
        }
    }

    std::vector<int> rows = chooseUniqueIndices(n, rowCnt);
    std::vector<int> cols = chooseUniqueIndices(n, colCnt);

    std::vector<Line> lines;
    lines.reserve(rows.size() + cols.size());
    for (int r : rows) {
        Line ln;
        ln.isRow = true;
        ln.index = r;
        ln.color = pickColor(probS);
        lines.push_back(ln);
    }

    for (int c : cols) {
        Line ln;
        ln.isRow = false;
        ln.index = c;
        ln.color = pickColor(probS);
        lines.push_back(ln);
    }

    if (distinct != 0 && lines.size() >= 2) {
        int cntS = 0;
        for (const auto& ln : lines) if (ln.color == 'S') cntS++;
        if (cntS == 0) lines[0].color = 'S';
        if (cntS == static_cast<int>(lines.size())) lines[0].color = 'V';
    }

    std::vector<std::string> grid;
    fillGrid(n, lines, grid);
    std::cout << n << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << grid[i] << "\n";
    }

    return 0;
}