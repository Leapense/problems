import sys

def solve():
    """
    주어진 정수 N을 팩토리얼의 합으로 나타낼 때,
    필요한 최소 팩토리얼 항의 개수를 계산한다.
    """
    try:
        n_input = int(sys.stdin.readline())
    except (ValueError, IndexError):
        print(0)
        return
    
    factorials = []
    current_factorial = 1
    i = 1
    while current_factorial <= n_input:
        factorials.append(current_factorial)
        i += 1
        current_factorial *= i

    count = 0
    remaining_n = n_input

    for fact in reversed(factorials):
        if remaining_n == 0:
            break
        num_to_use = remaining_n // fact
        if num_to_use > 0:
            count += num_to_use
            remaining_n %= fact

    print(count)

if __name__ == "__main__":
    solve()