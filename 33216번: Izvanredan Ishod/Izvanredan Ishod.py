def parse_token(token):
    status = token[0]
    rest = token[1:]
    count = 0
    time_val = None

    if not rest:
        return status, 0, None
    
    if '/' in rest:
        count_str, time_str = rest.split('/')
        if count_str:
            count = int(count_str)

        h, m, s = map(int, time_str.split(':'))
        time_val = h * 3600 + m * 60 + s
    else:
        if rest:
            count = int(rest)
    return status, count, time_val

def compute_penalty(time_sec, submissions):
    return time_sec + 1200 * (submissions - 1)


import sys, math

def main():
    data = sys.stdin.read().strip().splitlines()
    if not data:
        return
    
    first_line = data[0].split()
    N = int(first_line[0])
    M = int(first_line[1])

    frozen = {}
    order = []

    for i in range(1, N+1):
        parts = data[i].split()
        team_name = parts[0]
        tokens = parts[1:]
        solved = 0
        penalty = 0
        pending = []

        for token in tokens:
            if token == '-':
                continue
            status, count, t_sec = parse_token(token)
            if status == '+':
                solved += 1
                penalty += compute_penalty(t_sec, count)
            elif status == '?':
                pending.append(compute_penalty(t_sec, count))
        frozen[team_name] = (solved, penalty, pending)
        order.append(team_name)

    final_line = data[N+1].split()
    our_team = final_line[0]
    solved_final = 0
    penalty_final = 0

    for token in final_line[1:]:
        if token == '-':
            continue
        status, count, t_sec = parse_token(token)
        if status == '+':
            solved_final += 1
            penalty_final += compute_penalty(t_sec, count)

    our_result = (solved_final, penalty_final, our_team)

    def can_beat(team_name, team_data):
        base_solved, base_penalty, pending = team_data
        pending_count = len(pending)
        if base_solved > our_result[0]:
            return True
        if base_solved + pending_count < our_result[0]:
            return False
        if base_solved + pending_count > our_result[0]:
            return True
        
        needed = our_result[0] - base_solved

        dp = [math.inf] * (needed + 1)
        dp[0] = 0
        for p_val in pending:
            for j in range(needed, 0, -1):
                if dp[j-1] != math.inf:
                    dp[j] = min(dp[j], dp[j-1] + p_val)
        if dp[needed] == math.inf:
            return False
        final_pen = base_penalty + dp[needed]
        if final_pen < our_result[1]:
            return True
        if final_pen == our_result[1] and team_name < our_team:
            return True
        return False
    
    def can_beat_with_equal_base(team_name, team_data):
        base_solved, base_penalty, pending = team_data
        pending_count = len(pending)
        if base_solved == our_result[0]:
            if pending_count >= 1:
                return True
            else:
                if base_penalty < our_result[1]:
                    return True
                if base_penalty == our_result[1] and team_name < our_team:
                    return True
        return False
    
    beaten = 0
    for name in frozen:
        if name == our_team:
            continue
        base_solved, base_penalty, pending = frozen[name]
        if base_solved > our_result[0]:
            beaten += 1
        elif base_solved < our_result[0]:
            if base_solved + len(pending) > our_result[0]:
                beaten += 1
            elif base_solved + len(pending) == our_result[0]:
                if can_beat(name, (base_solved, base_penalty, pending)):
                    beaten += 1
        else:
            if can_beat_with_equal_base(name, (base_solved, base_penalty, pending)):
                beaten += 1

    worst_position = beaten + 1
    sys.stdout.write(str(worst_position))

if __name__ == "__main__":
    main()