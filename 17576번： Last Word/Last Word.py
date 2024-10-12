def main():
    s = input()
    n = int(input())
    effective_start = 0
    effective_length = len(s)

    for _ in range(n):
        start, length = map(int, input().split())
        effective_start += start
        effective_length = length

    result = s[effective_start:effective_start + effective_length]

    print(result)

main()