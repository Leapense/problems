import sys
sys.setrecursionlimit(200000)

def solve() -> None:
	data = sys.stdin.read().split()
	it = iter(data)
	N = int(next(it))
	M = int(next(it))
	rev_adj = [[] for _ in range(N + 1)]
	for _ in range(M):
		a = int(next(it))
		b = int(next(it))
		rev_adj[b].append(a)
	X = int(next(it))
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
	print(count)

if __name__ == "__main__":
	solve()
