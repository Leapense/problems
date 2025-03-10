def parse(s):
    if s == "{}":
        return 0
    inner = s[1:-1]
    elements = []
    current = ""
    level = 0

    for char in inner:
        if char == '{':
            level += 1
        elif char == '}':
            level -= 1
        if char == ',' and level == 0:
            elements.append(current)
            current = ""
        else:
            current += char
    if current:
        elements.append(current)
    return len(elements)

def represent(n):
    if n == 0:
        return "{}"
    return "{" + ",".join(represent(i) for i in range(n)) + "}"

def main():
    import sys
    input = sys.stdin.readline
    t = int(input().strip())
    for _ in range(t):
        a = input().strip()
        b = input().strip()
        num_a = parse(a)
        num_b = parse(b)
        print(represent(num_a + num_b))

if __name__ == "__main__":
    main()