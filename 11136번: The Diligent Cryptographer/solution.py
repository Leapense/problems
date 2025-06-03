import sys
from typing import Optional

ALPHABET_START = ord('A')
ALPHABET_END = ord('Z')

def can_be_old_system(key: str) -> bool:
    length = len(key)
    max_char_code = max(ord(ch) for ch in key)
    min_m_required = max_char_code - ALPHABET_START + 1

    for m in range(min_m_required, 27):
        if length < m:
            if len(set(key)) < length:
                continue
        else:
            first_block = key[:m]
            if len(set(first_block)) < m:
                continue

        if length > m:
            mismatch_found = False
            for i in range(m, length):
                if key[i] != key[i - m]:
                    mismatch_found = True
                    break
            if mismatch_found:
                continue
        
        return True
    return False

def main() -> None:
    """
    표준 입력으로 T, 이후 T개의 key 문자열을 읽어들여 각각 분류 결과를 출력한다.
    구 시스템 가능 여부를 우선 확인하고, 가능하다면 'unknown',
    그렇지 않으면 'new'를 출력한다.
    'old'는 절대 출력하지 않는다.
    """
    data = sys.stdin.read().split()
    test_count = int(data[0])
    output_lines: list[str] = []

    idx = 1
    for _ in range(test_count):
        key_string = data[idx]
        idx += 1

        if can_be_old_system(key_string):
            output_lines.append('unknown')
        else:
            output_lines.append('new')

    sys.stdout.write("\n".join(output_lines))

if __name__ == "__main__":
    main()