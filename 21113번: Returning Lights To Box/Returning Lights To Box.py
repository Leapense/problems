def earliest_time_to_off(N, M, a, b):
    count = sum(a)
    if count == 0:
        return 0
    
    c = a.copy()
    for t in range(1, M + 1):
        i = b[t - 1] - 1
        if c[i] == 1:
            count -= 1
        else:
            count += 1

        c[i] ^= 1
        if count <= t:
            return t
        
    return count

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    M = int(data[1])
    a = list(map(int, data[2:2+N]))
    b = list(map(int, data[2+N:2+N+M]))
    print(earliest_time_to_off(N, M, a, b))