import sys

def main():
    import sys
    from collections import defaultdict

    input = sys.stdin.read
    data = input().split()

    N = int(data[0])
    keys = data[1:]

    history = []
    turbo_mode = False
    cycle_list = []
    cycle_idx = 0
    output = []

    for key in keys:
        if key != 'T':
            # Manual channel selection
            channel = int(key)
            history.append(channel)
            if turbo_mode:
                turbo_mode = False
        else:
            if not turbo_mode:
                # Enter turbo mode
                if not history:
                    # No channel to reference, skip
                    continue
                X = history[-1]
                # Find the last two occurrences of X
                last_idx = len(history) - 1
                prev_idx = -1
                for i in range(last_idx -1, -1, -1):
                    if history[i] == X:
                        prev_idx = i
                        break
                if prev_idx != -1:
                    relevant = history[prev_idx +1 : last_idx +1]
                else:
                    relevant = history[:last_idx +1]
                # Extract unique channels in order
                seen = set()
                unique_channels = []
                for ch in relevant:
                    if ch not in seen:
                        seen.add(ch)
                        unique_channels.append(ch)
                cycle_list = unique_channels
                cycle_idx = 0
                if cycle_list:
                    display = cycle_list[cycle_idx]
                    history.append(display)
                    output.append(str(display))
                    cycle_idx = (cycle_idx +1) % len(cycle_list)
                turbo_mode = True
            else:
                # Continue in turbo mode
                if not cycle_list:
                    # No cycle to follow, skip
                    continue
                display = cycle_list[cycle_idx]
                history.append(display)
                output.append(str(display))
                cycle_idx = (cycle_idx +1) % len(cycle_list)

    print('\n'.join(output))

if __name__ == "__main__":
    main()