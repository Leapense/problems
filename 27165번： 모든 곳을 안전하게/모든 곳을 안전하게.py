class BackgammonSafety:
    def solve(self):
        import sys
        input = sys.stdin.readline
        n = int(input())
        a = list(map(int, input().split()))
        x = int(input())
        s = [i for i in range(n + 1) if a[i] == 1]
        if len(s) > 2:
            print("NO")
            return
        for i in range(n + 1):
            if i + x > n:
                break
            if a[i] == 0 or a[i] == 2 or a[i + x] == 0:
                continue
            ok = True
            for cell in s:
                if cell != i and cell != i + x:
                    ok = False
                    break
            if ok:
                print("YES")
                print(i, i + x)
                return
        print("NO")

if __name__ == "__main__":
    BackgammonSafety().solve()