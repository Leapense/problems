import math

def truncated_binary_encoding(m):
    n = math.ceil(math.log2(m))
    total_bits = 2 ** n
    k = total_bits - m
    
    codes = []

    for i in range(k):
        code = format(i, f'0{n-1}b')
        codes.append(code)

    start = total_bits - (m - k)
    for i in range(start, total_bits):
        code = format(i, f'0{n}b')
        codes.append(code)

    return codes

def main():
    import sys
    input = sys.stdin.read
    m = int(input())

    encoded_codes = truncated_binary_encoding(m)

    for code in encoded_codes:
        print(code)

if __name__ == '__main__':
    main()