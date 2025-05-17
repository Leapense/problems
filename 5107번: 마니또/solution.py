def count_manitto_chains(n, relations):
    name_to_idx = {}
    for i, (a, b) in enumerate(relations):
        name_to_idx[a] = i

    graph = [0] * n
    for i, (a, b) in enumerate(relations):
        graph[i] = name_to_idx[b]

    state = [0] * n
    cycle_count = 0

    def dfs(u):
        nonlocal cycle_count
        state[u] = 1
        v = graph[u]
        if state[v] == 0:
            dfs(v)
        elif state[v] == 1:
            cycle_count += 1
        state[u] = 2
    
    for i in range(n):
        if state[i] == 0:
            dfs(i)
    
    return cycle_count

def main():
    case_num = 1
    while True:
        n = int(input())
        if n == 0:
            break
        relations = [tuple(input().split()) for _ in range(n)]
        result = count_manitto_chains(n, relations)
        print(case_num, result)
        case_num += 1

if __name__ == "__main__":
    main()