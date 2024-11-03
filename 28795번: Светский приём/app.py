#=====================================================================
#   28795번:    Светский приём                   
#   @date:   2024-11-02              
#   @link:   https://www.acmicpc.net/problem/28795  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

import math

def find_route(q, p):
    # If p == q, straight line
    if p == q:
        return [(0, 0), (1, 0)]
    
    # Calculate the multiplier
    multiplier = p / q
    
    # Choose endpoint (multiplier, 0) to simplify
    xf, yf = int(multiplier), 0
    d = math.hypot(xf, yf)
    total_length = multiplier * d  # which is p/q * d
    
    # Start building the path
    path = [(0, 0)]
    
    # To increase the path length, we can make a zigzag
    # For simplicity, move vertically by 1 unit up and down
    # Each up and down adds 2 units to the path length
    # We need to add (total_length - d) units through detours
    # Number of detours needed:
    extra_length = total_length - d
    num_detours = int(extra_length)
    
    # Current position
    x, y = 0, 0
    for i in range(num_detours):
        # Move up
        path.append((x, y + 1))
        y += 1
        # Move right
        path.append((x + 1, y))
        x += 1
        # Move down
        path.append((x, y - 1))
        y -= 1
    
    # Finally, move to the endpoint
    if (x, y) != (xf, yf):
        path.append((xf, yf))
    
    return path

# Read input
q, p = map(int, input().split())

route = find_route(q, p)

# Ensure the route has at least 2 points and no two consecutive points are the same
if len(route) < 2:
    route = [(0,0), (1,0)]
for i in range(1, len(route)):
    if route[i] == route[i-1]:
        # Adjust by moving up
        x, y = route[i]
        route[i] = (x, y+1)

# Output the route
print(len(route))
for point in route:
    print(point[0], point[1])


