import sys

def is_subsequence(sub, T):
    it = iter(T)
    return all(c in it for c in sub)

input = sys.stdin.readline

S = input().strip()
T = input().strip()

# S의 홀수 인덱스
S_odd = S[1::2]
# S의 짝수 인덱스
S_even = S[::2]

# S의 홀수 인덱스 문자들이 T의 하위 수열로 존재하는가?
it = iter(T)

if is_subsequence(S_odd, T):
    print("Yes")
elif is_subsequence(S_even, T):
    print("Yes")
else:
    print("No")