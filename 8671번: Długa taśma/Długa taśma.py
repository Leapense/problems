def minimal_average_of_subarray(n, array):
    # 배열의 요소 중 최소값을 찾는다.
    min_value = min(array)
    
    # 연속된 두 개의 원소로 이루어진 부분 수열의 최소 평균 계산
    for i in range(n - 1):
        two_sum = array[i] + array[i + 1]
        current_avg = two_sum / 2.0
        if current_avg < min_value:
            min_value = current_avg

    # 결과를 소수점 두 자리 형식으로 반환
    return format(min_value, ".2f")

n = int(input())
array = list(map(int, input().split()))
print(minimal_average_of_subarray(n, array))