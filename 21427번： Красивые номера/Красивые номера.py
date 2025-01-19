def calculate_score(group):
    score = 0
    if len(group) == 2:
        if group[0] == group[1]:
            score = 2
    elif len(group) == 3:
        if group[0] == group[1] and group[1] == group[2]:
            score = 3
        elif group[0] == group[1] or group[1] == group[2] or group[0] == group[2]:
            score = 2
    elif len(group) == 4:
        if group[0] == group[1] == group[2] == group[3]:
            score = 5
        elif group[0] == group[1] and group[2] == group[3]:
            score = 3
        elif group[0] == group[2] and group[1] == group[3]:
            score = 3
        elif group[0] == group[3] and group[1] == group[2]:
            score = 4
        elif (group[0] == group[1] and group[1] == group[2]) or \
             (group[1] == group[2] and group[2] == group[3]) or \
             (group[0] == group[1] and group[1] == group[3]) or \
             (group[0] == group[2] and group[2] == group[3]):
            score = 3
        elif (group[0] == group[2]) or (group[1] == group[3]):
            score = 2

    return score

def find_best_combination(groups, remaining_digits, current_score):
    global best_score, best_combination

    if not remaining_digits:
        if current_score > best_score:
            best_score = current_score
            best_combination = "-".join(groups)
        return
    for i in range(2, min(4, len(remaining_digits)) + 1):
        new_group = remaining_digits[:i]
        find_best_combination(groups + [new_group], remaining_digits[i:], current_score + calculate_score(new_group))

number = input()

if not number.isdigit() or len(number) != 7:
    print("Invalid input")
else:
    best_score = 0
    best_combination = ""

    find_best_combination([], number, 0)
    print(best_combination)
    print(best_score)