def juggling_pattern(p, heights):
    throws = []
    balls = []
    ball_map = {}
    ball_count = 0
    time_limit = 20
    available = [None] * time_limit

    for t in range(time_limit):
        current_throw = heights[t % p]

        if available[t] is not None:
            ball = available[t]
        else:
            ball = chr(ord('A') + ball_count)
            ball_count += 1

        throws.append(ball)
        next_throw_time = t + current_throw

        if next_throw_time < time_limit:
            if available[next_throw_time] is not None:
                return "CRASH"
            available[next_throw_time] = ball

    return "".join(throws)

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    for line in data:
        if line == '0':
            break

        line_data = list(map(int, line.split()))
        p = line_data[0]
        heights = line_data[1:]

        result = juggling_pattern(p, heights)
        print(result)

if __name__ == "__main__":
    main()