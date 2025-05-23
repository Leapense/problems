def next_permutation(num_str):
    num_list = list(num_str)
    i = len(num_list) - 1
    while i > 0 and num_list[i - 1] >= num_list[i]:
        i -= 1
    if i <= 0:
        return "USELESS"
    j = len(num_list) - 1
    while num_list[j] <= num_list[i-1]:
        j -= 1
    num_list[i-1], num_list[j] = num_list[j], num_list[i-1]
    num_list[i:] = num_list[i:][::-1]
    return "".join(num_list)

if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().split()
    t = int(input_data[0])
    results = []
    for k in range(1, t+1):
        results.append(next_permutation(input_data[k]))
    print("\n".join(results))