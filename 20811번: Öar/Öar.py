def find_last_island(N):
    if N == 1:
        return 1
    
    a, b = 1, 1
    total_lost = 2
    island_count = 2

    while total_lost < N:
        next_loss = a + b
        a = b
        b = next_loss
        island_count += 1
        total_lost += next_loss

    return island_count

N = int(input())
print(find_last_island(N))