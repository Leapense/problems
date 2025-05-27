import sys
input_ = sys.stdin.readline

def count_reachable_pairs(n, edges):
    reach = [1 << i for i in range(n)]
    for u, v in edges:
        reach[u] |= (1 << v)
    
    for k in range(n):
        mask_k = reach[k]
        bit_k = 1 << k
        for i in range(n):
            if reach[i] & bit_k:
                reach[i] |= mask_k

    total = 0
    for i in range(n):
        total += bin(reach[i]).count('1') - 1

    return total

def main():
    t = int(input_())
    outputs = []
    for _ in range(t):
        n, m = map(int, input_().split())
        edges = []
        for _ in range(m):
            a, b = map(int, input_().split())
            edges.append((a - 1, b - 1))
        outputs.append(str(count_reachable_pairs(n, edges)))
    sys.stdout.write("\n".join(outputs))

if __name__ == "__main__":
    main()