import sys
import itertools

def normalize_course(name):
    return name.strip().lower().replace(' ', '')

def solve():
    lines = sys.stdin.read().splitlines()
    board = [line for line in lines if line.strip()]

    R = len(board)
    C = len(board[0]) if R > 0 else 0

    micromasters = []

    visited_corners = set()

    for r in range(R):
        for c in range(C):
            if board[r][c] == '+' and (r, c) not in visited_corners:
                if r + 1 < R and c + 1 < C and board[r + 1][c] == '|' and board[r][c + 1] == '-':
                    c2 = c + 1
                    while c2 < C and board[r][c2] == '-':
                        c2 += 1

                    if c2 < C and board[r][c2] == '+':
                        r2 = r + 1
                        while r2 < R and board[r2][c] == '|':
                            r2 += 1

                        if r2 < R and board[r2][c] == '+' and r2 < R and c2 < C and board[r2][c2] == '+':
                            visited_corners.add((r, c))
                            current_courses_set = set()
                            for row in range(r + 1, r2):
                                if row < R:
                                    if c + 1 < c2:
                                        course_name = board[row][c + 1 : c2]
                                        normalized_name = normalize_course(course_name)
                                        if normalized_name:
                                            current_courses_set.add(normalized_name)

                            if current_courses_set:
                                micromasters.append(current_courses_set)


    min_total_courses = float('inf')
    for combo in itertools.combinations(micromasters, 3):
        combined_courses = set()
        for micro in combo:
            combined_courses.update(micro)

        min_total_courses = min(min_total_courses, len(combined_courses))

    print(min_total_courses)

solve()

