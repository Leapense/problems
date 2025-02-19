import sys

def main():
    data = sys.stdin.read().split()
    n, m = int(data[0]), int(data[1])
    answer = float('inf')
    index = 2

    for i in range(m):
        u = int(data[index])
        d = int(data[index+1])
        index += 2
        x = (n * d) // (u + d) + 1
        floor_value = x * (u + d) - n * d
        answer = min(answer, floor_value)
    print(answer)

if __name__ == "__main__":
    main()