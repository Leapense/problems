import sys

def solve():
    try:
        n_str = sys.stdin.readline().strip()
        if not n_str: return False
        n = int(n_str)
    except (IOError, ValueError):
        return False
    
    if n == 0:
        return False

    names = [sys.stdin.readline().strip() for _ in range(n)]
    names.sort()

    n1 = names[n // 2 - 1]
    n2 = names[n // 2]

    candidates = []
    if n1 < n2:
        candidates.append(n1)

    for i in range(len(n1)):
        if n1[i] < 'Z':
            prefix = n1[:i]
            char = n1[i]
            new_char = chr(ord(char) + 1)
            candidate = prefix + new_char

            if candidate < n2:
                candidates.append(candidate)

    best_s = candidates[0]
    for s in candidates[1:]:
        if len(s) < len(best_s):
            best_s = s
        elif len(s) == len(best_s) and s < best_s:
            best_s = s

    print(best_s)
    return True

def main():
    while solve():
        pass

if __name__ == "__main__":
    main()