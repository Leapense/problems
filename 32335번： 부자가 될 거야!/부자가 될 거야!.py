import sys

def main():
    import sys
    import threading

    def solve():
        N, M = map(int, sys.stdin.readline().split())
        S = sys.stdin.readline().strip()
        D = [int(c) for c in S]
        rem = M
        result = []

        for d in D:
            c0 = (10 - d) % 10
            if c0 <= rem:
                result.append('0')
                rem -= c0
            else:
                result.append(str(d))

        print(''.join(result))

    threading.Thread(target=solve).start()
    
if __name__ == '__main__':
    main()
