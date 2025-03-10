#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 8009                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/8009                           #+#        #+#      #+#     #
#    Solved: 2025/02/26 21:53:23 by cjhool        ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #

def main():
    import sys
    input_data = sys.stdin.read().splitlines()
    index = 0
    output_lines = []
    while index < len(input_data):
        hotel_name = input_data[index].strip()
        index += 1
        if hotel_name == "#":
            break
        deals= []
        while index < len(input_data):
            line = input_data[index].strip()
            index += 1
            parts = line.split()
            s, p, r = map(int, parts)
            if s == 0 and p == 0 and r == 0:
                break
            deals.append((s, p, r))
        while index < len(input_data):
            line = input_data[index].strip()
            index += 1
            if line == "0":
                break
            nights = int(line)
            min_cost = nights
            for s, p, r in deals:
                for k in range(1, r + 1):
                    if k * s >= nights:
                        cost = k * p
                    else:
                        cost = k * p + (nights - k * s)
                    if cost < min_cost:
                        min_cost = cost
            night_word = "night" if nights == 1 else "nights"
            output_lines.append(f"Stay {nights} {night_word} at {hotel_name}, pay {min_cost}.")
    sys.stdout.write("\n".join(output_lines))

if __name__ == "__main__":
    main()