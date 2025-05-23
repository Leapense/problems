def count_dark_oaks(n):
    count = 0
    current_power_of_2 = 2
    while current_power_of_2 <= n:
        current = current_power_of_2
        while current <= n:
            count += 1
            current *= 3
        current_power_of_2 *= 2

    return count

n = int(input())
print(count_dark_oaks(n))