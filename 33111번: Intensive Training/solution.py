import sys

def solve_instance():
    N, R, K = map(int, sys.stdin.readline().split())
    k_s_val = K // N
    k_b_val = K // N + 1
    num_k_big_days = K % N

    r_s_val = R // N
    r_b_val = R // N + 1
    num_r_big_days = R % N
    num_r_small_days = N - num_r_big_days

    count_kb_rs = min(num_k_big_days, num_r_small_days)
    count_kb_rb = num_k_big_days - count_kb_rs
    count_ks_rs = num_r_small_days - count_kb_rs
    count_ks_rb = N - (count_kb_rs + count_kb_rb + count_ks_rs)

    total_productivity = 0
    total_productivity += count_kb_rs * k_b_val * r_s_val
    total_productivity += count_kb_rb * k_b_val * r_b_val
    total_productivity += count_ks_rs * k_s_val * r_s_val
    total_productivity += count_ks_rb * k_s_val * r_b_val

    sys.stdout.write(str(total_productivity) + "\n")
    
num_test_cases = int(sys.stdin.readline())
for _ in range(num_test_cases):
    solve_instance()