#include <bits/stdc++.h>
using namespace std;

static vector<string_view> splitPath(string_view path) {
    vector<string_view> out;
    size_t start = 0;
    for (size_t i = 0; i <= path.size(); ++i) {
        if (i == path.size() || path[i] == '/') {
            out.emplace_back(path.substr(start, i - start));
            start = i + 1;
        }
    }
    return out;
}

static string joinRange(const vector<string_view>& v,
                        size_t l, size_t r,
                        bool leadingSlash, bool trailingSlash) {
    if (l >= r) {
        return {};
    }
    size_t total = leadingSlash + trailingSlash;
    for (size_t i = l; i < r; ++i) {
        total += v[i].size();
        if (i + 1 < r) {
            ++total;
        }
    }
    string res;
    res.reserve(total);
    if (leadingSlash) {
        res.push_back('/');
    }
    for (size_t i = l; i < r; ++i) {
        res.append(v[i]);
        if (i + 1 < r) {
            res.push_back('/');
        }
    }
    if (trailingSlash) {
        res.push_back('/');
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string src, dst;
    getline(cin, src);
    getline(cin, dst);

    auto srcParts = splitPath(src);
    auto dstParts = splitPath(dst);

    size_t p = 0;
    while (p < srcParts.size() && p < dstParts.size()
           && srcParts[p] == dstParts[p]) {
        ++p;
    }

    size_t q = 0;
    while (q < srcParts.size() - p && q < dstParts.size() - p
           && srcParts[srcParts.size() - 1 - q] ==
              dstParts[dstParts.size() - 1 - q]) {
        ++q;
    }

    string A = joinRange(srcParts, 0, p, false, p > 0);
    string B = joinRange(srcParts, p, srcParts.size() - q, false, false);
    string C = joinRange(dstParts, p, dstParts.size() - q, false, false);
    string D = joinRange(srcParts, srcParts.size() - q, srcParts.size(), q > 0, false);

    constexpr string_view L = "{";
    constexpr string_view AR = " => ";
    constexpr string_view R = "}";

    string result;
    result.reserve(A.size() + B.size() + C.size() + D.size() +
                   L.size() + AR.size() + R.size());
    result.append(A).append(L).append(B).append(AR).append(C).append(R).append(D);

    cout << result << '\n';
    return 0;
}