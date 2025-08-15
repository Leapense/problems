import sys
import string
from typing import Optional, Tuple

ALPHABET = string.ascii_letters + string.digits
MAX_LEN = 20
LENGTH_MISMATCH_TIME = 5
FILL_CHAR = "0"

def read_response() -> Tuple[bool, Optional[int]]:
    while True:
        line = sys.stdin.readline()
        if not line:
            sys.exit(0)
        line = line.strip()
        if not line:
            continue
        if line.startswith("ACCESS GRANTED"):
            return True, None
        if line.startswith("ACCESS DENIED"):
            digits = "".join(ch for ch in line if ch.isdigit())
            if not digits:
                continue
            return False, int(digits)
        
def ask(guess: str) -> Tuple[bool, Optional[int]]:
    print(guess, flush=True)
    return read_response()

def find_length() -> int:
    for length in range(1, MAX_LEN + 1):
        guess = "A" * length
        granted, t = ask(guess)
        if granted:
            sys.exit(0)
        if t != LENGTH_MISMATCH_TIME:
            return length
    return MAX_LEN

def deduce_password(length: int) -> None:
    prefix = ""
    for i in range(length):
        best_char = None
        best_time = -1
        for ch in ALPHABET:
            remain = length - len(prefix) - 1
            guess = prefix + ch + (FILL_CHAR * remain if remain > 0 else "")
            granted, t = ask(guess)
            if granted:
                sys.exit(0)
            if t is not None and t > best_time:
                best_time = t
                best_char = ch
        if best_char is None:
            sys.exit(1)
        prefix += best_char
    print(prefix, flush=True)
    granted, _ = read_response()
    if not granted:
        sys.exit(1)

def main() -> None:
    length = find_length()
    deduce_password(length)

if __name__ == "__main__":
    main()
        