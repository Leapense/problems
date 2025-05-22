import sys
from collections import deque

NUM_MAX_COUNTRIES = 20
NUM_BOARD_INPUT_LINES = 19

def bfs_shortest_path(start_node, end_node, adj_list):
    distances = [-1] * (NUM_MAX_COUNTRIES + 1)

    if start_node == end_node:
        return 0
    
    queue = deque()

    distances[start_node] = 0
    queue.append(start_node)

    while queue:
        current_country = queue.popleft()
        if current_country == end_node:
            return distances[current_country]
        
        for neighbor in adj_list[current_country]:
            if distances[neighbor] == -1:
                distances[neighbor] = distances[current_country] + 1
                queue.append(neighbor)

    return -1

def solve_risk_problem():
    test_set_counter = 0
    while True:
        test_set_counter += 1

        adj = [[] for _ in range(NUM_MAX_COUNTRIES + 1)]

        first_connection_line = sys.stdin.readline()
        if not first_connection_line:
            break

        parts = list(map(int, first_connection_line.split()))
        for neighbor_country in parts[1:]:
            adj[1].append(neighbor_country)
            adj[neighbor_country].append(1)

        for country_id in range(2, NUM_BOARD_INPUT_LINES + 1):
            connection_line = sys.stdin.readline()
            if not connection_line:
                return
            
            parts = list(map(int, connection_line.split()))
            for neighbor_country in parts[1:]:
                adj[country_id].append(neighbor_country)
                adj[neighbor_country].append(country_id)

        num_queries_line = sys.stdin.readline()
        if not num_queries_line:
            return
        num_queries = int(num_queries_line.strip())

        print(f"Test Set #{test_set_counter}")

        for _ in range(num_queries):
            query_pair_line = sys.stdin.readline()
            if not query_pair_line:
                return
            
            start_country, end_country = map(int, query_pair_line.split())
            num_conquests = bfs_shortest_path(start_country, end_country, adj)

            start_country_str = str(start_country).rjust(2)
            end_country_str = str(end_country).rjust(2)

            print(f"{start_country_str} to {end_country_str}: {num_conquests}")
        
        print()

if __name__ == "__main__":
    solve_risk_problem()