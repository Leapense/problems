import sys
from typing import List

def build_levels(inorder: List[int], start: int, end: int, depth: int, levels: List[List[int]]) -> None:
    """
    inorder 배열의 인덱스 범위 [start, end]에 해당하는 서브트리를
    깊이 depth로 재귀적으로 분할하여 노드 값을 levels[depth]에 추가한다.
    """
    if start > end:
        return
    
    mid = (start + end) // 2
    root_value = inorder[mid]
    levels[depth].append(root_value)

    # 왼쪽 서브트리 재귀
    build_levels(inorder, start, mid - 1, depth + 1, levels)
    # 오른쪽 서브트리 재귀
    build_levels(inorder, mid + 1, end, depth + 1, levels)

def main():
    k = int(sys.stdin.readline().strip())
    total_nodes = (1 << k) - 1
    inorder = list(map(int, sys.stdin.readline().split()))

    levels: List[List[int]] = [[] for _ in range(k)]
    build_levels(inorder, 0, total_nodes - 1, 0, levels)

    output_lines = []
    for depth in range(k):
        line = " ".join(map(str, levels[depth]))
        output_lines.append(line)

    sys.stdout.write("\n".join(output_lines))

if __name__ == "__main__":
    main()