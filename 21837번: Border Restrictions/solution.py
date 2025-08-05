import sys
from collections import deque, defaultdict

def solve():
    try:
        n_str = sys.stdin.readline()
        if not n_str:
            return
        n = int(n_str)
    except (IOError, ValueError):
        return

    graph = defaultdict(list)
    all_countries_set = set()
    first_country_input = None

    for i in range(n):
        line = sys.stdin.readline().strip()
        if not line:
            continue

        parts = line.split()
        destination = parts[0]

        if first_country_input is None:
            first_country_input = destination

        all_countries_set.add(destination)

        origins = []
        try:
            from_index = parts.index("from")
            origins = parts[from_index + 1:]
        except ValueError:
            pass

        for origin in origins:
            all_countries_set.add(origin)
            graph[origin].append(destination)

    sorted_countries = sorted(list(all_countries_set))
    arrival_weeks = {country: 0 for country in sorted_countries}

    if not first_country_input:
        return

    queue = deque()

    if first_country_input in arrival_weeks:
        arrival_weeks[first_country_input] = 1
        queue.append((first_country_input, 1))

    while queue:
        current_country, current_week = queue.popleft()
        for neighbor in graph[current_country]:
            if arrival_weeks.get(neighbor) == 0:
                arrival_weeks[neighbor] = current_week + 1
                queue.append((neighbor, current_week + 1))

    for country in sorted_countries:
        print(f"{arrival_weeks[country]}")

if __name__ == "__main__":
    solve()
