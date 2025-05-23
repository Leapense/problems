import heapq

a, b, c, v0, v1, v2 = map(int, input().split())

distance = {
    ('H', 'M'): a,
    ('H', 'P'): b,
    ('M', 'H'): a,
    ('M', 'P'): c,
    ('P', 'H'): b,
    ('P', 'M'): c,
}

heap = []
heapq.heappush(heap, (0.0, 'H', 0, 0, 0))

dist = {}
initial_state = ('H', 0, 0, 0)
dist[initial_state] = 0.0

min_time = float('inf')

while heap:
    current_time, pos, g, p, carried = heapq.heappop(heap)
    
    if current_time > dist.get((pos, g, p, carried), float('inf')):
        continue
    
    if pos == 'H' and g == 1 and p == 1:
        if current_time < min_time:
            min_time = current_time
    
    if pos == 'H':
        neighbors = ['M', 'P']
    elif pos == 'M':
        neighbors = ['H', 'P']
    else:
        neighbors = ['H', 'M']
    
    for next_pos in neighbors:
        d = distance[(pos, next_pos)]
        
        if carried == 0:
            speed = v0
        elif carried == 1:
            speed = v1
        else:
            speed = v2
        
        time_spent = d / speed
        
        new_g = g
        if next_pos == 'M':
            new_g = max(g, 1)
        
        new_p = p
        if next_pos == 'P':
            new_p = max(p, 1)
        
        new_carried = carried
        if next_pos == 'M' and g == 0:
            new_carried += 1
        if next_pos == 'P' and p == 0:
            new_carried += 1
        
        if next_pos == 'H':
            new_carried = 0
        
        new_state = (next_pos, new_g, new_p, new_carried)
        new_time = current_time + time_spent
        
        if (new_state not in dist) or (new_time < dist.get(new_state, float('inf'))):
            dist[new_state] = new_time
            heapq.heappush(heap, (new_time, *new_state))

print("{0:.15f}".format(min_time))