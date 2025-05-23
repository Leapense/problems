class DeliverySolver:
    def solve(self):
        import sys
        input = sys.stdin.readline
        T = int(input())
        for _ in range(T):
            N, PA, PB = map(int, input().split())
            Xs = list(map(int, input().split()))
            sumA = 0
            sumB = 0
            tieCount = 0
            costTie = 0
            for x in Xs:
                distA = 2 * abs(x - PA)
                distB = 2 * abs(x - PB)
                if distA < distB:
                    sumA += distA
                elif distA > distB:
                    sumB += distB
                else:
                    tieCount += 1
                    costTie = distA

            baseSum = sumA + sumB
            totalSum = baseSum + tieCount * costTie
            diff0 = sumA - sumB
            if tieCount == 0:
                print(totalSum, abs(diff0))
                continue
            def f(k):
                return diff0 + costTie * (2 * k - tieCount)
            crossNum = tieCount * costTie - diff0
            crossDen = costTie
            kFloat = crossNum / (2 * crossDen)
            kFloor = int(kFloat)
            candidates = [kFloor, kFloor + 1]
            bestDiff = None

            for cand in candidates:
                if cand < 0:
                    cand = 0
                if cand > tieCount:
                    cand = tieCount
                val = abs(f(cand))
                if bestDiff is None or val < bestDiff:
                    bestDiff = val
            print(totalSum, bestDiff)

if __name__ == "__main__":
    DeliverySolver().solve()