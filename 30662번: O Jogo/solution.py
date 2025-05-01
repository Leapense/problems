import sys
from collections import defaultdict

def process(lines):
    outputs = []
    idx = 0
    n_lines = len(lines)

    while True:
        while idx < n_lines and lines[idx].strip() == "":
            idx += 1
        if idx >= n_lines:
            break

        try:
            n = int(lines[idx].strip())
        except ValueError:
            idx += 1
            continue
        idx += 1
        if n == 0:
            break

        followers = defaultdict(set)
        last_day = {}
        count = {}

        def ensure_user(u):
            if u not in last_day:
                last_day[u] = -1
                count[u] = 0

        for _ in range(n):
            while idx < n_lines and lines[idx].strip() == "":
                idx += 1
            if idx >= n_lines:
                break

            day_str, rest = lines[idx].split(' ', 1)
            day = int(day_str)
            idx += 1

            if rest.startswith('SUBSCRIBE'):
                _, users_str = rest.split(' ', 1)
                a, b = [u.strip() for u in users_str.split(',')]
                ensure_user(a)
                ensure_user(b)
                followers[b].add(a)

            elif rest.startswith('UNSUBSCRIBE'):
                _, users_str = rest.split(' ', 1)
                a, b = [u.strip() for u in users_str.split(',')]
                ensure_user(a)
                ensure_user(b)
                followers[b].discard(a)

            elif rest.startswith('PUBLISH'):
                _, author = rest.split(' ', 1)
                author = author.strip()
                ensure_user(author)
                if last_day[author] != day:
                    last_day[author] = day
                    count[author] += 1
                for follower in followers.get(author, ()):
                    ensure_user(follower)
                    if last_day[follower] != day:
                        last_day[follower] = day
                        count[follower] += 1

            else:
                continue

        if count:
            min_count = min(count.values())
            winners = sorted(u for u, c in count.items() if c == min_count)
            outputs.append(' '.join(winners))
        else:
            outputs.append('')

    return outputs

def main():
    data = sys.stdin.read().splitlines()
    for line in process(data):
        print(line)

if __name__ == "__main__":
    main()