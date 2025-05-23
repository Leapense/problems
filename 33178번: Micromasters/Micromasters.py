def calculate_free_courses(n):
    free_courses = n // 10
    return free_courses


n = int(input().strip())
print(calculate_free_courses(n))