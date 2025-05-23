import sys

def main():
    input = sys.stdin.read().split()
    N = int(input[0])
    digits = ''.join(input[1:N+1])
    k = 0
    while True:
        if str(k) not in digits:
            print(k)
            return
        k += 1
main()