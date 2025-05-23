def solve():
    import sys
    sys.setrecursionlimit(1000000)
    h, w = map(int, sys.stdin.readline().split())
    grid = [list(map(int, sys.stdin.readline().split())) for _ in range(h)]
    selected_rows = [i for i in range(h) if all(cell == 1 for cell in grid[i])]
    selected_columns = [j for j in range(w) if all(grid[i][j] == 1 for i in range(h))]
    sets = []
    labels = []
    for r in selected_rows:
        bitmask = 0
        for j in range(w):
            bitmask |= (1 << (r * w + j))
        sets.append(bitmask)
        labels.append(-(r + 1))
    for c in selected_columns:
        bitmask = 0
        for i in range(h):
            bitmask |= (1 << (i * w + c))
        sets.append(bitmask)
        labels.append(c + 1)
    remaining = 0
    for i in range(h):
        for j in range(w):
            if grid[i][j] == 1:
                remaining |= (1 << (i * w + j))
    cell_to_sets = [[] for _ in range(h * w)]
    for s, bitmask in enumerate(sets):
        x = bitmask
        while x:
            lsb = x & -x
            idx = (lsb).bit_length() - 1
            cell_to_sets[idx].append(s)
            x &= x - 1
    for i in range(h):
        for j in range(w):
            if grid[i][j] == 1:
                cell = i * w + j
                if not cell_to_sets[cell]:
                    print(-1)
                    return
    current_min = h + w + 1
    best_solution = []
    def recurse(remaining, selected_sets, current_count):
        nonlocal current_min, best_solution
        if remaining == 0:
            if current_count < current_min:
                current_min = current_count
                best_solution = selected_sets.copy()
            return
        if current_count >= current_min:
            return
        min_options = float('inf')
        chosen_cell = -1
        cell = 0
        while cell < h * w:
            if (remaining >> cell) & 1:
                options = len(cell_to_sets[cell])
                if options < min_options:
                    min_options = options
                    chosen_cell = cell
                    if min_options == 1:
                        break
            cell += 1
        if chosen_cell == -1:
            return
        for s in cell_to_sets[chosen_cell]:
            if (sets[s] & remaining) == 0:
                continue
            selected_sets.append(s)
            new_remaining = remaining & ~sets[s]
            recurse(new_remaining, selected_sets, current_count + 1)
            selected_sets.pop()
    recurse(remaining, [], 0)
    if best_solution:
        print(current_min)
        print(' '.join(str(labels[s]) for s in best_solution))
    else:
        print(-1)

solve()