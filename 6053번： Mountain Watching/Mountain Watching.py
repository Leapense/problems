def main():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))
    N = data[0]
    H = data[1:]
    if N ==0:
        print(0)
        return
    left = [1]*N
    for i in range(1,N):
        if H[i] >= H[i-1]:
            left[i] = left[i-1] +1
        else:
            left[i] =1
    right = [1]*N
    for i in range(N-2,-1,-1):
        if H[i] >= H[i+1]:
            right[i] = right[i+1] +1
        else:
            right[i] =1
    max_width = 0
    for i in range(N):
        if i ==0 or i ==N-1:
            width = left[i] + right[i] -1
            if width > max_width:
                max_width = width
        else:
            if left[i] >1 and right[i] >1:
                width = left[i] + right[i] -1
                if width > max_width:
                    max_width = width
    print(max_width)
if __name__ == "__main__":
    main()