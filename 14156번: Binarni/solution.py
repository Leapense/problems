import sys

def generate_gray_code(n: int) -> list[str]:
    if n == 0:
        return [""]
    if n == 1:
        return ["0", "1"]
    
    prev_gray_codes = generate_gray_code(n - 1)

    first_half = ["0" + code for code in prev_gray_codes]
    second_half = ["1" + code for code in prev_gray_codes[::-1]]

    return first_half + second_half

def main():
    try:
        n = int(sys.stdin.readline())
    except ValueError:
        print("입력은 자연수여야 합니다.", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"입력 읽기 오류: {e}", file=sys.stderr)
        sys.exit(1)

    if not (1 <= n <= 16):
        print("N은 1 이상 16 이하의 자연수여야 합니다.", file=sys.stderr)
        sys.exit(1)

    gray_codes = generate_gray_code(n)
    for code in gray_codes:
        print(code)

if __name__ == "__main__":
    main()