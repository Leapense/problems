import sys
from typing import List

def main():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    v_list: List[int] = [int(input()) for _ in range(N)]
    
    idx: List[int] = [0] * (N + 1)
    for i in range(N):
        door_number = v_list[i]
        idx[door_number] = i
    
    i_arr: List[int] = [0] * (N + 1)
    for j in range(1, N + 1):
        i_arr[j] = idx[j]
    
    first_index = i_arr[1]

    C = 0
    for j in range(1, N):
        if i_arr[j + 1] < i_arr[j]:
            C += 1

    if i_arr[1] < i_arr[N]:
        C += 1

    diff: List[int] = [0] * (N + 1)
    for j in range(1, N):
        raw = i_arr[j + 1] - i_arr[j]
        diff[j] = raw if raw >= 0 else raw + N

    raw_last = i_arr[1] - i_arr[N]
    diff[N] = raw_last if raw_last >= 0 else raw_last + N

    diff_total = C * N

    total_steps = K - 1
    full_cycles = total_steps // N
    rem = total_steps % N

    rem_total = 0

    for j in range(1, rem + 1):
        rem_total += diff[j]

    S = first_index + full_cycles * diff_total + rem_total
    print(S)

if __name__ == "__main__":
    main()