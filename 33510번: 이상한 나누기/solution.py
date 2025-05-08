import sys

def main_logic():
    _ = int(sys.stdin.readline())
    x_str = sys.stdin.readline().strip()

    x_list = list(x_str)
    odd_op_count = 0

    while True:
        current_len = len(x_list)
        if current_len == 1 and x_list[0] == '1':
            break

        if x_list[current_len - 1] == '0':
            x_list.pop()
        else:
            odd_op_count += 1
            idx = current_len - 1
            while idx >= 0:
                if x_list[idx] == '1':
                    x_list[idx] = '0'
                    idx -= 1
                else:
                    x_list[idx] = '1'
                    break
            if idx < 0:
                x_list.insert(0, '1')

            x_list.pop()

    sys.stdout.write(str(odd_op_count) + "\n")

if __name__ == "__main__":
    main_logic()