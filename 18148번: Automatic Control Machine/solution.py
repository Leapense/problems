import sys, itertools

def main():
    data = sys.stdin.read().split()
    iterator = iter(data)
    num_cases = int(next(iterator))
    outputs = []

    for _ in range(num_cases):
        num_features = int(next(iterator))
        num_datasets = int(next(iterator))
        masks = []
        for _ in range(num_datasets):
            s = next(iterator)
            mask = 0
            for idx, ch in enumerate(s):
                if ch == '1':
                    mask |= 1 << idx
            masks.append(mask)

        full_mask = (1 << num_features) - 1
        answer = -1

        for k in range(1, num_datasets + 1):
            for combo in itertools.combinations(masks, k):
                combined = 0
                for m in combo:
                    combined |= m
                if combined == full_mask:
                    answer = k
                    break
            if answer != -1:
                break
        outputs.append(str(answer))

    sys.stdout.write("\n".join(outputs))

if __name__ == "__main__":
    main()