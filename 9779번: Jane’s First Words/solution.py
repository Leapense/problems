#!/usr/bin/env python3

import re
import sys

def process_call_signals():
    """
    표준 입력으로부터 아기의 음성 단어를 한 줄씩 읽어
    'daddy' 계열의 호출 패턴과 매칭되면 'She called me!!!'를,
    그렇지 않으면 'Cooing'을 출력한다.
    """
    call_pattern = re.compile(r"da+dd?(?:i|y)$")
    for line in sys.stdin:
        word = line.strip()
        if not word:
            continue

        if call_pattern.fullmatch(word):
            print("She called me!!!")
        else:
            print("Cooing")

if __name__ == "__main__":
    process_call_signals()