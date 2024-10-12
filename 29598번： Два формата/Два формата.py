def solve(N):
    # Bytes are retrieved from N considering N's size
    bytes = []
    while N > 0:
        bytes.append(N & 0xFF)
        N >>= 8
    
    # Construct M by reversing the byte order and forming the big-endian number
    M = 0
    for i, byte in enumerate(bytes):
        M += byte * (256**i)
    
    return M

N = int(input())
print(solve(N))