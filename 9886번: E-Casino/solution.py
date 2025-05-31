import sys

def main():
    # 한 줄로 주어진 입력(총 2113문자)을 읽는다.
    line = sys.stdin.readline().strip()

    pos_percent = line.find('%')
    if pos_percent == -1:
        return

    # 앞의 64문자: 관측된 r[0..63]
    observed = line[:pos_percent]
    # 64번째 index 문자는 '%', 그 뒤 2048문자는 S[0..2047]
    S_string = line[pos_percent + 1:] # 인덱스 65부터 끝까지 (총 2048문자)

    try:
        r_bits = [int(ch) for ch in observed]
        S_bits = [int(ch) for ch in S_string]
    except ValueError:
        return

    total_observed = len(r_bits)
    if total_observed % 2 != 0:
        return

    M = total_observed // 2
    N = len(S_bits)

    # k 후보를 0부터 순회
    for k in range(N):
        valid = True # 이 k가 가능한 후보인지 플래그
        # u: m[u] = r[u] XOR S[k+u] 식과 비교를 위해 0..31 순회
        for u in range(M):
            idx1 = (k + u) % N
            idx2 = (k + u + M) % N # M = 32이므로... (k + u + 32) % 2048
            # 두 경우에서 XOR 결과가 동일해야 한다.
            val1 = S_bits[idx1] ^ r_bits[u]
            val2 = S_bits[idx2] ^ r_bits[u + M]
            if val1 != val2:
                # 일치하지 않으면 이 k는 불가능
                valid = False
                break
        
        if valid:
            # 조건을 모두 만족한 최초의 k를 출력하고 종료
            print(k)
            return
        
if __name__ == "__main__":
    main()