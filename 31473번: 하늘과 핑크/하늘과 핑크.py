def find_optimal_a_b(N, A, B):
    S_A = sum(A)
    S_B = sum(B)

    # 분모가 0이 되는 경우를 방지하기 위해 기본값 설정
    if S_A == 0:
        a = 0
        b = 1
    elif S_B == 0:
        a = 1
        b = 0
    else:
        a = S_B
        b = S_A

    # 기약분수 형태로 만들기 위해 최대공약수를 구함
    from math import gcd
    g = gcd(a, b)
    a //= g
    b //= g

    return a, b

# 입력 받기
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 최적의 a, b 찾기
a, b = find_optimal_a_b(N, A, B)
print(a, b)