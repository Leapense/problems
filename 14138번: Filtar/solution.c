#include <stdio.h>
#include <stdlib.h> // For qsort
#include <stddef.h> // For size_t
#include <stdbool.h> // For bool type

// Point structure
typedef struct {
    long long x;
    long long y;
} Point;

// Global array for input points. Max N = 50.
// Declared as static for internal linkage, a good practice in C.
static Point input_signal_points[50];
static size_t num_input_points;

// Comparison function for qsort when sorting long long values.
static int compare_long_long(const void* a, const void* b) {
    long long val1 = *(const long long*)a;
    long long val2 = *(const long long*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

/**
 * @brief Calculates the interpolated value of the input signal u[k] at a given integer k.
 * @param k The integer x-coordinate for which to calculate u[k].
 * @return The interpolated y-value u[k].
 * @details This function handles three cases: k less than or equal to x_0,
 *          k greater than or equal to x_{N-1}, and k in between.
 *          It uses integer arithmetic, assuming slopes are integers as per problem statement.
 *          Implements binary search for segment finding.
 */
static long long get_u_value(long long k) {
    // If k is to the left of the first point's x-coordinate or at it
    if (k <= input_signal_points[0].x) {
        const Point p1 = input_signal_points[0];
        const Point p2 = input_signal_points[1];
        return p1.y + (p2.y - p1.y) / (p2.x - p1.x) * (k - p1.x);
    }
    // If k is to the right of the last point's x-coordinate or at it
    if (k >= input_signal_points[num_input_points - 1].x) {
        const Point p1 = input_signal_points[num_input_points - 2];
        const Point p2 = input_signal_points[num_input_points - 1];
        return p1.y + (p2.y - p1.y) / (p2.x - p1.x) * (k - p1.x);
    }

    // k is strictly between the first and last x-coordinates.
    // Binary search to find the segment [input_signal_points[idx], input_signal_points[idx+1]]
    // such that input_signal_points[idx].x <= k < input_signal_points[idx+1].x
    size_t low = 0;
    size_t high = num_input_points - 1;
    size_t idx = 0; // Will store the index of the left point of the segment

    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (input_signal_points[mid].x <= k) {
            idx = mid; // This point is potentially the start of our segment
            low = mid + 1; // Try to find a point further right
        } else {
            high = mid - 1; // k is to the left of mid, so search left
        }
    }
    // After loop, input_signal_points[idx].x <= k, and input_signal_points[idx+1].x > k
    // (This holds because of the initial boundary checks for k outside the main range)
    const Point p1 = input_signal_points[idx];
    const Point p2 = input_signal_points[idx + 1];

    return p1.y + (p2.y - p1.y) / (p2.x - p1.x) * (k - p1.x);
}

// Global array for storing k values for median calculation.
// Max N * (2d+1) + 4 = 50 * 101 + 4 = 5054.
static long long k_values_set[5054];
static size_t num_k_values_set_actual = 0; // Actual count of unique K values

// Helper function to add a k_value to the set (array).
// This function doesn't guarantee uniqueness until qsort and unique pass.
static void add_k_value_to_set(long long k_val) {
    if (num_k_values_set_actual < sizeof(k_values_set) / sizeof(k_values_set[0])) {
        k_values_set[num_k_values_set_actual++] = k_val;
    }
}

int main() {
    int n_int;
    if (scanf("%d", &n_int) != 1) return 1;
    num_input_points = (size_t)n_int;

    for (size_t i = 0; i < num_input_points; ++i) {
        if (scanf("%lld %lld", &input_signal_points[i].x, &input_signal_points[i].y) != 2) return 1;
    }

    int d_int;
    if (scanf("%d", &d_int) != 1) return 1;
    long long d = (long long)d_int;

    // Determine the range for k values to calculate median for
    long long min_x = input_signal_points[0].x;
    long long max_x = input_signal_points[num_input_points - 1].x;

    // Add boundary points for output signal.
    // These points define the linear segments of the output signal that extend infinitely.
    add_k_value_to_set(min_x - d - 1); 
    add_k_value_to_set(max_x + d + 1); 

    // Add all potential breakpoints (x_j + i).
    for (size_t j = 0; j < num_input_points; ++j) {
        for (long long i = -d; i <= d; ++i) {
            add_k_value_to_set(input_signal_points[j].x + i);
        }
    }

    // Sort k_values_set and remove duplicates to simulate a sorted set.
    qsort(k_values_set, num_k_values_set_actual, sizeof(long long), compare_long_long);

    if (num_k_values_set_actual > 0) {
        size_t current_unique_idx = 0;
        for (size_t i = 1; i < num_k_values_set_actual; ++i) {
            if (k_values_set[i] != k_values_set[current_unique_idx]) {
                k_values_set[++current_unique_idx] = k_values_set[i];
            }
        }
        num_k_values_set_actual = current_unique_idx + 1;
    }

    // Raw output points before collinearity filtering.
    // Max size is num_k_values_set_actual (max 5054).
    Point raw_output_points[5054];
    size_t num_raw_output_points = 0;

    // Window for median calculation (max 2d+1 = 101 elements).
    long long window_values[101];
    size_t window_size = (size_t)(2 * d + 1);

    for (size_t k_idx = 0; k_idx < num_k_values_set_actual; ++k_idx) {
        long long k = k_values_set[k_idx];
        
        // Populate window_values for median calculation.
        for (size_t i = 0; i < window_size; ++i) {
            // k-d + i effectively iterates from k-d to k+d
            window_values[i] = get_u_value(k - d + (long long)i);
        }

        // Calculate median.
        qsort(window_values, window_size, sizeof(long long), compare_long_long);
        long long y_k = window_values[d]; // Median is at index d for 2d+1 elements.

        raw_output_points[num_raw_output_points].x = k;
        raw_output_points[num_raw_output_points].y = y_k;
        num_raw_output_points++;
    }

    // Final output points after collinearity filtering.
    // In practice, max 5054, but problem states up to 100,000.
    Point final_output_points[5054]; // Using a smaller, more realistic max size for static allocation.
    size_t num_final_output_points = 0;

    // Add the first two points directly if they exist, as collinearity needs at least 3 points.
    if (num_raw_output_points > 0) {
        final_output_points[num_final_output_points++] = raw_output_points[0];
    }
    if (num_raw_output_points > 1) {
        final_output_points[num_final_output_points++] = raw_output_points[1];
    }

    // Filter out redundant points based on collinearity.
    for (size_t i = 2; i < num_raw_output_points; ++i) {
        Point current_point = raw_output_points[i];
        Point last_point = final_output_points[num_final_output_points - 1];
        Point second_last_point = final_output_points[num_final_output_points - 2];

        // Check for collinearity using the cross-product method to avoid division.
        // (y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2)
        bool collinear = (current_point.y - last_point.y) * (last_point.x - second_last_point.x) ==
                         (last_point.y - second_last_point.y) * (current_point.x - last_point.x);

        if (collinear) {
            // If collinear, update the last point in final_output_points to current_point.
            final_output_points[num_final_output_points - 1] = current_point;
        } else {
            // If not collinear, add current_point as a new breakpoint.
            final_output_points[num_final_output_points++] = current_point;
        }
    }

    // Output the total number of points and then each point.
    printf("%zu\n", num_final_output_points);
    for (size_t i = 0; i < num_final_output_points; ++i) {
        printf("%lld %lld\n", final_output_points[i].x, final_output_points[i].y);
    }

    return 0;
}