def solve():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    party_num = 0
    i = 0
    result = []
    while i < len(data):
        if data[i] == "#":
            break
        party = []
        while i < len(data) and data[i] != "#":
            party.append(data[i])
            i += 1
        i += 1
        if not party:
            break
        party_num += 1
        mapping = {}
        order = []

        for line in party:
            giver, receiver = line.split()
            if giver not in mapping:
                order.append(giver)
            mapping[giver] = receiver
        visited = set()
        cycles = []
        for person in order:
            if person in visited:
                continue
            cycle = []
            current = person
            while current not in visited:
                cycle.append(current)
                visited.add(current)
                current = mapping[current]

            cycle.append(cycle[0])
            cycles.append(cycle)
        result.append("Party number " + str(party_num))
        for cycle in cycles:
            result.append(" to ".join(cycle) + ".")
        result.append("")
    sys.stdout.write("\n".join(result).strip())

if __name__ == "__main__":
    solve()