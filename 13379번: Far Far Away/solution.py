from collections import defaultdict, deque
import sys
from typing import DefaultDict, List, Tuple

def readInts() -> List[int]:
    """
    Reads a line of input and splits it into a list of integers.

    Returns:
        list[int]: A list of integers read from stdin.
    """
    return list(map(int, sys.stdin.readline().split()))

def longestPathFromRoot(cityCount: int, edges: List[Tuple[int, int, int]]) -> int:
    """
    Calculates the longest path from the root city (assumed to be city 1) in a directed, weighted graph.

    Args:
        cityCount (int): The number of cities (nodes) in the graph.
        edges (List[Tuple[int, int, int]]): A list of edges where each edge is represented
            as a tuple (parent, child, weight), indicating a directed edge from 'parent' to 'child'
            with the given 'weight'.

    Returns:
        int: The maximum distance from the root city to any other city in the graph.
    """

    adjacency: DefaultDict[int, List[Tuple[int, int]]] = defaultdict(list)
    for parent, child, weight in edges:
        adjacency[parent].append((child, weight))

    queue: deque[Tuple[int, int]] = deque([(1, 0)])
    maxDistance: int = 0

    while queue:
        city, distanceSoFar = queue.popleft()
        if distanceSoFar > maxDistance:
            maxDistance = distanceSoFar

        for child, weight in adjacency.get(city, []):
            queue.append((child, distanceSoFar + weight))

    return maxDistance

def processTestCases() -> None:
    """
    Reads the input for multiple test cases, calculates the longest path from the root city to any other city
    in each test case, and outputs the longest path if it is longer than or equal to the given threshold,
    otherwise outputs -1.

    Input:
        The first line contains the number of test cases.
        Each test case consists of the following:
            - The number of cities and the threshold.
            - The directed, weighted graph represented as a list of edges, where each edge is represented
              as three space-separated integers: the parent city, the child city, and the weight of the edge.

    Output:
        The longest path from the root city to any other city in each test case, or -1 if the longest path
        is shorter than the given threshold.

    Note:
        The root city is assumed to be city 1.
    """
    testCaseCount = int(sys.stdin.readline())
    answers: List[str] = []

    for _ in range(testCaseCount):
        cityCount, threshold = readInts()
        edgeList: List[Tuple[int, int, int]] = [tuple(readInts()) for _ in range(cityCount - 1)]
        longestPath = longestPathFromRoot(cityCount, edgeList)
        answers.append(str(longestPath if longestPath >= threshold else -1))

    sys.stdout.write("\n".join(answers))

def main() -> None:
    """
    The entry point of the program.

    Reads input from stdin for multiple test cases and outputs the longest path from the root city to any
    other city in each test case, or -1 if the longest path is shorter than the given threshold.
    """
    processTestCases()

if __name__ == "__main__":
    main()