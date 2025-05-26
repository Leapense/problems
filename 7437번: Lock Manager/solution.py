import sys
from collections import defaultdict
from typing import Dict, List, Set, Tuple

LockInfo = Tuple[int, str]

def main() -> None:
    """
    표준 입력으로부터 잠금 요청을 읽어 처리 결과를 출력한다.
    """
    granted_locks: Dict[int, List[LockInfo]] = defaultdict(list)
    blocked_tx: Set[int] = set()

    for line in sys.stdin:
        line = line.strip()
        if line == '#' or not line:
            break

        mode, tx_str, item_str = line.split()
        tx_id = int(tx_str)
        item_id = int(item_str)

        if tx_id in blocked_tx:
            print("IGNORED")
            continue

        if has_conflict(granted_locks[item_id], tx_id, mode):
            print("DENIED")
            blocked_tx.add(tx_id)
            continue

        granted_locks[item_id].append((tx_id, mode))
        print("GRANTED")

def has_conflict(existing: List[LockInfo], tx_id: int, mode: str) -> bool:
    """
    기존에 승인된 잠금 목록(existing)과 비교해
    (tx_id, mode) 요청이 충돌하는지 여부를 반환.
    """
    for other_tx, other_mode in existing:
        if other_tx != tx_id and (mode == 'X' or other_mode == 'X'):
            return True
    return False

if __name__ == '__main__':
    main()