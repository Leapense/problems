import sys

def max_team_score() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    n, a, _ = data[0:3]
    physics_scores = data[3:3+n]
    biology_scores = data[3+n:3+2*n]
    base = sum(biology_scores)
    deltas = sorted((p - b for p, b in zip(physics_scores, biology_scores)), reverse=True)
    answer = base + sum(deltas[:a])
    print(answer)

if __name__ == "__main__":
    max_team_score()