#=====================================================================
#   28795번:    Светский приём                   
#   @date:   2024-11-02              
#   @link:   https://www.acmicpc.net/problem/28795  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

def generate_route(q, p):
    # Start at (0, 0) and ensure the route has enough points to sync times
    route = [(0, 0)]

    # Ensure the route has at least two points
    if q == p:
        route.append((1, 1))  # Simple direct route when speeds are the same
    else:
        # Calculate the number of steps needed to match the times
        steps = p // q + 1
        for i in range(1, steps):
            route.append((i, i % 2))  # Alternate between (x, 0) and (x, 1)
        route.append((steps, 0))

    return route

# Read input values
q, p = map(int, input().split())

# Generate the route
route = generate_route(q, p)

# Output the number of points
print(len(route))

# Output each point in the route
for x, y in route:
    print(x, y)
