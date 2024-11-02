def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    N = int(data[0])
    a = int(data[1])
    b = int(data[2])

    index = 3
    total_cost = 0

    for _ in range(N):
        a_i = int(data[index])
        index += 1

        for _ in range(a_i):
            house_number = int(data[index])
            index += 1

            binary_repr = bin(house_number)[2:]
            count_0 = binary_repr.count('0')
            count_1 = binary_repr.count('1')

            cost = (count_0 * a) + (count_1 * b)
            total_cost += cost
        
    print(total_cost)

main()