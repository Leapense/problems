N = int(input())
sequence = list(map(int, input().split()))

current_states = {"red"}

trans = {
    "red": {0: "green", 1: "green"},
    "green": {0: "red", 1: "blue"},
    "blue": {0: "yellow", 1: "blue"},
    "yellow": {0: "yellow", 1: "red"}
}

for button in sequence:
    next_states = set()

    for state in current_states:
        if button == -1:
            next_states.add(trans[state][0])
            next_states.add(trans[state][1])
        else:
            next_states.add(trans[state][button])

    current_states = next_states

print("JAH" if "red" in current_states else "EI")
print("JAH" if "green" in current_states else "EI") 
print("JAH" if "blue" in current_states else "EI")
print("JAH" if "yellow" in current_states else "EI")   