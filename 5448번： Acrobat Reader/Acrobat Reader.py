import sys
import threading
import math

def main():
    import sys

    sys.setrecursionlimit(1 << 25)
    input_data = sys.stdin.read().split()
    index = 0

    T = int(input_data[index])
    index += 1

    rotations = [
        lambda x, y: (x, y),
        lambda x, y: (-y, x),
        lambda x, y: (-x, -y),
        lambda x, y: (y, -x),
    ]

    epsilon = 1e-6

    for _ in range(T):
        N = int(input_data[index])
        index += 1

        scan1 = []
        for _ in range(N):
            x = int(input_data[index])
            index += 1
            y = int(input_data[index])
            index += 1
            scan1.append((x, y))

        scan2 = []
        for _ in range(N):
            x = int(input_data[index])
            index += 1
            y = int(input_data[index])
            index += 1
            scan2.append((x, y))

        # Compute distances for scan1
        distances1 = []
        for i in range(N):
            x1, y1 = scan1[i]
            for j in range(i+1, N):
                x2, y2 = scan1[j]
                dx = x1 - x2
                dy = y1 - y2
                dist = dx * dx + dy * dy
                distances1.append(dist)

        distances1.sort()
        # Normalize distances by median
        median1 = distances1[len(distances1) // 2]
        distances1 = [d / median1 for d in distances1]

        match_found = False

        for rotate in rotations:
            # Rotate scan2
            rotated_scan2 = []
            for x, y in scan2:
                xr, yr = rotate(x, y)
                rotated_scan2.append((xr, yr))

            # Compute distances for rotated scan2
            distances2 = []
            for i in range(N):
                x1, y1 = rotated_scan2[i]
                for j in range(i+1, N):
                    x2, y2 = rotated_scan2[j]
                    dx = x1 - x2
                    dy = y1 - y2
                    dist = dx * dx + dy * dy
                    distances2.append(dist)

            distances2.sort()
            # Normalize distances by median
            median2 = distances2[len(distances2) // 2]
            if median2 == 0:
                continue  # Avoid division by zero
            distances2 = [d / median2 for d in distances2]

            # Compare the normalized distances
            mismatch = False
            for d1, d2 in zip(distances1, distances2):
                if abs(d1 - d2) > epsilon:
                    mismatch = True
                    break
            if not mismatch:
                match_found = True
                break

        print("okay" if match_found else "mismatch!")

if __name__ == "__main__":
    threading.Thread(target=main).start()
