n = int(input())
players = []

for _ in range(n):
    data = input().split()
    salary = int(data[0])
    name = data[1]
    nationality = data[2]
    players.append((salary, name, nationality))

max_salary = -1
max_salary_player = None

for salary, name, nationality in players:
    if nationality == 'Russia' and salary > max_salary:
        max_salary = salary
        max_salary_player = name

print(max_salary_player)