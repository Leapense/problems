class BookReturnDistanceCalculator:
    def __init__(self, N, K, shelves):
        """
        :param N: 책의 총 개수
        :param K: 한 번에 옮길 수 있는 최대 책 수
        :param shelves: 각 책이 놓일 x 좌표 리스트
        """
        self.N = N
        self.K = K
        self.shelves = shelves
        
    def compute_minimum_distance(self):
        # 1. 음수 좌표, 양수 좌표 분리
        positives = []
        negatives = []
        for x in self.shelves:
            if x > 0:
                positives.append(x)
            else:
                negatives.append(x)
        
        # 2. 절댓값 기준 내림차순 정렬
        positives.sort(reverse=True)  # 양수는 큰 순으로
        negatives.sort()              # 음수는 작은 순(절댓값 큰 순으로 보려면 오름차순 정렬 상태로 처리)
        
        # 3. 그룹별 왕복 비용 계산
        distance_sum = 0
        
        # 양수 처리
        for i in range(0, len(positives), self.K):
            # 현재 그룹에서 가장 멀리 떨어진 위치
            distance_sum += positives[i] * 2
        
        # 음수 처리
        # negatives는 오름차순(-4, -3 ...)이므로 뒤에서부터 K개씩 묶을 때 절댓값이 가장 큰 것을 커버
        for i in range(0, len(negatives), self.K):
            # 음수 좌표는 예: -4 -> 절댓값 4
            distance_sum += abs(negatives[i]) * 2
        
        # 4. 가장 멀리 떨어진 좌표(절댓값 기준) 찾기
        #   (가장 큰 절댓값을 가진 좌표 = 마지막 왕복에서 돌아올 필요가 없으므로 그만큼 빼줌)
        max_distance = 0
        if positives:  # 양수 중 절댓값 최댓값
            max_distance = max(max_distance, positives[0])
        if negatives:  # 음수 중 절댓값 최댓값
            max_distance = max(max_distance, abs(negatives[0]))
        
        # 5. 마지막 귀환 비용 절약
        distance_sum -= max_distance
        
        return distance_sum


# 사용 예시
if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().strip().split()
    N, K = map(int, input_data[:2])
    shelves = list(map(int, input_data[2:]))

    calculator = BookReturnDistanceCalculator(N, K, shelves)
    result = calculator.compute_minimum_distance()
    print(result)