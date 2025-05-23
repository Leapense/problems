import sys
input = sys.stdin.read
data = input().splitlines()

N, M = map(int, data[0].split())
state = list(map(int, data[1].split()))

count = 0
for i in range(N):
    if state[i] == 1 and (i == 0 or state[i - 1] == 0):
        count += 1

result = []
for line in data[2:]:
    command = line.split()
    if command[0] == "0":
        result.append(str(count))
    else:
        idx = int(command[1]) - 1
        if state[idx] == 0:
            state[idx] = 1

            left = idx > 0 and state[idx - 1] == 1
            right = idx < N - 1 and state[idx + 1] == 1

            if not left and not right:
                count += 1
            elif left and right:
                count -= 1

sys.stdout.write("\n".join(result) + "\n")