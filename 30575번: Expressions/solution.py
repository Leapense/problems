import sys

def main():
    input = sys.stdin.readline
    n, m = map(int, input().split())

    need = 2 * n - 1
    tokens = []
    while len(tokens) < need:
        line = input()
        if not line:
            break
        tokens += line.split()

    term_of = [0] * n
    arr_par = [0] * n
    cnt_even = []

    term = 0
    for i in range(n):
        a = int(tokens[2 * i])
        par = a & 1
        arr_par[i] = par
        if i > 0:
            op = tokens[2 * i - 1]
            if op == '+' or op == '-':
                term += 1
        term_of[i] = term
        if term == len(cnt_even):
            cnt_even.append(0)
        if par == 0:
            cnt_even[term] += 1
    
    odd_terms = sum(1 for c in cnt_even if c == 0)
    out = []
    out.append('odd' if (odd_terms & 1) else 'even')

    for _ in range(m):
        line = input().strip()
        while line == '':
            line = input().strip()
        x, y = map(int, line.split())
        idx = x - 1
        old_par = arr_par[idx]
        new_par = y & 1
        if old_par != new_par:
            t = term_of[idx]
            before = cnt_even[t]
            if old_par == 1 and new_par == 0:
                cnt_even[t] += 1
                if before == 0:
                    odd_terms -= 1
            else:
                cnt_even[t] -= 1
                if cnt_even[t] == 0:
                    odd_terms += 1
            arr_par[idx] = new_par
        out.append('odd' if (odd_terms & 1) else 'even')

    print('\n'.join(out))

if __name__ == "__main__":
    main()