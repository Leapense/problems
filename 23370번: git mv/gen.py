import random, string, sys

def random_dir(existing):
    while True:
        size = random.randint(1, 10)
        candidate = ''.join(random.choices(string.ascii_lowercase, k=size))
        if candidate not in existing:
            return candidate
        
def generate_path():
    count = random.randint(1, 10)
    parts = []
    for _ in range(count):
        parts.append(random_dir(parts))
    return parts

def mutate(parts):
    parts = parts[:]
    op = random.choice(('insert', 'delete', 'replace'))
    if op == 'insert' or len(parts) == 1:
        idx = random.randint(0, len(parts))
        parts.insert(idx, random_dir(parts))
    elif op == "delete":
        idx = random.randrange(len(parts))
        del parts[idx]
    else:
        idx = random.randrange(len(parts))
        parts[idx] = random_dir(parts)
    return parts

def join(parts):
    return '/'.join(parts)

def generate_pair():
    src_parts = generate_path()
    dst_parts = mutate(src_parts)
    return join(src_parts), join(dst_parts)

def main():
    cases = int(sys.argv[1]) if len(sys.argv) > 1 else 10
    random.seed()
    for idx in range(cases):
        src, dst = generate_pair()
        print(src)
        print(dst)
        if idx + 1 != cases:
            print()

if __name__ == "__main__":
    main()