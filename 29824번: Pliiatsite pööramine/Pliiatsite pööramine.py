def main():
    N = int(input())
    pencils = input().strip()
    
    # 두 가지 목표 문자를 고려
    targets = ['t', 'n']
    results = []
    
    for target in targets:
        flips = []
        current = list(pencils)
        
        while True:
            # 현재 상태에서 목표 문자와 다른 연필의 위치를 찾음
            mismatches = [i for i in range(N) if current[i] != target]
            if not mismatches:
                break
            # 첫 번째와 마지막 불일치 위치를 찾음
            first = mismatches[0]
            last = mismatches[-1]
            # 플립 구간을 기록 (1-based indexing)
            flips.append((first + 1, last + 1))
            # 해당 구간을 플립
            for i in range(first, last + 1):
                current[i] = 't' if current[i] == 'n' else 'n'
        
        results.append(flips)
    
    # 두 경우 중 플립 횟수가 적은 경우를 선택
    if len(results[0]) <= len(results[1]):
        selected_flips = results[0]
    else:
        selected_flips = results[1]
    
    # 출력
    print(len(selected_flips))
    for flip in selected_flips:
        print(f"{flip[0]}-{flip[1]}")

if __name__ == "__main__":
    main()