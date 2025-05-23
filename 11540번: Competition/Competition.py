import sys

def main():
    sys.setrecursionlimit(1 << 25)
    N, A, B = map(int, sys.stdin.readline().split())
    alice = list(map(int, sys.stdin.readline().split()))
    bob = list(map(int, sys.stdin.readline().split()))
    alice_set = set(alice)
    bob_set = set(bob)
    solvable = sorted(alice_set.union(bob_set))
    prev_A = prev_B = float('inf')
    first = True

    for p in solvable:
        can_A = p in alice_set
        can_B = p in bob_set

        if first:
            current_A = 0 if can_A else float('inf')
            current_B = 0 if can_B else float('inf')
            first = False
        else:
            temp_A = min(prev_A if can_A else float('inf'), prev_B + 1 if can_A else float('inf'))
            temp_B = min(prev_B if can_B else float('inf'), prev_A + 1 if can_B else float('inf'))
            current_A = temp_A if can_A else float('inf')
            current_B = temp_B if can_B else float('inf')
        prev_A, prev_B = current_A, current_B
    result = min(prev_A, prev_B)
    print(int(result) if result != float('inf') else 0)
if __name__ == '__main__':
    main()