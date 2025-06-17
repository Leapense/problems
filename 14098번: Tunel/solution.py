import sys

def solve():
    """
    터널 입구와 출구의 차량 통과 순서를 바탕으로 추월한 차량의 수를 계산
    """
    try:
        input = sys.stdin.readline
        n = int(input())
        if not (1 <= n <= 1000):
            return
        
        entrance_positions = {input().strip(): i for i in range(n)}
        exit_order = [input().strip() for _ in range(n)]
        violators = set()

        for i in range(n):
            for j in range(i + 1, n):
                car_that_exited_earlier = exit_order[i]
                car_that_exited_later = exit_order[j]
                if entrance_positions[car_that_exited_earlier] > entrance_positions[car_that_exited_later]:
                    violators.add(car_that_exited_earlier)

        print(len(violators))

    except (ValueError, IndexError) as e:
        print(f"An error occurred: {e}", file=sys.stderr)

if __name__ == "__main__":
    solve()