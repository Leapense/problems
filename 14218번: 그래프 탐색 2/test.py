import matplotlib.pyplot as plt
import math

def calculate_time_complexity(n, m, q):
    query_cost_per_bfs = n + (m + q)
    total_query_cost = q * query_cost_per_bfs
    return total_query_cost

def calculate_space_complexity(n, m, q):
    return n + (m + q)

def plot_complexity():
    n_fixed = 1000
    m_fixed = 100000
    q_values = list(range(1, 501, 25))
    
    time_complexities_q = [calculate_time_complexity(n_fixed, m_fixed, q) for q in q_values]
    space_complexities_q = [calculate_space_complexity(n_fixed, m_fixed, q) for q in q_values]

    plt.figure(figsize=(14, 6))
    plt.subplot(1, 2, 1)
    plt.plot(q_values, time_complexities_q, marker='o', linestyle='-', color='blue')
    plt.title(f'Time Complexity vs. Q (N={n_fixed}, M={m_fixed} Fixed)')
    plt.xlabel('Number of Queries (Q)')
    plt.ylabel('Approximate Operations (Units)')
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')

    plt.subplot(1, 2, 2)
    plt.plot(q_values, space_complexities_q, marker='x', linestyle='--', color='red')
    plt.title(f'Space Complexity vs. Q (N={n_fixed}, M={m_fixed} Fixed)')
    plt.xlabel('Number of Queries (Q)')
    plt.ylabel('Approximate Memory Units')
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')

    plt.tight_layout()
    plt.show()

    n_values = list(range(100, 1001, 100))
    m_fixed_for_n = 50000
    q_fixed_for_n = 250

    time_complexities_n = [calculate_time_complexity(n, m_fixed_for_n, q_fixed_for_n) for n in n_values]
    space_complexities_n = [calculate_space_complexity(n, m_fixed_for_n, q_fixed_for_n) for n in n_values]

    plt.figure(figsize=(14, 6))
    plt.subplot(1, 2, 1)
    plt.plot(n_values, time_complexities_n, marker='o', linestyle='-', color='green')
    plt.title(f'Time Complexity vs. N (M={m_fixed_for_n}, Q={q_fixed_for_n} Fixed)')
    plt.xlabel('Number of Cities (N)')
    plt.ylabel('Approximate Operations (Units)')
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')

    plt.subplot(1, 2, 2)
    plt.plot(n_values, space_complexities_n, marker='x', linestyle='--', color='purple')
    plt.title(f'Space Complexity vs. N (M={m_fixed_for_n}, Q={q_fixed_for_n} Fixed)')
    plt.xlabel('Number of Cities (N)')
    plt.ylabel('Approximate Memory Units')
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')

    plt.tight_layout()
    plt.show()

    m_values = list(range(1000, 100001, 10000))
    n_fixed_for_m = 500
    q_fixed_for_m = 250

    time_complexities_m = [calculate_time_complexity(n_fixed_for_m, m, q_fixed_for_m) for m in m_values]
    space_complexities_m = [calculate_space_complexity(n_fixed_for_m, m, q_fixed_for_m) for m in m_values]

    plt.figure(figsize=(14, 6))
    plt.subplot(1, 2, 1)
    plt.plot(m_values, time_complexities_m, marker='o', linestyle='-', color='orange')
    plt.title(f'Time Complexity vs. M (N={n_fixed_for_m}, Q={q_fixed_for_m} Fixed)')
    plt.xlabel('Number of Initial Roads (M)')
    plt.ylabel('Approximate Operations (Units)')
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')

    plt.subplot(1, 2, 2)
    plt.plot(m_values, space_complexities_m, marker='x', linestyle='--', color='brown')
    plt.title(f'Space Complexity vs. M (N={n_fixed_for_m}, Q={q_fixed_for_m} Fixed)')
    plt.xlabel('Number of Initial Roads (M)')
    plt.ylabel('Approximate Memory Units')
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_complexity()
