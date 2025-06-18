import sys
import time
import matplotlib.pyplot as plt
import numpy as np

def generate_gray_code(n: int) -> list[str]:
    if n == 0:
        return [""]
    if n == 1:
        return ["0", "1"]
    prev_gray_codes = generate_gray_code(n - 1)
    first_half = ["0" + code for code in prev_gray_codes]
    second_half = ["1" + code for code in prev_gray_codes[::-1]]
    return first_half + second_half

def measure_time(func, n_value):
    start_time = time.time()
    result = func(n_value)
    end_time = time.time()
    return end_time - start_time, len(result) * len(result[0]) if result else 0

n_values = list(range(1, 17))
measured_times = []
space_usages_approx = []

for n in n_values:
    exec_time, approx_space = measure_time(generate_gray_code, n)
    measured_times.append(exec_time)
    space_usages_approx.append(approx_space)

theoretical_time_proxy = [n * (2 ** n) for n in n_values]
theoretical_space_proxy = [n * (2 ** n) for n in n_values]

plt.figure(figsize=(14, 6))
plt.subplot(1, 2, 1)
plt.plot(n_values, measured_times, marker='o', linestyle='-', label='Measured Execution Time')
plt.yscale('log')
plt.xlabel('N (Input Size)')
plt.ylabel('Execution Time (seconds) [log scale]')
plt.title('Execution Time vs. N')
plt.legend()
plt.grid(True)

plt.subplot(1, 2, 2)
plt.plot(n_values, space_usages_approx, marker='o', linestyle='-', label='Approx. Total String Length')
plt.yscale('log')
plt.xlabel('N (Input Size)')
plt.ylabel('Approx. Space Usage (characters) [log scale]')
plt.title('Space Usage (Approx.) vs. N')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()

print ("\n측정된 시간 (초) :", measured_times)
print("근사적인 공간 사용량 (총 문자열 길이) :", space_usages_approx)