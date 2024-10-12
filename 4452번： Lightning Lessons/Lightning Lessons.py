N = int(input())

for _ in range(N):
    data = input().split()
    M = int(data[0])
    amplitudes = list(map(int, data[1:]))
    P = 0

    while True:
        if all(a == 0 for a in amplitudes):
            if P == 0:
                print("ap!")
            else:
                print("z" * P + "ap!")
            break
        if len(amplitudes) == 1 and amplitudes[0] != 0:
            if amplitudes[0] > 0:
                print("*fizzle*")
            else:
                print("*bunny*")
            break

        previous_amplitudes = amplitudes.copy()
        amplitudes = amplitudes[1:]
        amplitudes = [a - previous_amplitudes[i] for i, a in enumerate(amplitudes)]
        P += 1