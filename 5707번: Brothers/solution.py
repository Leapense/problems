import sys
input = sys.stdin.readline

def simulate_battles(N, R, C, K, grid):
    # Directions: up, down, left, right
    dr = (-1, 1, 0, 0)
    dc = (0, 0, -1, 1)
    
    for _ in range(K):
        # Prepare next grid as a fresh copy
        next_grid = [row[:] for row in grid]
        
        for r in range(R):
            for c in range(C):
                curr = grid[r][c]
                # Who can conquer this county?
                attacker = (curr - 1) % N
                # Check all four neighbors
                for d in range(4):
                    nr, nc = r + dr[d], c + dc[d]
                    if 0 <= nr < R and 0 <= nc < C:
                        if grid[nr][nc] == attacker:
                            next_grid[r][c] = attacker
                            break
        
        grid = next_grid
    
    return grid

def main():
    while True:
        N, R, C, K = map(int, input().split())
        if N == 0 == R == C == K:
            break
        
        grid = [list(map(int, input().split())) for _ in range(R)]
        result = simulate_battles(N, R, C, K, grid)
        
        # Output result
        for row in result:
            print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()
