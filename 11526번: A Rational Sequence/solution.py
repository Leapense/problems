import sys

def rational_to_index(p: int, q: int) -> int:
    """
    주어진 서로소 양의 정수 p, q에 대해 Calkin-Wilf 트리의 BFS 순서 인덱스 n을 반환한다.
    알고리즘:
    1. (p, q) != (1, 1)인 동안,
    - p < q: bits.append('0'), q -= p
    - p > q: bits.append('1'), p -= q
    2. bits를 뒤집은 뒤, 맨 앞에 '1'을 붙여서 이진수 문자열을 만들고,
    2진수 -> 10진수 정수로 변환하여 반환.
    """
    bits = []
    while not (p == 1 and q == 1):
        if p < q:
            bits.append('0')
            q -= p
        else:
            bits.append('1')
            p -= q

    bits.reverse()
    binary_str = '1' + ''.join(bits)

    return int(binary_str, 2)

def main():
    data = sys.stdin.read().strip().split()
    P = int(data[0])
    idx = 1

    for _ in range(P):
        K = data[idx]
        idx += 1
        frac = data[idx]
        idx += 1

        p_str, q_str = frac.split('/')
        p = int(p_str)
        q = int(q_str)

        n_val = rational_to_index(p, q)
        sys.stdout.write(f"{K} {n_val}\n")

if __name__ == "__main__":
    main()