def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    a = int(data[0])
    b = int(data[1])
    index = 2
    ab = []
    
    # Create the transformed matrix directly from input
    for i in range(b):
        row = []
        for j in range(a):
            row.append(int(data[index]))
            index += 1
        ab.append(row)
    
    # Determine if the cat can eat the food
    food = True
    
    # Compare with the student's given food matrix
    for i in range(a):
        for j in range(b):
            n = int(data[index])
            index += 1
            
            # Check if the current element matches
            if ab[b - 1 - j][i] != n:
                food = False
                break
        if not food:
            break

    # Output the result
    if food:
        print("|>___/|        /}")
        print("| O < |       / }")
        print("(==0==)------/ }")
        print("| ^  _____    |")
        print("|_|_/     ||__|")
    else:
        print("|>___/|     /}")
        print("| O O |    / }")
        print("( =0= )\"\"\"\"  \\")
        print("| ^  ____    |")
        print("|_|_/    ||__|")

if __name__ == "__main__":
    main()
