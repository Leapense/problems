from collections import defaultdict, deque

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

def get_primes_up_to(n):
    primes = []
    for i in range(2, n + 1):
        if is_prime(i):
            primes.append(i)
    return primes

def bfs_order(n, edges):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * (n + 1)
    order = []
    queue = deque([1])
    visited[1] = True

    while queue:
        node = queue.popleft()
        order.append(node)
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)
        
    return order

def relabel_tree(n, edges):
    order = bfs_order(n, edges)
    labels = [0] * (n + 1)

    primes = get_primes_up_to(n)
    non_primes = [i for i in range(1, n + 1) if i not in primes]

    label_index = 0
    prime_index = 0
    non_prime_index = 0

    for node in order:
        if prime_index < len(primes):
            labels[node] = primes[prime_index]
            prime_index += 1
        else:
            labels[node] = non_primes[non_prime_index]
            non_prime_index += 1
    
    return labels[1:]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        edges = [tuple(map(int, input().split())) for _ in range(n - 1)]
        result = relabel_tree(n, edges)
        print(*result)

main()