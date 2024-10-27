#=====================================================================
#   26420번:    Image Labeler                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/26420  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

T = int(input())
for test_case in range(1, T+1):
    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort(reverse=True)
    medians = []
    # Assign largest M-1 elements to M-1 categories
    for i in range(M-1):
        medians.append(float(A[i]))
    # Assign remaining elements to the last category
    remaining_elements = A[M-1:]
    remaining_elements.sort()
    size = len(remaining_elements)
    if size % 2 == 1:
        median = float(remaining_elements[size // 2])
    else:
        median = (remaining_elements[size // 2 - 1] + remaining_elements[size // 2]) / 2.0
    medians.append(median)
    total_median = sum(medians)
    print(f"Case #{test_case}: {total_median:.10f}")