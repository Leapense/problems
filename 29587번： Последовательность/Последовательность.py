def find_max_non_increasing_subsequence(n, arr):
    # Проверим, существует ли хоть одна возрастающая подпоследовательность
    is_strictly_increasing = True
    for i in range(1, n):
        if arr[i] <= arr[i - 1]:
            is_strictly_increasing = False
            break
    
    # Если вся последовательность строго возрастающая, возвращаем 0
    if is_strictly_increasing:
        print(0)
        return
    
    # Ищем максимальную невозрастающую подпоследовательность
    indices = []
    for i in range(n):
        if not indices or arr[i] <= arr[indices[-1] - 1]:
            indices.append(i + 1)
    
    # Выводим результат
    print(len(indices))
    print(" ".join(map(str, indices)))

# Чтение входных данных
n = int(input())
arr = list(map(int, input().split()))

# Вызов функции
find_max_non_increasing_subsequence(n, arr)