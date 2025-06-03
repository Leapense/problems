#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN    55    // 입력 식 최대 길이 (안전 여유 포함)
#define MAX_STACK  100   // 스택 최대 크기

// 전역 스택 및 포인터
static long long operand_stack[MAX_STACK];
static int operand_top = -1;

static char operator_stack[MAX_STACK];
static int operator_top = -1;

// 숫자 스택 push
static bool push_operand(long long val) {
    if (operand_top >= MAX_STACK - 1) {
        return false;
    }
    operand_stack[++operand_top] = val;
    return true;
}

// 연산자 스택 push
static bool push_operator(char op) {
    if (operator_top >= MAX_STACK - 1) {
        return false;
    }
    operator_stack[++operator_top] = op;
    return true;
}

// 숫자 스택 pop
static bool pop_operand(long long *ret) {
    if (operand_top < 0) {
        return false;
    }
    *ret = operand_stack[operand_top--];
    return true;
}

// 연산자 스택 pop
static bool pop_operator(char *ret) {
    if (operator_top < 0) {
        return false;
    }
    *ret = operator_stack[operator_top--];
    return true;
}

// 숫자 스택 비어 있는지
static bool is_operand_empty(void) {
    return (operand_top < 0);
}

// 연산자 스택 비어 있는지
static bool is_operator_empty(void) {
    return (operator_top < 0);
}

// 연산자 스택 top 확인
static bool top_operator(char *ret) {
    if (operator_top < 0) {
        return false;
    }
    *ret = operator_stack[operator_top];
    return true;
}

// 연산자 우선순위 반환
static int get_precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return -1; // 허용되지 않은 문자
}

// 두 피연산자를 꺼내 연산자에 따라 계산 후 스택에 결과 push
// 만약 0으로 나누기나 스택 언더플로우 발생 시 invalid_flag를 true로 설정
static bool apply_operator(char op, bool *invalid_flag) {
    long long rhs = 0, lhs = 0;
    if (!pop_operand(&rhs) || !pop_operand(&lhs)) {
        *invalid_flag = true;
        return false;
    }

    long long computed = 0;
    switch (op) {
        case '+':
            computed = lhs + rhs;
            break;
        case '-':
            computed = lhs - rhs;
            break;
        case '*':
            computed = lhs * rhs;
            break;
        case '/':
            if (rhs == 0) {
                *invalid_flag = true;
                return false;
            }
            // C의 정수 나눗셈은 0 방향으로 절단(floor toward zero)
            // 본 문제에서는 모든 수가 정수(음수 포함)이고, 음수 나눗셈도 0 방향 절단으로 충분히 내림(floor) 효과와 일치
            computed = lhs / rhs;
            break;
        default:
            *invalid_flag = true;
            return false;
    }

    if (!push_operand(computed)) {
        *invalid_flag = true;
        return false;
    }
    return true;
}

// 문자열 expr을 계산하여 result에 저장
// 음수 리터럴 처리 및 에러 검사를 포함
static bool evaluate_expression(const char *expr, long long *result) {
    int len = (int)strlen(expr);
    if (len == 0) {
        return false;
    }

    operand_top = -1;
    operator_top = -1;
    bool invalid_flag = false;

    int idx = 0;            // 현재 처리할 인덱스
    char prev_char = '\0';  // 이전 문자 (연산자 연속 검사용)

    // 1) 맨 앞이 음수 리터럴인지 확인
    if (expr[0] == '-' && len >= 2 && (expr[1] >= '0' && expr[1] <= '9')) {
        // 예: "-1" 또는 "-5" 같은 경우
        long long val = -(long long)(expr[1] - '0');
        if (!push_operand(val)) {
            return false;
        }
        idx = 2;               // 이미 첫 두 문자를 처리함
        prev_char = '0';       // 숫자가 들어간 것으로 간주 (연산자 연속 검사 시 '-' 다음 바로 연산자 오면 에러)
    }
    else {
        // 맨 앞이 연산자(+/*/)이면 무조건 에러
        if (expr[0] == '+' || expr[0] == '*' || expr[0] == '/') {
            return false;
        }
        // 만약 expr[0] == '-' 이면서 뒤에 숫자가 아닌 것이 올 경우에도 에러
        if (expr[0] == '-' && !(len >= 2 && (expr[1] >= '0' && expr[1] <= '9'))) {
            return false;
        }
        // 맨 앞이 정상 숫자일 때는 idx=0 그대로 두고, prev_char='\0'로 초기화
    }

    // 2) 남은 문자열이 있으면 순차 처리
    for (int i = idx; i < len; ++i) {
        char c = expr[i];

        // 허용된 문자(숫자 또는 사칙연산)인지 검사
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/')) {
            return false;
        }

        bool isOp = (c == '+' || c == '-' || c == '*' || c == '/');
        bool isDigit = (c >= '0' && c <= '9');

        // 연산자가 연속해서 나오는지 검사 (예: "2+-3" 중 '+' 다음 '-' 처리는 음수 리터럴 아니므로 에러)
        if (isOp && (prev_char == '+' || prev_char == '-' || prev_char == '*' || prev_char == '/')) {
            return false;
        }

        // 숫자 처리
        if (isDigit) {
            long long val = (long long)(c - '0');
            if (!push_operand(val)) {
                return false;
            }
        }
        // 연산자 처리
        else {
            int cur_prec = get_precedence(c);
            if (cur_prec < 0) {
                return false;
            }
            // 기존 스택에 우선순위가 높은 연산자가 있다면 미리 계산
            char top_op = '\0';
            while (!is_operator_empty() && top_operator(&top_op) &&
                   get_precedence(top_op) >= cur_prec) {
                pop_operator(&top_op);
                if (!apply_operator(top_op, &invalid_flag)) {
                    return false;
                }
                if (invalid_flag) {
                    return false;
                }
            }
            // 현재 연산자를 스택에 push
            if (!push_operator(c)) {
                return false;
            }
        }

        prev_char = c;
    }

    // 3) 남은 연산자 전부 처리
    while (!is_operator_empty()) {
        char op = '\0';
        pop_operator(&op);
        if (!apply_operator(op, &invalid_flag)) {
            return false;
        }
        if (invalid_flag) {
            return false;
        }
    }

    // 4) 피연산자 스택에 값이 딱 하나 남아야 정상
    if (operand_top != 0) {
        return false;
    }
    long long final_value = 0;
    pop_operand(&final_value);
    *result = final_value;
    return true;
}

// 메인 함수: T개의 테스트케이스 처리
int main(void) {
    int T = 0;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    char buf[MAX_LEN];
    for (int tc = 0; tc < T; ++tc) {
        if (scanf("%s", buf) != 1) {
            printf("WRONG INPUT\n");
            continue;
        }
        long long answer = 0;
        if (evaluate_expression(buf, &answer)) {
            printf("%lld\n", answer);
        } else {
            printf("WRONG INPUT\n");
        }
    }
    return 0;
}
