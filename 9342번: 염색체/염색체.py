import sys
import re

def main():
    pattern = re.compile(r'^[ABCDEF]?A+F+C+[ABCDEF]?$')
    input = sys.stdin.read().splitlines()
    if not input:
        return
    T = int(input[0])
    lines = input[1:]
    while len(lines) < T:
        lines += sys.stdin.read().splitlines()
    for i in range(T):
        s = lines[i].strip()
        if pattern.match(s):
            print("Infected!")
        else:
            print("Good")

if __name__ == '__main__':
    main()