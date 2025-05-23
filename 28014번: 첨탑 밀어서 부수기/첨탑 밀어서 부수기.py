def minimum_pushes_to_collapse_towers(N, heights):
    pushes = 1
    for i in range(N - 1):
        if heights[i] <= heights[i + 1]:
            pushes += 1
        else:
            continue
    
    return pushes

# 입력 받기
N = int(input().strip())
heights = list(map(int, input().strip().split()))

# 함수 호출 및 결과 출력
result = minimum_pushes_to_collapse_towers(N, heights)
print(result)
