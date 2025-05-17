def main():
    import sys
    import itertools

    input = sys.stdin.read
    data = input().split()
    ptr = 0
    K = int(data[ptr])
    ptr += 1

    for data_set in range(1, K + 1):
        n, Y, B = map(int, data[ptr:ptr+3])
        ptr += 3
        job_targets = list(map(int, data[ptr:ptr + Y]))
        ptr += Y

        projects = []
        for _ in range(n):
            jobs = list(map(int, data[ptr:ptr + Y]))
            cost = int(data[ptr + Y])
            gain = int(data[ptr + Y + 1])
            projects.append((jobs, cost, gain))
            ptr += Y + 2

        max_gain = -1
        for mask in range(1, 1 << n):
            total_jobs = [0] * Y
            total_cost = 0
            total_gain = 0

            for i in range(n):
                if (mask >> i) & 1:
                    pj_jobs, pj_cost, pj_gain = projects[i]
                    total_cost += pj_cost
                    total_gain += pj_gain
                    for y in range(Y):
                        total_jobs[y] += pj_jobs[y]
            if total_cost > B:
                continue
            if all(total_jobs[y] >= job_targets[y] for y in range(Y)):
                if total_gain > max_gain:
                    max_gain = total_gain

        print(f"Data Set {data_set}:")
        if max_gain == -1:
            print("No selection.\n")
        else:
            print(f"{max_gain}\n")
if __name__ == "__main__":
    main()