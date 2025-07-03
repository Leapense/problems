import sys

ALPHABET_SIZE = 26

def index_of(char: str) -> int:
    return ord(char) - ord('a')

def build_reachability_matrix(size: int) -> list[list[bool]]:
    return [[False] * size for _ in range(size)]

def floyd_warshall(matrix: list[list[bool]], size: int) -> None:
    for k in range(size):
        row_k = matrix[k]
        for i in range(size):
            if matrix[i][k]:
                row_i = matrix[i]
                for j in range(size):
                    if row_k[j]:
                        row_i[j] = True

def answer_queries(matrix: list[list[bool]], stdin: list[str]) -> list[str]:
    outputs: list[str] = []
    for line in stdin:
        if not line.strip():
            continue

        parts = line.strip().split()
        source = index_of(parts[0])
        target = index_of(parts[2])
        outputs.append('T' if matrix[source][target] else 'F')
    return outputs

def main() -> None:
    lines = sys.stdin.read().splitlines()
    pointer = 0

    num_premises = int(lines[pointer].strip())
    pointer += 1

    reachability = build_reachability_matrix(ALPHABET_SIZE)

    for _ in range(num_premises):
        premise_parts = lines[pointer].strip().split()
        pointer += 1
        a_idx = index_of(premise_parts[0])
        b_idx = index_of(premise_parts[2])
        reachability[a_idx][b_idx] = True

    floyd_warshall(reachability, ALPHABET_SIZE)
    num_queries = int(lines[pointer].strip())
    pointer += 1

    result = answer_queries(reachability, lines[pointer:pointer + num_queries])
    sys.stdout.write('\n'.join(result))

if __name__ == "__main__":
    main()