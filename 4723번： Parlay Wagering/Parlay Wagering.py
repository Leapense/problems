import sys, math

def truncate(num, decimals):
    factor = 10 ** decimals
    return math.floor(num * factor) / factor

def main():
    data = sys.stdin.read().splitlines()
    idx = 0
    t = int(data[idx])
    idx += 1
    results = []
    for _ in range(t):
        parts = data[idx].split()
        idx += 1
        initial = float(parts[0])
        n = int(parts[1])
        total = initial
        lost = False
        for _ in range(n):
            parts = data[idx].split()
            idx += 1
            money_line = int(parts[0])
            outcome = parts[1]
            if outcome == "Loss":
                lost = True
                break
            elif outcome == "Tie":
                continue
            else:  # outcome == "Win"
                if money_line > 0:
                    multiplier = money_line / 100.0
                else:
                    multiplier = 100.0 / abs(money_line)
                multiplier = truncate(multiplier, 3)
                profit = truncate(total * multiplier, 2)
                total = total + profit
        if lost:
            results.append("$0.00")
        else:
            if total > 1000000:
                total = 1000000
            results.append(f"${total:,.2f}")
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()
