import sys, heapq

def main() -> None:
    data = sys.stdin.read().split()
    if not data:              # (재-import 등으로) 더 읽을 것이 없으면 종료
        return

    n = int(data[0])
    m = int(data[1])
    times = list(map(int, data[2:])) if n else []

    if n == 0:
        print(0)
        return

    times.sort()
    k = m if m < n else n
    h = [0] * k
    heapq.heapify(h)

    total = 0
    for t in times:
        s = heapq.heappop(h)
        fin = s + t
        total += fin
        heapq.heappush(h, fin)

    print(total)

main()    # 가드 없이 호출 (테스트 환경 호환)