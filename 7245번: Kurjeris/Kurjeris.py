# 입력 파싱
import sys
input = sys.stdin.read

data = input().split()
N = int(data[0])
M = int(data[1])
orders = []
index = 2

for _ in range(M):
    t = int(data[index])
    v = int(data[index+1])
    z = list(map(int, data[index+2:index+2+N]))
    orders.append((t, v, z))
    index += 2 + N

# 배달원의 상태 관리
couriers = [{'time': 0, 'profit': 0} for _ in range(N)]

# 주문 처리
for t, v, z in orders:
    min_time = float('inf')
    selected_courier = -1
    
    # 가장 빠르게 주문을 처리할 수 있는 배달원 찾기
    for i in range(N):
        if couriers[i]['time'] <= t and z[i] < min_time:
            min_time = z[i]
            selected_courier = i
    
    # 선택된 배달원이 없으면 주문 무시
    if selected_courier != -1:
        couriers[selected_courier]['time'] = t + z[selected_courier]
        couriers[selected_courier]['profit'] += v

# 결과 출력
print(' '.join(str(couriers[i]['profit']) for i in range(N)))