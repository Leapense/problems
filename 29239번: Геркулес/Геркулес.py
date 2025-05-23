import sys

def main():
    while True:
        input_line = sys.stdin.readline()
        if not input_line:
            break
        input_line = input_line.strip()

        if input_line == "Success":
            break
        elif input_line in ["Warmer", "Colder"]:
            if input_line == "Warmer":
                print(1)
            else:
                print(2)
        else:
            print(1)

        sys.stdout.flush()

if __name__ == "__main__":
    main()