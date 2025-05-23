def compute_visible_from_left(seq):
    count = 0
    current_max = 0
    for h in seq:
        if h > current_max:
            count +=1
            current_max = h
    return count

def compute_visible_from_right(seq):
    count =0
    current_max =0
    for h in reversed(seq):
        if h > current_max:
            count +=1
            current_max = h
    return count

def compute_visible_to_both(seq):
    N = len(seq)
    max_left = [0]*N
    max_so_far =0
    for i in range(N):
        if seq[i] > max_so_far:
            max_left[i]=1
            max_so_far=seq[i]
    max_right = [0]*N
    max_so_far =0
    for i in range(N-1,-1,-1):
        if seq[i] > max_so_far:
            max_right[i]=1
            max_so_far=seq[i]
    C=0
    for i in range(N):
        if max_left[i]==1 and max_right[i]==1:
            C +=1
    return C

def solve_case(N, A, B, C):
    if C > min(A, B):
        return "IMPOSSIBLE"
    if A + B - C > N:
        return "IMPOSSIBLE"
    if A + B - C ==N and C >1:
        return "IMPOSSIBLE"
    # Assign heights
    left_part_start = 1 + N - (A + B - C)
    left_visible = A - C
    right_visible = B - C
    if left_visible <0 or right_visible <0:
        return "IMPOSSIBLE"
    left_part = []
    for i in range(left_visible):
        left_part.append(left_part_start +i)
    right_part = []
    for i in range(right_visible):
        right_part.append(left_part_start + left_visible +i)
    common_part = [N]*C
    remaining = N - (A + B - C)
    remaining_part = [1]*remaining
    sequence = left_part + remaining_part + common_part + right_part
    # Verify
    visible_left = compute_visible_from_left(sequence)
    visible_right = compute_visible_from_right(sequence)
    visible_both = compute_visible_to_both(sequence)
    if visible_left == A and visible_right == B and visible_both ==C:
        return ' '.join(map(str, sequence))
    else:
        return "IMPOSSIBLE"

T=int(input())
for test_case in range(1, T+1):
    N,A,B,C = map(int, input().split())
    result = solve_case(N, A, B, C)
    print(f"Case #{test_case}: {result}")
