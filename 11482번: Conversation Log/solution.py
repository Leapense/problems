import sys
from collections import defaultdict
from typing import DefaultDict, Dict, Set

# ----- 상수 -----
STDIN = sys.stdin


def main() -> None:
    """표준 입력을 읽어 모든 사용자가 공통으로 사용한 단어를 찾는다."""
    # 1) 메시지 수 읽기
    first_line = STDIN.readline()
    if not first_line:
        print("ALL CLEAR")
        return

    try:
        msg_cnt = int(first_line.strip())
    except ValueError:
        print("ALL CLEAR")  # 비정상 입력 대비
        return

    # 2) 자료구조 초기화
    word_total_cnt: DefaultDict[str, int] = defaultdict(int)
    word_user_cnt: DefaultDict[str, int] = defaultdict(int)
    user_words: Dict[str, Set[str]] = {}

    # 3) 메시지 스트림 처리
    for _ in range(msg_cnt):
        line = STDIN.readline().rstrip('\n')
        if not line:
            continue                        # 빈 줄 무시
        user, *rest = line.split(maxsplit=1)
        content = rest[0] if rest else ""   # 메시지가 없을 수도 있음

        # 사용자별 단어 집합
        if user not in user_words:
            user_words[user] = set()
        seen = user_words[user]

        for word in content.split():
            word_total_cnt[word] += 1
            if word not in seen:
                seen.add(word)
                word_user_cnt[word] += 1

    # 4) 모든 사용자가 사용한 단어 추출
    total_users = len(user_words)
    commons = [
        w for w, c in word_user_cnt.items() if c == total_users
    ]

    if not commons:
        print("ALL CLEAR")
        return

    # 5) 정렬 및 출력
    commons.sort(key=lambda w: (-word_total_cnt[w], w))
    print("\n".join(commons))


if __name__ == "__main__":
    main()