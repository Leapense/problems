def time_to_minutes(time_str):
    hours, minutes = map(int, time_str.split(':'))
    return hours * 60 + minutes

import sys

def main():
    input_data = sys.stdin.read().strip().splitlines()
    if not input_data:
        return
    
    S, E, Q = input_data[0].split()
    S = time_to_minutes(S)
    E = time_to_minutes(E)
    Q = time_to_minutes(Q)

    entered = set()
    exited = set()

    for line in input_data[1:]:
        time_str, nickname = line.split()
        t = time_to_minutes(time_str)
        if t <= S:
            entered.add(nickname)
        if E <= t <= Q:
            exited.add(nickname)

    result = len(entered & exited)
    print(result)

if __name__ == "__main__":
    main()