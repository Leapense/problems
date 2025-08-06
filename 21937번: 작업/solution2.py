import sys

def solve() -> None:
	data = list(map(int, sys.stdin.read().split()))
	if not data:
		return
	it = iter(data)
	N = next(it)
	M = next(it)

	rev_adj = [[] for _ in range(N + 1)]
	for _ in range(M):
		a = next(it)
		b = next(it)
		rev_adj[b].append(a)
	X = next(it)

	visited = [False] * (N + 1)
	stack = [X]
	visited[X] = True
	count = 0

	while stack:
		node = stack.pop()
		for pre in rev_adj[node]:
			if not visited[pre]:
				visited[pre] = True
				count += 1
				stack.append(pre)
	sys.stdout.write(str(count))

if __name__ == "__main__":
	solve()
