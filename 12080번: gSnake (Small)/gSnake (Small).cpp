#include <iostream>
#include <deque>
#include <set>
#include <vector>

using namespace std;

struct Point {
  int r;
  int c;

  Point(int r, int c) : r(r), c(c) {}

  bool operator==(const Point& other) const {
    return r == other.r && c == other.c;
  }

  bool operator<(const Point& other) const {
    if (r != other.r) {
      return r < other.r;
    }
    return c < other.c;
  }
};

const int R_OFFSETS[] = {-1, 0, 1, 0};
const int C_OFFSETS[] = {0, 1, 0, -1};

int solve(vector<int>& X, vector<char>& A, int R, int C) {
  int direction = 1;
  deque<Point> deque;
  deque.push_front({0, 0});
  set<Point> body;
  body.insert({0, 0});
  set<Point> eaten;

  int timeLimit = X.back() + max(R, C);
  int actionIndex = 0;
  for (int time = 0; time <= timeLimit; ++time) {
    if (actionIndex != X.size() && time == X[actionIndex]) {
      if (A[actionIndex] == 'L') {
        direction = (direction - 1 + 4) % 4;
      } else {
        direction = (direction + 1) % 4;
      }

      ++actionIndex;
    }

    Point oldHead = deque.front();
    Point newHead = {(oldHead.r + R_OFFSETS[direction] + R) % R, (oldHead.c + C_OFFSETS[direction] + C) % C};
    if ((newHead.r + newHead.c) % 2 != 0 && !eaten.count(newHead)) {
      deque.push_front(newHead);
      body.insert(newHead);
      eaten.insert(newHead);
    } else {
      body.erase(deque.back());
      deque.pop_back();

      deque.push_front(newHead);
      if (!body.insert(newHead).second) {
        break;
      }
    }
  }

  return deque.size();
}

int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int S, R, C;
    cin >> S >> R >> C;
    vector<int> X(S);
    vector<char> A(S);
    for (int i = 0; i < S; ++i) {
      cin >> X[i] >> A[i];
    }

    cout << "Case #" << tc << ": " << solve(X, A, R, C) << endl;
  }

  return 0;
}