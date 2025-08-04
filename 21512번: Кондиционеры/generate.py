import random
import sys

def generate_test_case():
    """
    주어진 소스 코드를 위한 무작위 테스트 케이스를 생성하고 표준 출력으로 내보냅니다.
    """
    # 1. n과 m의 크기를 무작위로 결정합니다.
    # 문제의 복잡도를 다양하게 하기 위해 1부터 100, 200 사이의 값으로 설정합니다.
    n = random.randint(1, 100)
    m = random.randint(1, 200)

    # 원본 코드의 제약 조건과 유사한 상수를 정의합니다.
    MAX_POWER = 1000
    MAX_COST = 10000

    # 2. n개의 '요구 능력치' 목록을 생성합니다.
    # 1부터 MAX_POWER 사이의 값을 가집니다.
    required_powers = [random.randint(1, MAX_POWER) for _ in range(n)]

    # 3. m개의 '능력치-비용' 쌍을 생성합니다.
    # 이 과정에서 핵심 로직을 테스트하기 위한 다양한 시나리오를 포함시킵니다.
    power_cost_pairs = []
    for _ in range(m):
        power = random.randint(1, MAX_POWER)
        
        # 의도적으로 더 높은 능력치가 더 저렴한 비용을 갖는 경우를 만듭니다.
        # 10%의 확률로 비용을 매우 낮게 설정하여 '가성비 좋은' 상위 능력치를 생성합니다.
        if random.random() < 0.1:
            cost = random.randint(1, MAX_COST // 10)
        else:
            cost = random.randint(MAX_COST // 10, MAX_COST)
            
        power_cost_pairs.append((power, cost))
        
        # 20%의 확률로 동일한 능력치에 다른 비용 옵션을 추가합니다.
        # 이는 min() 함수의 작동을 테스트하는 데 효과적입니다.
        if random.random() < 0.2:
            another_cost = random.randint(1, MAX_COST)
            power_cost_pairs.append((power, another_cost))

    # 생성된 m개의 쌍 중 일부만 사용할 수 있으므로, m을 실제 쌍의 개수로 업데이트합니다.
    m = len(power_cost_pairs)

    # 4. 표준 입력 형식에 맞추어 생성된 데이터를 출력합니다.
    # n 출력
    print(n)
    # required_powers 리스트를 공백으로 구분하여 한 줄에 출력
    print(*required_powers)
    # m 출력
    print(m)
    # m개의 (power, cost) 쌍을 각 줄에 출력
    for power, cost in power_cost_pairs:
        print(power, cost)

if __name__ == "__main__":
    generate_test_case()