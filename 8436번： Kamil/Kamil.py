from itertools import product

def possible_words_count(kamil_word):
    # 변환 규칙 정의
    transformation_map = {
        'K': ['K', 'T'],
        'T': ['T'],
        'G': ['G', 'D'],
        'D': ['D'],
        'R': ['R', 'L', 'F'],
        'L': ['L'],
        'F': ['F']
    }

    # 각 문자에 대해 변환 가능성을 찾습니다.
    possibilities = [transformation_map.get(char, [char]) for char in kamil_word]

    # 가능한 모든 조합을 생성합니다.
    all_combinations = product(*possibilities)

    # 고유한 조합의 수를 반환합니다.
    unique_words = set(''.join(combination) for combination in all_combinations)
    return len(unique_words)

# 입력을 읽고 결과를 출력합니다.
if __name__ == "__main__":
    import sys
    input_word = sys.stdin.readline().strip()
    print(possible_words_count(input_word))