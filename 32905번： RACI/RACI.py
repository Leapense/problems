def solve():
    n, m = map(int, input().split())
    matrix = [input().split() for _ in range(n)]
    
    for row in matrix:
        # Count the number of 'A' in each row
        a_count = row.count('A')
        
        # If there's not exactly one 'A' in the row, the matrix is incorrect
        if a_count != 1:
            print("No")
            return
    
    # If all rows have exactly one 'A', the matrix is correct
    print("Yes")

solve()