N = int(input())
for _ in range(N):
    num_str = input()
    num = int(num_str)
    if num_str == num_str[::-1]:
        print(num_str)
    else:
        base = int(num_str[:3])
        candidates = []
        for b in [base - 1, base, base + 1]:
            if 100 <= b <= 999:
                palindrome = int(str(b) + str(b)[::-1])
                candidates.append(palindrome)
        min_diff = float('inf')
        closest = None
        for p in candidates:
            diff = abs(num - p)
            if diff < min_diff or (diff == min_diff and p < closest):
                min_diff = diff
                closest = p
        print("{:06d}".format(closest))