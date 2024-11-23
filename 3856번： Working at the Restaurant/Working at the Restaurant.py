import sys

def process_test_case(commands):
    operations = []
    pile1 = []
    pile2 = []

    for command in commands:
        parts = command.strip().split()
        cmd_type = parts[0]
        m = int(parts[1])

        if cmd_type == "DROP":
            operations.append(f"DROP 2 {m}")
            pile2.extend([1] * m)
        elif cmd_type == "TAKE":
            plates_to_take = m

            if len(pile1) >= plates_to_take:
                operations.append(f"TAKE 1 {plates_to_take}")
                for _ in range(plates_to_take):
                    pile1.pop()
            else:
                if len(pile1) > 0:
                    operations.append(f"TAKE 1 {len(pile1)}")
                    plates_to_take -= len(pile1)
                    pile1 = []

                if len(pile2) > 0:
                    operations.append(f"MOVE 2->1 {len(pile2)}")
                    pile1 = pile2[::-1]
                    pile2 = []

                if plates_to_take > 0:
                    operations.append(f"TAKE 1 {plates_to_take}")
                    for _ in range(plates_to_take):
                        pile1.pop()

    return operations

def main():
    input = sys.stdin.read().splitlines()
    idx = 0
    output_cases = []

    while idx < len(input):
        N = int(input[idx].strip())
        idx += 1

        if N == 0:
            break

        commands = input[idx:idx + N]
        idx += N

        operations = process_test_case(commands)
        output_cases.append(operations)

    for i, case_ops in enumerate(output_cases):
        for op in case_ops:
            print(op)
        if i != len(output_cases) - 1:
            print()

if __name__ == '__main__':
    main()