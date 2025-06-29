import time
import matplotlib.pyplot as plt
import sys

def calculate_perimeter(points):
    n = len(points)
    if n < 4:
        return 0

    x_coords = [p[0] for p in points]
    y_coords = [p[1] for p in points]

    min_x = min(x_coords)
    max_x = max(x_coords)
    min_y = min(y_coords)
    max_y = max(y_coords)

    bounding_box_perimeter = 2 * ((max_x - min_x) + (max_y - min_y))
    total_perimeter = 0
    for i in range(n):
        p1 = points[0]
        p2 = points[(i + 1) % n]
        dx = abs(p1[0] - p2[0])
        dy = abs(p1[1] - p2[1])
        total_perimeter += dx + dy

    return total_perimeter - bounding_box_perimeter

def generate_rectilinear_polygon(n):
    if n < 4 or n % 2 != 0:
        n = (n // 4) * 4 if n >= 4 else 4

    points = []
    x, y = 0, 0
    step = 1

    for i in range(n // 2):
        points.append([x, y])
        if i % 2 == 0:
            x += step
        else:
            y += step
            step += 1

    for i in range(n // 2):
        points.append([x, y])
        if i % 2 == 0:
            x -= step
        else:
            y -= step
            step -= 1

    return points

def main():
    n_values = list(range(4, 2001, 50))
    time_measurements = []
    space_measurements = []

    print("Running benchmark...")
    for n in n_values:
        polygon_points = generate_rectilinear_polygon(n)
        start_time = time.perf_counter()
        calculate_perimeter(polygon_points)
        end_time = time.perf_counter()

        elapsed_time = end_time - start_time
        time_measurements.append(elapsed_time)

        space_measurements.append(n)
        sys.stdout.write(f"\rProcessed n = {n}/{n_values[-1]}")
        sys.stdout.flush()
    print("\nBenchmark complete.")

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
    ax1.plot(n_values, time_measurements, 'o-', label='Measured Time', markersize=4)
    ax1.set_title('Time Complexity Analysis', fontsize=16)
    ax1.set_xlabel('Number of Vertices (N)', fontsize=12)
    ax1.set_ylabel('Execution Time (seconds)', fontsize=12)
    ax1.grid(True)

    if time_measurements[-1] > 0:
        c = time_measurements[-1] / n_values[-1]
        theoretical_time = [c * n for n in n_values]
        ax1.plot(n_values, theoretical_time, 'r--', label='Theoretical O(N) Line')
    ax1.legend()
    ax2.plot(n_values, space_measurements, 'o-', color='green', label='Estimated Space', markersize=4)
    ax2.set_title('Space Complexity Analysis', fontsize=16)
    ax2.set_xlabel('Number of Vertices (N)', fontsize=12)
    ax2.set_ylabel('Space Units (Proportional to N)', fontsize=12)
    ax2.grid(True)

    ax2.plot(n_values, n_values, 'r--', label='Theoretical O(N) Line')
    ax2.legend()
    fig.suptitle('Performance Analysis of Perpendicularia Solution', fontsize=20)
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.show()

if __name__ == "__main__":
    main()