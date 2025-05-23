def solve():
    import sys
    from collections import defaultdict
    
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    s = data[1]
    
    # Dictionary to store the last positions of each character
    mp = {}
    for i in range(n):
        mp[s[i]] = i + 1  # Store positions as 1-based index

    # If there's only one unique character
    if len(mp) == 1:
        print("No")
    else:
        # Extract the first two unique characters and their positions
        keys = list(mp.keys())
        print("Yes")
        print(mp[keys[0]], mp[keys[1]], 1)

if __name__ == "__main__":
    solve()