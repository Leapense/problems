import sys

def time_to_seconds(time_str):
    h, m, s = map(int, time_str.split(':'))
    return h * 3600 + m * 60 + s

def parse_task(task_str):
    if task_str == '-':
        return ('-', 0, 0)
    status = task_str[0]
    rest = task_str[1:]
    if '/' in rest:
        submissions, time_str = rest.split('/')
        submissions = int(submissions) if submissions else 0
        time = time_to_seconds(time_str)
    else:
        submissions = int(rest) if rest else 0
        time = 0
    return (status, submissions, time)

def main():
    N, M = map(int, sys.stdin.readline().split())
    other_teams = []
    for _ in range(N):
        parts = sys.stdin.readline().strip().split()
        team_name = parts[0]
        if team_name == 'NijeZivotJedanACM':
            continue
        tasks = parts[1:]
        parsed_tasks = [parse_task(t) for t in tasks]
        other_teams.append(parsed_tasks)
    final_line = sys.stdin.readline().strip().split()
    final_tasks = final_line[1:]
    nij_tasks = [parse_task(t) for t in final_tasks]
    nij_solved = 0
    nij_penalty = 0
    for status, submissions, time in nij_tasks:
        if status == '+':
            nij_solved += 1
            nij_penalty += time + 1200 * (submissions - 1)
        elif status == '?':
            pass
    better = 0
    for team in other_teams:
        solved = 0
        penalty = 0
        possible_solved = 0
        possible_penalty = 0
        for status, submissions, time in team:
            if status == '+':
                solved += 1
                penalty += time + 1200 * (submissions - 1)
            elif status == '?':
                possible_solved += 1
                possible_penalty += time + 1200 * (submissions - 1)
        max_solved = solved + possible_solved
        min_penalty = penalty + possible_penalty
        if max_solved > nij_solved:
            better += 1
        elif max_solved == nij_solved and min_penalty < nij_penalty:
            better += 1
    print(better + 1)

if __name__ == "__main__":
    main()
