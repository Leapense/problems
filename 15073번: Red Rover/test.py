import os
import subprocess
import time
import random
import string
import matplotlib.pyplot as plt
import numpy as np

# Java 15 source code for the "Red Rover" problem
JAVA_SOURCE_CODE = """
import java.util.Scanner;

public final class RedRover {

    private RedRover() {
    }

    private static int calculateEncodedLength(String route, String macro) {
        int routeLength = route.length();
        int macroLength = macro.length();
        
        int compressedStringLength = 0;
        int index = 0;

        while (index < routeLength) {
            boolean isMacroMatch = (index + macroLength <= routeLength) 
                                && route.substring(index, index + macroLength).equals(macro);

            if (isMacroMatch) {
                compressedStringLength++;
                index += macroLength;
            } else {
                compressedStringLength++;
                index++;
            }
        }
        
        return compressedStringLength + macroLength;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String route = scanner.nextLine();
        scanner.close();

        int n = route.length();
        int minLength = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                String macro = route.substring(i, j);
                
                if (macro.isEmpty()) {
                    continue;
                }

                int currentLength = calculateEncodedLength(route, macro);
                minLength = Math.min(minLength, currentLength);
            }
        }

        System.out.println(minLength);
    }
}
"""

def compile_java(source_code, class_name):
    """Compiles the Java source code using javac."""
    source_file = f"{class_name}.java"
    with open(source_file, "w") as f:
        f.write(source_code)
    
    compile_command = ["javac", source_file]
    print(f"Compiling with: {' '.join(compile_command)}")
    try:
        subprocess.run(compile_command, check=True, capture_output=True, text=True)
        print("Compilation successful.")
        return True
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        print("Compilation failed.")
        if isinstance(e, subprocess.CalledProcessError):
            print("Compiler Error:", e.stderr)
        else:
            print("Error: javac not found. Please install a JDK and ensure it's in your PATH.")
        return False

def generate_input_file(length, filename="input.txt"):
    """Generates a random valid input file for the problem."""
    with open(filename, "w") as f:
        route = "".join(random.choices(['N', 'S', 'E', 'W'], k=length))
        f.write(route + "\n")

def run_and_measure(class_name, input_filename, use_time_util):
    """Runs the Java program and measures time and memory."""
    time_cmd = []
    if use_time_util:
        time_cmd = ["/usr/bin/time", "-f", "%M"]

    java_command = ["java", class_name]
    full_command = time_cmd + java_command

    start_time = time.perf_counter()
    with open(input_filename, "r") as stdin_file:
        result = subprocess.run(
            full_command,
            stdin=stdin_file,
            capture_output=True,
            text=True
        )
    end_time = time.perf_counter()
    
    execution_time = end_time - start_time
    
    peak_memory_kb = None
    if use_time_util:
        try:
            peak_memory_kb = int(result.stderr.strip().split('\n')[-1])
        except (ValueError, IndexError):
            print("Warning: Could not parse memory usage.")
    
    return execution_time, peak_memory_kb

def plot_results(l_values, times, memories):
    """Plots the time and space complexity graphs."""
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))
    fig.suptitle('Performance Analysis of Red Rover Java Code', fontsize=16)

    # --- Time Complexity Plot ---
    l_values_np = np.array(l_values)
    times_np = np.array(times)
    ax1.scatter(l_values_np, times_np, label='Measured Time', color='blue')
    
    # Fit a 3rd-degree polynomial (for O(L^3))
    coeffs = np.polyfit(l_values_np, times_np, 3)
    p = np.poly1d(coeffs)
    ax1.plot(l_values_np, p(l_values_np), color='red', linestyle='--', label=f'Cubic Fit O(L³)')
    ax1.set_xlabel('Route Length (L)')
    ax1.set_ylabel('Execution Time (seconds)')
    ax1.set_title('Time Complexity')
    ax1.legend()
    ax1.grid(True)

    # --- Space Complexity Plot ---
    if memories and any(mem is not None for mem in memories):
        valid_points = [(l, mem) for l, mem in zip(l_values, memories) if mem is not None]
        l_mem, mem_vals = zip(*valid_points)
        l_mem_np = np.array(l_mem)
        mem_vals_np = np.array(mem_vals)
        
        ax2.scatter(l_mem_np, mem_vals_np, label='Measured Peak Memory', color='green')
        # Fit a linear regression line (for O(L))
        m_fit, b_fit = np.polyfit(l_mem_np, mem_vals_np, 1)
        ax2.plot(l_mem_np, m_fit * l_mem_np + b_fit, color='orange', linestyle='--', label=f'Linear Fit O(L)')
        ax2.set_ylabel('Peak Memory Usage (KB)')
        ax2.set_title('Space Complexity')
    else:
        ax2.text(0.5, 0.5, 'Memory measurement skipped.\n(Requires /usr/bin/time)', 
                 ha='center', va='center', transform=ax2.transAxes)
        ax2.set_title('Space Complexity (Not Measured)')

    ax2.set_xlabel('Route Length (L)')
    ax2.legend()
    ax2.grid(True)

    plt.tight_layout(rect=[0, 0, 1, 0.96])
    plt.show()

def main():
    """Main function to orchestrate the analysis."""
    class_name = "RedRover"
    input_filename = "temp_input.txt"

    if not compile_java(JAVA_SOURCE_CODE, class_name):
        return

    use_time_util = os.path.exists("/usr/bin/time")
    if not use_time_util:
        print("\nWarning: /usr/bin/time not found. Memory usage will not be measured.")

    # Define the range of input sizes to test. L^3 can be slow, so keep steps reasonable.
    l_values = list(range(10, 101, 10))
    execution_times = []
    peak_memories = []

    print(f"\nStarting benchmark...")
    for l in l_values:
        print(f"Testing for route length L = {l}...")
        generate_input_file(l, input_filename)
        
        exec_time, peak_mem = run_and_measure(class_name, input_filename, use_time_util)
        
        execution_times.append(exec_time)
        peak_memories.append(peak_mem)

    print("\nBenchmark complete. Generating plots...")
    plot_results(l_values, execution_times, peak_memories)

    # Cleanup
    print("Cleaning up generated files...")
    for file_ext in [".java", ".class", ""]:
        # Handle input filename separately
        if file_ext == "":
             filename_to_remove = input_filename
        else:
            filename_to_remove = f"{class_name}{file_ext}"

        if os.path.exists(filename_to_remove):
            os.remove(filename_to_remove)
    print("Done.")

if __name__ == "__main__":
    main()
