import sys
import math

def main():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    logs = [0.0] * 9001
    for n in range(1, 9001):
        logs[n] = math.log10(n)

    def digit_count_for(E: int) -> int:
        total = 0.0
        x = 9000
        while x > 0:
            total += logs[x]
            x -= E
        return int(total) + 1
    
    outputs = []
    idx = 1

    for case_number in range(1, t + 1):
        D = int(data[idx])
        idx += 1
        chosen_E = None
        for E in range(1, 9001):
            if digit_count_for(E) < D:
                chosen_E = E
                break

        if chosen_E is None and 4 < D:
            chosen_E = 9001
        
        if chosen_E is None:
            result = "..."
        else:
            result = "IT'S OVER 9000" + '!' * chosen_E

        outputs.append(f"Case #{case_number}: {result}")

    sys.stdout.write("\n".join(outputs))

if __name__ == "__main__":
    main()