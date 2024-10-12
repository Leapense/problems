def smallest_number(x, y, z):
    digits = sorted([x, y, z])
    
    if digits[0] == 0:
        # Find the first non-zero digit and swap with the first position
        for i in range(1, 3):
            if digits[i] != 0:
                digits[0], digits[i] = digits[i], digits[0]
                break
    
    # Convert list of digits to a string and then to an integer
    result = int(''.join(map(str, digits)))
    return result

# Reading input and invoking the function
def main():
    x, y, z = map(int, input().split())
    print(smallest_number(x, y, z))

# Sample usage with example input
if __name__ == "__main__":
    main()