def can_unlock(combination):
    keypad = [
        ['1', '2', '3'],
        ['4', '5', '6'],
        ['7', '8', '9'],
        [' ', '0', ' ']
    ]

    def find_position(digit):
        for i, row in enumerate(keypad):
            if digit in row:
                return (i, row.index(digit))
        return None
    
    d1, d2, d3 = combination[0], combination[1], combination[2]

    pos1 = find_position(d1)
    pos2 = find_position(d2)
    pos3 = find_position(d3)

    if len(set(combination)) != 3:
        return "Locked"
    
    if pos1[0] == pos2[0] == pos3[0]:
        sorted_positions = sorted([pos1[1], pos2[1], pos3[1]])
        if sorted_positions[1] - sorted_positions[0] == 1 and sorted_positions[2] - sorted_positions[1] == 1:
            return "Unlocked"
        
    if pos1[1] == pos2[1] == pos3[1]:
        sorted_positions = sorted([pos1[0], pos2[0], pos3[0]])
        if sorted_positions[1] - sorted_positions[0] == 1 and sorted_positions[2] - sorted_positions[1] == 1:
            return "Unlocked"
    
    return "Locked"

combination = input().strip()
print(can_unlock(combination))