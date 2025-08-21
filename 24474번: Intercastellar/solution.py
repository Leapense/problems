import sys
def solve():
    try:
        n_str = sys.stdin.readline()
        if not n_str: return
        n = int(n_str)
        a = [int(sys.stdin.readline()) for _ in range(n)]
        q = int(sys.stdin.readline())
        queries = [int(sys.stdin.readline()) for _ in range(q)]
    except (IOError, ValueError):
        return
    
    final_pieces = []
    for val in a:
        count = 1
        while val % 2 == 0:
            val //= 2
            count *= 2
        final_pieces.append({'value': val, 'count': count})

    prefix_counts = []
    current_sum = 0
    for piece in final_pieces:
        current_sum += piece['count']
        prefix_counts.append(current_sum)

    block_idx = 0
    for query_pos in queries:
        while query_pos > prefix_counts[block_idx]:
            block_idx += 1
        
        print(final_pieces[block_idx]['value'])

if __name__ == "__main__":
    solve()