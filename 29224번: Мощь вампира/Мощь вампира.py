import sys

def main():
    n = int(sys.stdin.readline())
    queries = []
    responses = []

    query = ['+'] * n
    print(' '.join(query))
    sys.stdout.flush()
    S1 = int(sys.stdin.readline())
    responses.append(S1)

    for i in range(1, n):
        query = ['+'] * n
        query[i] = '-'
        print(' '.join(query))
        sys.stdout.flush()
        S = int(sys.stdin.readline())
        responses.append(S)

    p = [0] * n
    for i in range(1, n):
        p[i] = (responses[0] - responses[i]) // 2

    p[0] = responses[0] - sum(p[1:])

    answer = 'answer: ' + ' '.join(map(str, p))
    print(answer)
    sys.stdout.flush()

if __name__ == '__main__':
    main()