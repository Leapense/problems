import numpy as np
import matplotlib.pyplot as plt

def plot_complexity_analysis():
    """
    Generates and displays plots for the time and space complexity
    of the Pony Express solution.
    """
    plt.style.use('seaborn-v0_8-whitegrid')
    n_values = np.arange(2, 101)
    time_complexity_n3 = n_values ** 3
    time_complexity_n2 = n_values ** 2
    fig, ax1 = plt.subplots(figsize=(10, 6))
    ax1.plot(n_values, time_complexity_n3,
             label=r'Algorithm Complexity: $O(N^3)$',
             color='crimson', linewidth=2.5)
    ax1.plot(n_values, time_complexity_n2,
             label=r'For Comparison: $O(N^2)$',
             color='royalblue', linestyle='--', linewidth=2)
    ax1.set_yscale('log')
    ax1.set_xlabel('Number of Cities (N)', fontsize=12)
    ax1.set_ylabel('Number of Relative Operations (Log Scale)', fontsize=12)
    ax1.set_title('Time Complexity Analysis: Pony Express Solution', fontsize=14, fontweight='bold')
    ax1.legend(fontsize=11)
    ax1.grid(True, which='both', ls='--')

    space_complexity_n2 = n_values ** 2
    space_complexity_n = n_values
    fig, ax2 = plt.subplots(figsize=(10, 6))
    ax2.plot(n_values, space_complexity_n2,
             label=r'Algorithm Complexity: $O(N^2)$',
             color='forestgreen', linewidth=2.5)
    ax2.plot(n_values, space_complexity_n,
             label=r'For Comparison: $O(N)$',
             color='darkorange', linestyle='--', linewidth=2)
    ax2.set_xlabel('Number of Cities (N)', fontsize=12)
    ax2.set_ylabel('Relative Memory Units', fontsize=12)
    ax2.set_title('Space Complexity Analysis: Pony Express Solution', fontsize=14, fontweight='bold')
    ax2.legend(fontsize=11)
    ax2.grid(True, which='both', ls="--")
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_complexity_analysis()