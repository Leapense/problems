import sys

def main():
    import sys
    from collections import defaultdict

    # Read all input lines
    input = sys.stdin.read().splitlines()
    if not input:
        return

    N = int(input[0])
    tag_counts = defaultdict(int)

    for i in range(1, N+1):
        line = input[i].strip()
        if not line:
            continue
        tokens = line.split()
        if len(tokens) < 2:
            continue
        s = tokens[0]  # Problem number, not used
        t = int(tokens[1])
        tags = tokens[2:2+t]
        for tag in tags:
            tag_counts[tag] +=1

    if not tag_counts:
        print(-1)
        return

    # Find the maximum frequency
    max_freq = max(tag_counts.values())

    # Collect all tags with maximum frequency
    max_tags = [tag for tag, count in tag_counts.items() if count == max_freq]

    if len(max_tags) ==1:
        print(max_tags[0])
    else:
        print(-1)

if __name__ == "__main__":
    main()