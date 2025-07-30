import sys

cycle = ["Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"]
index_map = {animal: i for i, animal in enumerate(cycle)}

def main():
    input_data = sys.stdin.read().split()
    n = int(input_data[0])
    years = {"Bessie": 0}
    ptr = 1
    for _ in range(n):
        name1 = input_data[ptr]
        relation = input_data[ptr+3]
        animal = input_data[ptr+4]
        name2 = input_data[ptr+7]
        ptr += 8
        base = years[name2]
        baseIndex = (base % 12 + 12) % 12
        targetIndex = index_map[animal]
        diff = targetIndex - baseIndex
        if relation == "next":
            if diff <= 0:
                diff += 12
        else:
            if diff >= 0:
                diff -= 12
        years[name1] = base + diff
    print(abs(years["Elsie"]))

if __name__ == "__main__":
    main()
