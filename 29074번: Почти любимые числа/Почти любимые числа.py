def count_almost_favorites(n, m):
    if n > m:
        return 0
    
    k = len(str(n))
    divisor = 10 ** k
    count = (m - n) // divisor + 1
    return count

if __name__ == '__main__':
    import sys
    input_line = sys.stdin.read().strip()
    n, m = map(int, input_line.split())
    print(count_almost_favorites(n, m))