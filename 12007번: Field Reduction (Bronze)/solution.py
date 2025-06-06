import sys

def solve():
    """
    Field Reduction 문제를 해결하는 메인 함수
    """
    try:
        input = sys.stdin.readline
        n = int(input())
        if n <= 3:
            print(0)
            return
        
        cows = []
        for _ in range(n):
            x, y = map(int, input().split())
            cows.append((x, y))

    except (IOError, ValueError) as e:
        print(f"입력 처리 중 오류 발생: {e}", file=sys.stderr)
        return
    
    cows_sorted_by_x = sorted(cows, key=lambda p: p[0])
    cows_sorted_by_y = sorted(cows, key=lambda p: p[1])

    candidate_cows_to_remove = set()
    candidate_cows_to_remove.add(cows_sorted_by_x[0])
    candidate_cows_to_remove.add(cows_sorted_by_x[-1])
    candidate_cows_to_remove.add(cows_sorted_by_y[0])
    candidate_cows_to_remove.add(cows_sorted_by_y[-1])

    min_area = float('inf')
    for cow_to_remove in candidate_cows_to_remove:
        if cow_to_remove == cows_sorted_by_x[0]:
            new_min_x = cows_sorted_by_x[1][0]
        else:
            new_min_x = cows_sorted_by_x[0][0]

        if cow_to_remove == cows_sorted_by_x[-1]:
            new_max_x = cows_sorted_by_x[-2][0]
        else:
            new_max_x = cows_sorted_by_x[-1][0]
        
        if cow_to_remove == cows_sorted_by_y[0]:
            new_min_y = cows_sorted_by_y[1][1]
        else:
            new_min_y = cows_sorted_by_y[0][1]

        if cow_to_remove == cows_sorted_by_y[-1]:
            new_max_y = cows_sorted_by_y[-2][1]
        else:
            new_max_y = cows_sorted_by_y[-1][1]

        width = new_max_x - new_min_x
        height = new_max_y - new_min_y
        current_area = width * height
        min_area = min(min_area, current_area)

    print(min_area)

if __name__ == "__main__":
    solve()