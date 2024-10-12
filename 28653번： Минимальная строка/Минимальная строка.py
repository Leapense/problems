import sys
input = sys.stdin.read

def minimal_string():
    data = input().split()
    a = data[0]
    b = data[1]

    combined = a + b
    sorted_combined = sorted(combined)

    result = ''.join(sorted_combined[:len(a)])
    print(result)

if __name__ == "__main__":
    minimal_string()