import sys
import bisect

def process_test_case(C, N, events):
    available = [(0, C)]
    occupied = {}
    total_revenue = 0
    for event in events:
        if event[0] == 'C':
            P = int(event[1])
            Q = int(event[2])
            # Find the first available block that can accommodate Q
            for i, (start, end) in enumerate(available):
                if end - start >= Q:
                    # Park from start to start + Q
                    occupied[P] = (start, start + Q)
                    # If there's remaining space, split the block
                    if start + Q < end:
                        available.insert(i+1, (start + Q, end))
                    # Remove the original block
                    del available[i]
                    total_revenue += 10
                    break
            else:
                # No available block found
                pass
        else:
            # 'S' event
            P = int(event[1])
            start, end = occupied[P]
            # Add back the freed block
            available.append((start, end))
            # Sort available blocks by start
            available.sort()
            # Merge adjacent or overlapping blocks
            i = 0
            while i < len(available) - 1:
                current = available[i]
                next_block = available[i+1]
                if current[1] >= next_block[0]:
                    # Merge them
                    available[i] = (current[0], max(current[1], next_block[1]))
                    del available[i+1]
                else:
                    i += 1
            # Remove the plate from occupied
            del occupied[P]
    return total_revenue

def main():
    input = sys.stdin.read().splitlines()
    idx = 0
    while idx < len(input):
        if input[idx].strip() == '':
            idx += 1
            continue
        # Read C and N
        C_N = input[idx].split()
        C = int(C_N[0])
        N = int(C_N[1])
        idx += 1
        events = []
        for _ in range(N):
            if idx >= len(input):
                break
            event_line = input[idx].strip()
            if event_line == '':
                idx += 1
                continue
            event_parts = event_line.split()
            events.append(event_parts)
            idx += 1
        # Process the test case
        revenue = process_test_case(C, N, events)
        print(revenue)

if __name__ == "__main__":
    main()