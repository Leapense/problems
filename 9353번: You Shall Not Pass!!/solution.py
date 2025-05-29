import sys

def solve():
    A, B, C = map(int, sys.stdin.readline().split())
    adj = {i: [] for i in range(A)}

    for _ in range(B):
        F, T_node = map(int, sys.stdin.readline().split())
        adj[F].append(T_node)

    memo_subtree_sets = {}

    def get_subtree_set_for_node(u_node):
        if u_node in memo_subtree_sets:
            return memo_subtree_sets[u_node]
        
        current_s = {u_node}
        if u_node in adj:
            for v_child in adj[u_node]:
                current_s.update(get_subtree_set_for_node(v_child))

        memo_subtree_sets[u_node] = current_s
        return current_s
    
    for i in range(A):
        get_subtree_set_for_node(i)

    covered_teams = set()

    for _ in range(C):
        best_gain = -1
        best_set_to_add = None

        for team_idx in range(A):
            candidate_set = memo_subtree_sets[team_idx]
            current_gain = 0
            for team_member in candidate_set:
                if team_member not in covered_teams:
                    current_gain += 1
            
            if current_gain > best_gain:
                best_gain = current_gain
                best_set_to_add = candidate_set

        if best_gain <= 0:
            break

        covered_teams.update(best_set_to_add)

    sys.stdout.write(str(len(covered_teams)) + "\n")

num_test_cases = int(sys.stdin.readline())
for _ in range(num_test_cases):
    solve()