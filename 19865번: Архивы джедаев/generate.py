from random import randint, sample, seed

def generate_case(n_limit=1000, m_limit=10, seed_value=42):
    seed(seed_value)
    N = n_limit
    planets = list(range(1, N + 1))
    m = randint(0, min(m_limit, N // 2))
    removed = set(sample(planets, m))
    survivors = [x for x in planets if x not in removed]

    pivot_index = randint(0, len(survivors) - 1)
    rotated = survivors[pivot_index:] + survivors[:pivot_index]
    planet_to_index = {planet: i + 1 for i, planet in enumerate(rotated)}
    if randint(0, 4) == 0 and len(removed) > 0:
        x = sample(list(removed), 1)[0]
        answer = -1
    else:
        x = sample(survivors, 1)[0]
        answer = planet_to_index[x]
    return {
        "x": x,
        "m": m,
        "removed": removed,
        "pivot_index": pivot_index,
        "array": rotated,
        "answer": answer,
        "interactive": lambda idx: rotated[idx - 1]  # 1-based indexing
    }

if __name__ == "__main__":
    case = generate_case(n_limit=30, m_limit=5, seed_value=2025)
    print(f"x = {case['x']}, m = {case['m']}")
    print(f"삭제된 행성: {sorted(case['removed'])}")
    print(f"회전 시작 인덱스: {case['pivot_index']}")
    print(f"회전된 배열: {case['array']}")
    print("셀 인덱스 질의 시뮬레이션:")
    for i in range(1, len(case["array"]) + 1):
        print(f"? {i} => {case['interactive'](i)}")
    print(f"정답: {case['answer']}")