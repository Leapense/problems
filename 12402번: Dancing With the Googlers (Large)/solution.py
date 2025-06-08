def precompute_triplet_possibilities():
    best = [[[False, False] for _ in range(11)] for _ in range(31)]
    for a in range(11):
        for b in range(11):
            for c in range(11):
                total = a + b + c
                mx = max(a, b, c)
                mn = min(a, b, c)
                if mx - mn > 2:
                    continue
                is_surprise = (mx - mn == 2)
                for p in range(0, 11):
                    if mx >= p:
                        if is_surprise:
                            best[total][p][1] = True
                        else:
                            best[total][p][0] = True
    
    return best

def solve(test_cases):
    best = precompute_triplet_possibilities()
    results = []
    for case_idx, (N, S, p, totals) in enumerate(test_cases):
        definite = 0
        surprise_needed = 0
        for t in totals:
            if best[t][p][0]:
                definite += 1
            elif best[t][p][1]:
                surprise_needed += 1
        answer = definite + min(S, surprise_needed)
        results.append(f"Case #{case_idx + 1}: {answer}")
    return results

def parse_input():
    import sys
    T = int(sys.stdin.readline())
    test_cases = []
    for _ in range(T):
        parts = list(map(int, sys.stdin.readline().strip().split()))
        N = parts[0]
        S = parts[1]
        p = parts[2]
        totals = parts[3:]
        test_cases.append((N, S, p, totals))
    return test_cases

if __name__ == "__main__":
    test_cases = parse_input()
    answers = solve(test_cases)
    for ans in answers:
        print(ans)