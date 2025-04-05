#include <string>

std::string find_reverse (int N, int M, int connections[][2]) {
    std::string result;
    result.reserve(M);

    for (int i = 0; i < M; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        result.push_back((u < v) ? '0' : '1');
    }

    return result;
}
