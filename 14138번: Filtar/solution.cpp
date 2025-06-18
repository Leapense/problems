#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

// C++26에서는 std::int128_t가 표준화될 수 있지만, 현재는 확장 기능을 사용합니다.
using int128 = __int128_t;
using ll = long long;

struct Point {
    ll x, y;
    // std::upper_bound를 위해 operator< 정의
    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

int n;
std::vector<Point> input_points;
int d;

// 128비트 정수 출력을 위한 함수
std::ostream& operator<<(std::ostream& os, int128 val) {
    if (val == 0) return os << "0";
    std::string s = "";
    bool neg = val < 0;
    if (neg) val = -val;
    while (val > 0) {
        s += (val % 10) + '0';
        val /= 10;
    }
    if (neg) s += '-';
    std::reverse(s.begin(), s.end());
    return os << s;
}

// k에서의 입력 신호 u[k] 값 계산
ll get_u(ll k) {
    auto it = std::upper_bound(input_points.begin(), input_points.end(), Point{k, 0});

    const Point* p1;
    const Point* p2;

    if (it == input_points.begin()) { // 왼쪽 외삽
        p1 = &input_points[0];
        p2 = &input_points[1];
    } else if (it == input_points.end()) { // 오른쪽 외삽
        p1 = &input_points[n - 2];
        p2 = &input_points[n - 1];
        if (k == input_points[n - 1].x) return input_points[n-1].y;
    } else { // 내삽
        p1 = &(*(it - 1));
        p2 = &(*it);
        if (k == p1->x) return p1->y;
    }

    ll x1 = p1->x, y1 = p1->y;
    ll x2 = p2->x, y2 = p2->y;
    
    // "모든 보간된 값은 정수"라는 조건 덕분에 기울기는 항상 정수입니다.
    ll slope = (y2 - y1) / (x2 - x1);
    return y1 + (k - x1) * slope;
}

// k에서의 출력 신호 y[k] 값 계산
ll get_y(ll k) {
    std::vector<ll> values;
    values.reserve(2 * d + 1);
    for (int i = -d; i <= d; ++i) {
        values.push_back(get_u(k - i));
    }
    std::ranges::sort(values);
    return values[d];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    input_points.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input_points[i].x >> input_points[i].y;
    }
    std::cin >> d;

    std::set<ll> event_x;
    for (int j = 0; j < n; ++j) {
        for (int i = -d; i <= d; ++i) {
            event_x.insert(input_points[j].x + i);
        }
    }

    // 충분한 범위를 확보하기 위해 양 끝점을 추가
    if (!event_x.empty()) {
        ll min_x = *event_x.begin();
        ll max_x = *event_x.rbegin();
        ll range = (max_x - min_x) > 0 ? (max_x - min_x) : 100000;
        event_x.insert(min_x - range);
        event_x.insert(max_x + range);
    }
    
    std::map<ll, ll> calculated_points;
    std::queue<std::pair<ll, ll>> work_queue;
    
    std::vector<ll> initial_events(event_x.begin(), event_x.end());

    for (ll x : initial_events) {
        calculated_points[x] = get_y(x);
    }

    for (size_t i = 0; i + 1 < initial_events.size(); ++i) {
        work_queue.push({initial_events[i], initial_events[i + 1]});
    }

    int max_points = 99000; // 출력 제한에 맞춘 안전장치
    while (!work_queue.empty() && calculated_points.size() < max_points) {
        auto [x1, x2] = work_queue.front();
        work_queue.pop();

        if (x2 - x1 <= 1) continue;

        ll x_mid = x1 + (x2 - x1) / 2;
        if (calculated_points.contains(x_mid)) continue;

        ll y1 = calculated_points[x1];
        ll y2 = calculated_points[x2];
        ll y_mid_true = get_y(x_mid);

        // 동일 직선 판별: (y_mid - y1)*(x2 - x1) == (y2 - y1)*(x_mid - x1)
        int128 lhs = (int128)(y_mid_true - y1) * (x2 - x1);
        int128 rhs = (int128)(y2 - y1) * (x_mid - x1);

        if (lhs != rhs) {
            calculated_points[x_mid] = y_mid_true;
            work_queue.push({x1, x_mid});
            work_queue.push({x_mid, x2});
        }
    }

    std::vector<Point> result_points;
    if (calculated_points.size() >= 2) {
        auto it = calculated_points.begin();
        result_points.push_back({it->first, it->second});
        it++;
        result_points.push_back({it->first, it->second});
        it++;

        for (; it != calculated_points.end(); ++it) {
            Point p3 = {it->first, it->second};
            Point p2 = result_points.back();
            Point p1 = result_points[result_points.size() - 2];

            int128 x1 = p1.x, y1 = p1.y;
            int128 x2 = p2.x, y2 = p2.y;
            int128 x3 = p3.x, y3 = p3.y;

            if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) {
                result_points.back() = p3;
            } else {
                result_points.push_back(p3);
            }
        }
    } else { // 2개 미만인 경우 그대로 출력
         for(const auto& p : calculated_points) {
            result_points.push_back({p.first, p.second});
        }
    }


    std::cout << result_points.size() << "\n";
    for (const auto& p : result_points) {
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}