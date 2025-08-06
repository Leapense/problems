import sys

def compute_min_time(member_count, task_count, task_time, change_time, preferences):
    infinity = 10 ** 9
    dp = [infinity] * member_count
    for idx in range(member_count):
        if preferences[idx][0]:
            dp[idx] = 0
    for task_idx in range(1, task_count):
        next_dp = [infinity] * member_count
        for member_idx in range(member_count):
            if not preferences[member_idx][task_idx]:
                continue
            best_switches = min(
                dp[prev_idx] + (prev_idx != member_idx)
                for prev_idx in range(member_count)
                if dp[prev_idx] != infinity
            )
            next_dp[member_idx] = best_switches
        dp = next_dp
    min_switches = min(dp)
    return task_count * task_time + min_switches * change_time

def main():
    lines = sys.stdin.read().splitlines()
    if not lines:
        return
    test_cases = int(lines[0])
    cursor = 1
    outputs = []

    for _ in range(test_cases):
        n, m, t_val, c_val = map(int, lines[cursor].split())
        cursor += 1
        pref = [
            [char == "1" for char in lines[cursor + row].strip()]
            for row in range(n)
        ]
        cursor += n
        result = compute_min_time(n, m, t_val, c_val, pref)
        outputs.append(str(result))
    sys.stdout.write("\n".join(outputs))

if __name__ == "__main__":
    main()