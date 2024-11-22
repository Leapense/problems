def main():
    import sys

    N, M, X, Y = map(int, sys.stdin.readline().split())
    h_student, h_mid = sys.stdin.readline().split()
    h_mid = int(h_mid)

    eligible_students = []
    other_students = []

    for _ in range(N - 1):
        s_num, s_mid = sys.stdin.readline().split()
        s_mid = int(s_mid)

        if s_num.startswith('2024'):
            eligible_students.append(s_mid)
        else:
            other_students.append(s_mid)

    other_final_scores = []
    for s_mid in eligible_students:
        final = Y - (X - s_mid)
        final = max(final, 0)
        total = s_mid + final
        other_final_scores.append(total)

    total_eligible = len(other_final_scores) + 1

    if total_eligible <= M:
        print("YES")
        print(0)
        return
    other_final_scores.sort(reverse=True)

    left = 0
    right = Y
    answer = -1

    while left <= right:
        mid_final = (left + right) // 2
        h_total = h_mid + mid_final

        count = 0
        for score in other_final_scores:
            if score > h_total:
                count += 1

        if count < M:
            answer = mid_final
            right = mid_final - 1
        else:
            left = mid_final + 1

    if answer != -1 and answer <= Y:
        print("YES")
        print(answer)
    else:
        print("NO")
if __name__ == '__main__':
    main()