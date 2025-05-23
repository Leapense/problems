import sys

def main():
    input = sys.stdin.read().splitlines()
    Q = int(input[0])
    orders = input[1:]
    counts = [0]*26
    current_step =0
    current_position = None
    current_direction =1
    outputs = []
    for order in orders:
        parts = order.split()
        if parts[0] == "SMJER":
            n = int(parts[1])
            delta = n - current_step
            if current_step ==0 and current_position is None:
                if delta >=1:
                    counts[0] +=1
                    current_position=0
                    delta -=1
                    current_step +=1
            if delta >0:
                full_cycles = delta //26
                remainder_steps = delta %26
                for i in range(26):
                    counts[i] +=full_cycles
                for _ in range(remainder_steps):
                    current_position = (current_position + current_direction) %26
                    counts[current_position] +=1
                current_step +=delta
            current_direction *= -1
        elif parts[0] == "UPIT":
            n = int(parts[1])
            x = parts[2]
            delta = n - current_step
            if current_step ==0 and current_position is None:
                if delta >=1:
                    counts[0] +=1
                    current_position=0
                    delta -=1
                    current_step +=1
            if delta >0:
                full_cycles = delta //26
                remainder_steps = delta %26
                for i in range(26):
                    counts[i] +=full_cycles
                for _ in range(remainder_steps):
                    current_position = (current_position + current_direction) %26
                    counts[current_position] +=1
                current_step +=delta
            outputs.append(str(counts[ord(x)-97]))
    print('\n'.join(outputs))

main()
