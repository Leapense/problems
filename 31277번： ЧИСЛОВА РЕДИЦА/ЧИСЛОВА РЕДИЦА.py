def main():
    import sys
    input = sys.stdin.read().split()
    N = int(input[0])
    sequence = list(map(int, input[1:N+1]))

    max_length = 1
    current_length = 1
    for i in range(1, N):
        if sequence[i] == sequence[i - 1]:
            current_length += 1
            if current_length > max_length:
                max_length = current_length
        else:
            current_length = 1

    required_numbers = {1, 2, 4, 8}
    quadruple_count = 0

    if N >= 4:
        freq = {1:0, 2:0, 4:0, 8:0}
        for i in range(4):
            if sequence[i] in freq:
                freq[sequence[i]] += 1
        if all(freq[num] >= 1 for num in required_numbers):
            quadruple_count += 1

        for i in range(4, N):
            exiting = sequence[i - 4]
            if exiting in freq:
                freq[exiting] -= 1
            entering = sequence[i]
            if entering in freq:
                freq[entering] += 1
            if all(freq[num] >= 1 for num in required_numbers):
                quadruple_count += 1

    print(max_length, quadruple_count)

if __name__ == '__main__':
    main()