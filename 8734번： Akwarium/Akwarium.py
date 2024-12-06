import sys
import heapq
input = sys.stdin.readline
INF = 10**15

n = int(input().strip())
fish_data = [None]*(n+1)
for i in range(1, n+1):
    m, w = map(int, input().split())
    fish_data[i] = (m, w)

z = int(input().strip())
queries = [tuple(map(int, input().split())) for _ in range(z)]

dayOfDeath = [INF]*(n+1)

# Initial population
population = [(fish_data[i][0], fish_data[i][1], i) for i in range(1, n+1)]

day = 0
while population:
    day += 1
    # Build heaps
    eaters_heap = []
    victims_heap = []
    for (m, w, i) in population:
        heapq.heappush(eaters_heap, (-m, -w, i))
        heapq.heappush(victims_heap, (m, w, i))

    valid = set(i for _, _, i in population)
    new_survivors = []

    while eaters_heap:
        em, ew, eid = heapq.heappop(eaters_heap)
        em = -em
        ew = -ew
        if eid not in valid:
            continue

        while victims_heap and victims_heap[0][2] not in valid:
            heapq.heappop(victims_heap)

        if victims_heap:
            vm, vw, vid = victims_heap[0]
            if vm < em:
                # eat victim
                heapq.heappop(victims_heap)
                valid.remove(vid)
                dayOfDeath[vid] = day
                # update eater mass
                new_mass = em + (vm // 2)
                # eater survives
                new_survivors.append((new_mass, ew, eid))
            else:
                # no suitable victim
                valid.remove(eid)
                dayOfDeath[eid] = day
        else:
            # no victims
            valid.remove(eid)
            dayOfDeath[eid] = day

    if not new_survivors:
        break

    population = new_survivors


for r, x in queries:
    if x < dayOfDeath[r]:
        print("TAK")
    else:
        print("NIE")