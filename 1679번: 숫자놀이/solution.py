import sys

def get_solution_output(N_val, available_numbers_val, K_val):
    available_numbers = available_numbers_val
    K = K_val
    max_num_in_set = available_numbers[-1]
    dp_table_max_target = K * max_num_in_set + 1
    dp = [float('inf')] * (dp_table_max_target + 1)
    dp[0] = 0

    for i in range(1, dp_table_max_target + 1):
        for num_val in available_numbers:
            if num_val > i:
                break
            if dp[i - num_val] != float('inf'):
                dp[i] = min(dp[i], dp[i - num_val] + 1)
    target_sum = 1
    while target_sum <= dp_table_max_target:
        min_uses_for_target = dp[target_sum]

        if min_uses_for_target > K:
            winner_name = ""

            if target_sum % 2 == 1:
                winner_name = "jjaksoon"
            else:
                winner_name = "holsoon"
            
            return f"{winner_name} win at {target_sum}"
        
        target_sum += 1

    return "Error: Game did not conclude within the expected range."

if __name__ == "__main__":
    N_in = int(sys.stdin.readline())
    nums_str_in = sys.stdin.readline().split()
    available_numbers_in = [int(x) for x in nums_str_in]
    K_in = int(sys.stdin.readline())

    result = get_solution_output(N_in, available_numbers_in, K_in)
    print(result)