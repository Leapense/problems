import sys

N = int(sys.stdin.readline())

for test_case_idx in range(N):
    all_sentence = ''

    for line in sys.stdin:
        if line == '\n':
            all_sentence = all_sentence.rstrip('\n')
            break
        else:
            all_sentence += line.rstrip('\n')

    A = len(all_sentence)
    R = A - all_sentence.count('#')
    R_divide_A = round(R / A * 100, 1)

    if str(R_divide_A)[-1] == '0':
        R_divide_A = int(R_divide_A)

    print(f'Efficiency ratio is {R_divide_A}%.')
