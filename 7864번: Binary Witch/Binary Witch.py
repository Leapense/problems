import sys, bisect
input = sys.stdin.readline
N, L = map(int, input().split())
# 입력 문자열을 정수 리스트로 변환 (0,1)
seq = list(map(int, input().strip()))

# pat_occ[t]는 길이 t 패턴에 대해 {pattern: (last_occurrence, second_last_occurrence)} 를 저장
pat_occ = [{} for _ in range(14)]
tmax = min(13, N)

# 초기 수열에 대한 처리: 각 t=1..tmax에 대해 슬라이딩 윈도우로 최근 두 번 등장 위치 저장
for t in range(1, tmax+1):
    mask = (1 << t) - 1
    d = pat_occ[t]
    # 처음 t자리
    p = 0
    for j in range(t):
        p = (p << 1) | seq[j]
    d[p] = (0, -1)  # 최초 등장: 시작 인덱스 0, 이전 등장 없음
    # 이후 위치: i = 1 ~ N-t
    for i in range(1, N - t + 1):
        # rolling update: 기존 패턴에서 맨 앞 비트를 버리고, 새 비트를 추가
        p = ((p << 1) & mask) | seq[i+t-1]
        if p in d:
            # (last, second)에서 새 등장으로 인해 업데이트: 새 last = i, 이전 last를 second로
            last, _ = d[p]
            d[p] = (i, last)
        else:
            d[p] = (i, -1)

M = N  # 현재 수열 길이
ans = []
# L번 예측 진행
for _ in range(L):
    predicted = 0
    found = False
    # t = 13 부터 1까지 검사 (t가 현재 수열 길이보다 크면 건너뜀)
    for t in range(13, 0, -1):
        if t > M:
            continue
        p = 0
        # 현재 수열의 마지막 t자리 패턴 계산
        for j in range(M - t, M):
            p = (p << 1) | seq[j]
        d = pat_occ[t]
        if p in d:
            last, second = d[p]
            # 현재 수열의 접미사 시작 인덱스는 M-t
            if last == M - t:
                cand = second
            else:
                cand = last
            if cand != -1:
                # 예측값은 cand 위치 다음의 값
                predicted = seq[cand + t]
                found = True
                break
    # 예측값이 없으면 predicted는 0 (이미 설정됨)
    seq.append(predicted)
    ans.append(str(predicted))
    M += 1
    # 새로 추가된 숫자에 대해 길이 1부터 min(13, M)까지의 패턴 업데이트
    new_M = M
    t_lim = min(13, new_M)
    for t in range(1, t_lim+1):
        p = 0
        for j in range(new_M - t, new_M):
            p = (p << 1) | seq[j]
        d = pat_occ[t]
        # 새로 추가된 패턴의 시작 인덱스는 new_M - t
        if p in d:
            last, _ = d[p]
            d[p] = (new_M - t, last)
        else:
            d[p] = (new_M - t, -1)

sys.stdout.write("".join(ans))
