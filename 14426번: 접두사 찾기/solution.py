from __future__ import annotations
from dataclasses import dataclass, field
from typing import Dict, List
import sys

@dataclass
class TrieNode:
    children: Dict[str, int] = field(default_factory=dict)

class Trie:
    def __init__(self) -> None:
        self.nodes: List[TrieNode] = [TrieNode()]

    def insert(self, word: str) -> None:
        current: int = 0
        for char in word:
            next_idx: int | None = self.nodes[current].children.get(char)
            if next_idx is None:
                next_idx = len(self.nodes)
                self.nodes.append(TrieNode())
                self.nodes[current].children[char] = next_idx
            current = next_idx

    def is_prefix(self, word: str) -> bool:
        current: int = 0
        for char in word:
            next_idx: int | None = self.nodes[current].children.get(char)
            if next_idx is None:
                return False
            current = next_idx
        return True
    
def main() -> None:
    n_m = sys.stdin.readline().strip()
    while not n_m:
        n_m = sys.stdin.readline().strip()
    n_str, m_str = n_m.split()
    n, m = int(n_str), int(m_str)

    trie = Trie()
    for _ in range(n):
        s = sys.stdin.readline().rstrip('\n')
        trie.insert(s)

    answer: int = 0
    for _ in range(m):
        q = sys.stdin.readline().rstrip('\n')
        if trie.is_prefix(q):
            answer += 1

    print(answer)

if __name__ == "__main__":
    main()