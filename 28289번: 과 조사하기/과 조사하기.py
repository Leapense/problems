def count_students(P, students):
    software_dev = 0
    embedded_dev = 0
    ai_dev = 0
    first_year = 0

    for student in students:
        G, C, N = student
        if G == 1:
            first_year += 1
        elif G >= 2:
            if C in [1, 2]:
                software_dev += 1
            elif C == 3:
                embedded_dev += 1
            elif C == 4:
                ai_dev += 1

    print(software_dev)
    print(embedded_dev)
    print(ai_dev)
    print(first_year)

P = int(input().strip())
students = [tuple(map(int, input().split())) for _ in range(P)]

count_students(P, students)