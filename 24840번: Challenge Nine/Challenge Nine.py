def solve():
    import sys
    input = sys.stdin.read().split()
    T = int(input[0])
    cases = input[1:T+1]
    for case_num in range(1, T+1):
        N = cases[case_num - 1]
        S = sum(int(c) for c in N)
        possible_Ds = []
        if S % 9 == 0:
            possible_Ds = [0, 9]
        else:
            required = (9 - (S % 9))
            possible_Ds = [required]
        candidates = []

        for D in possible_Ds:
            if D == 0:
                s = N
                candidate = None
                found = False
                for i in range(1, len(s) + 1):
                    if i == len(s):
                        candidate = s + '0'
                        found = True
                        break
                    current_digit = s[i]
                    if current_digit > '0':
                        candidate = s[:i] + '0' + s[i:]
                        found = True
                        break
                if not found:
                    candidate = s + '0'
                candidates.append(candidate)
            else:
                D_char = str(D)
                s = N
                insert_pos = len(s)
                for i in range(len(s)):
                    if s[i] > D_char:
                        insert_pos = i
                        break
                candidate = s[:insert_pos] + D_char + s[insert_pos:]
                candidates.append(candidate)
        min_candidate = min(candidates)
        print(f"Case #{case_num}: {min_candidate}")

if __name__ == "__main__":
    solve()