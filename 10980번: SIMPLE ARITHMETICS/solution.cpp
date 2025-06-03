#include <bits/stdc++.h>
using namespace std;

// 연산자 우선순위 반환 함수
static int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return -1; // 허용되지 않은 문자
}

// 두 피연산자와 연산자로 계산 수행. 에러 시 nullopt 반환
static optional<long long> compute(long long lhs, long long rhs, char op) {
    switch (op) {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        case '/':
            if (rhs == 0) {
                return nullopt; // 분모 0 에러
            }
            // C++ 정수 나눗셈은 0 방향 절단, 음수 포함되어도 본 문제 조건과 일치
            return lhs / rhs;
        default:
            return nullopt;
    }
}

// 문자열 expr을 계산하여 result에 저장. 정상 시 true, 에러 시 false 반환
static bool evaluate(const string &expr, long long &result) {
    int n = (int)expr.size();
    if (n == 0) {
        return false;
    }

    stack<long long> operand;
    stack<char> oper;

    bool invalid = false;
    int idx = 0;           // 현재 검사 인덱스
    char prev_char = '\0'; // 이전 문자 (연산자 연속 검사용)

    // 1) 맨 앞이 음수 리터럴인지 확인
    if (expr[0] == '-' && n >= 2 && isdigit(static_cast<unsigned char>(expr[1]))) {
        // 예: "-1", "-9" 등에 대해 음수 하나로 처리
        long long val = -(long long)(expr[1] - '0');
        operand.push(val);
        idx = 2;
        prev_char = '0'; // 숫자처럼 처리 (연산자 연속 검사 시 다음에 연산자 나오면 에러)
    }
    else {
        // 맨 앞이 '+', '*', '/' 중 하나면 에러
        if (expr[0] == '+' || expr[0] == '*' || expr[0] == '/') {
            return false;
        }
        // expr[0] == '-'인데 expr[1]이 숫자가 아니면 에러
        if (expr[0] == '-' && !(n >= 2 && isdigit(static_cast<unsigned char>(expr[1])))) {
            return false;
        }
    }

    // 2) 남은 문자열 순회
    for (int i = idx; i < n; ++i) {
        char c = expr[i];

        bool isDigit = isdigit(static_cast<unsigned char>(c));
        bool isOp = (c == '+' || c == '-' || c == '*' || c == '/');
        if (!isDigit && !isOp) {
            return false;
        }

        // 연산자 연속 검사
        if (isOp && (prev_char == '+' || prev_char == '-' || prev_char == '*' || prev_char == '/')) {
            return false;
        }

        if (isDigit) {
            long long val = (long long)(c - '0');
            operand.push(val);
        }
        else {
            int cur_prec = precedence(c);
            if (cur_prec < 0) {
                return false;
            }
            // 기존 스택에 있는 연산자가 현재보다 우선순위가 높거나 같으면 미리 계산
            while (!oper.empty() && precedence(oper.top()) >= cur_prec) {
                char top_op = oper.top();
                oper.pop();

                if (operand.size() < 2) {
                    return false;
                }
                long long rhs = operand.top(); operand.pop();
                long long lhs = operand.top(); operand.pop();

                auto comp = compute(lhs, rhs, top_op);
                if (!comp.has_value()) {
                    return false;
                }
                operand.push(comp.value());
            }
            // 현재 연산자 스택에 push
            oper.push(c);
        }

        prev_char = c;
    }

    // 3) 남아 있는 연산자 모두 처리
    while (!oper.empty()) {
        char op = oper.top();
        oper.pop();
        if (operand.size() < 2) {
            return false;
        }
        long long rhs = operand.top(); operand.pop();
        long long lhs = operand.top(); operand.pop();

        auto comp = compute(lhs, rhs, op);
        if (!comp.has_value()) {
            return false;
        }
        operand.push(comp.value());
    }

    // 4) 최종 결과 검증
    if (operand.size() != 1) {
        return false;
    }
    result = operand.top();
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) {
        return 0;
    }

    while (T--) {
        string expr;
        cin >> expr;
        long long ans = 0;
        if (evaluate(expr, ans)) {
            cout << ans << "\n";
        } else {
            cout << "WRONG INPUT\n";
        }
    }
    return 0;
}
