def determine_divisions(r, available_divisions):
    if r <= 1600:
        base_division = 3
    elif r <= 1900:
        base_division = 2
    else:
        base_division = 1
    
    result = []
    
    for division in available_divisions:
        division = int(division)
        if division == base_division:
            result.append(f"{division}")
        else:
            if division == 1 and r > 1900:
                result.append(f"{division}*")
            elif division == 2 and r > 1600:
                result.append(f"{division}*")
            elif division == 3 and r > 0:
                result.append(f"{division}*")
    
    return result

r = int(input())
available_divisions = input().strip()

result = determine_divisions(r, available_divisions)

for line in result:
    print(line)