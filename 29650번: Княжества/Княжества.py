import sys
from collections import deque

class Prince:
    def __init__(self, name):
        self.name = name
        self.children = []
        self.alive = True

def main():
    import sys
    sys.setrecursionlimit(10000)
    input = sys.stdin.read
    data = input().splitlines()

    n = int(data[0])
    events = data[1:]

    princes = {}
    em = Prince("M")
    princes["M"] = em

    results = []

    for event in events:
        if event.startswith('+'):
            _, father_name, son_name = event.split()
            if father_name in princes:
                father = princes[father_name]
                son = Prince(son_name)
                father.children.append(son)
                princes[son_name] = son
            else:
                pass
        elif event.startswith('-'):
            _, name = event.split()
            if name in princes:
                princes[name].alive = False
            else:
                pass
        elif event.startswith('?'):
            _, k_str = event.split()
            k = int(k_str)
            queue = deque()
            queue.append(princes["M"])
            alive_princes = []
            while queue and len(alive_princes) < k:
                current = queue.popleft()
                if current.alive:
                    alive_princes.append(current.name)
                for child in current.children:
                    queue.append(child)
            if len(alive_princes) >= k:
                results.append(alive_princes[k - 1])
            else:
                results.append("-")

    print("\n".join(results))

if __name__ == "__main__":
    main()