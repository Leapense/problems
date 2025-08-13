#!/usr/bin/env python3

import random
import subprocess
import sys
from pathlib import Path

def rand_string(length: int) -> str:
    return ''.join(random.choice('abcdefghijklmnopqrstuvwxyz') for _ in range(length))

def possible_by_bruteforce(s: str, t: str) -> bool:
    n = len(t)
    m = len(s)

    dp = [[False] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][m] = ((n - i) % 2 == 0)

    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            match = t[i] == s[j] and dp[i + 1][j + 1]
            delete_pair = (i + 2 <= n) and dp[i + 2][j]
            dp[i][j] = match or delete_pair

    return dp[0][0]

def run_java_solution(s: str, t: str) -> str:
    java_cmd = ["java", "Main"]
    proc = subprocess.run(
        java_cmd,
        input=f"{s}\n{t}\n",
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
    )
    if proc.returncode != 0:
        sys.stderr.write(f"[ERROR] Java 프로세스 비정상 종료 (rc={proc.returncode})\n")
        sys.stderr.write(proc.stderr)
        sys.exit(1)

    return proc.stdout.strip()

def main():
    random.seed(0)
    total_cases = 5000
    max_len_t = 14
    passed = 0

    java_src = Path("Main.java")
    if java_src.is_file():
        compile_proc = subprocess.run(
            ["javac", "Main.java"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        if compile_proc.returncode != 0:
            sys.stderr.write("[ERROR] Java 컴파일 실패\n")
            sys.stderr.write(compile_proc.stderr)
            sys.exit(1)

    for case_no in range(1, total_cases + 1):
        len_t = random.randint(1, max_len_t)
        len_s = random.randint(1, len_t)
        t = rand_string(len_t)
        s = rand_string(len_s)

        ref = possible_by_bruteforce(s, t)
        java_ans = run_java_solution(s, t)

        expected = "YES" if ref else "NO"

        if java_ans != expected:
            print(f"\n[FAIL] case #{case_no}")
            print(f"s = {s}")
            print(f"t = {t}")
            print(f"Expected : {expected}")
            print(f"Java out : {java_ans}")
            sys.exit(1)
        else:
            passed += 1
            if case_no % 500 == 0:
                print(f"{case_no}/{total_cases} cases passed...")
    print(f"\nAll tests passed! ({passed}/{total_cases})")

if __name__ == "__main__":
    main()