def extract_code(name, k):
    code = []
    code.append(name[0])
    for i in range(1, len(name)):
        if name[i-1] in "aiueo":
            code.append(name[i])
    return "".join(code)[:k]

def is_unique_code(names, k):
    seen = set()
    for name in names:
        code = extract_code(name, k)
        if code in seen:
            return False
        seen.add(code)
    return True

def find_minimum_k(names):
    for k in range(1, 51):
        if is_unique_code(names, k):
            return k
    return -1

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    i = 0
    results = []
    while i < len(data):
        if data[i] == "0":
            break
    
        n = int(data[i])
        names = data[i+1:i+1+n]
        
        result = find_minimum_k(names)
        results.append(result)

        i += 1 + n
    for res in results:
        print(res)

if __name__ == "__main__":
    main()