import sys
import random

def main():
    if len(sys.argv) != 3:
        print(f"사용법: {sys.argv[0]} <n_limit> <ai_limit>")
        sys.exit(1)

    n_limit = int(sys.argv[1])
    ai_limit = int(sys.argv[2])

    if n_limit < 2 or n_limit > 10 ** 5:
        print("n은 2이상 10^5 이하의 자연수이어야 합니다.")
        sys.exit(1)
    if ai_limit < 1 or ai_limit > 10 ** 8:
        print("a[i]의 값은 1이상 10^8이하의 자연수이어야 합니다.")
        sys.exit(1)
    if ai_limit < n_limit:
        print("서로 다른 값을 생성하려면 ai_limit은 n_limit 이상이어야 합니다.")
        sys.exit(1)
    
    n = random.randint(2, n_limit)
    a = random.sample(range(1, ai_limit + 1), n)

    print(n)
    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()