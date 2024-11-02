#=====================================================================
#   16218번:    힘 겨루기                   
#   @date:   2024-10-13              
#   @link:   https://www.acmicpc.net/problem/16218  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

import sys
input = sys.stdin.read

def overpower_duel(N, K, A, B):
    junie_accumulated = 0
    ai_accumulated = 0
    used_overpower = False
    overpower_applied = False

    # Iterate through each round
    for i in range(N):
        # Calculate accumulative force without using OverPower
        junie_accumulated += A[i]
        ai_accumulated += B[i]

        # Check if either reaches or exceeds the threshold K
        if junie_accumulated >= K and ai_accumulated >= K:
            return 1 if not used_overpower else -1
        elif junie_accumulated >= K:
            return 1
        elif ai_accumulated >= K:
            return -1
        
        # Check if Junie has over 50 more accumulative force compared to AI
        if junie_accumulated - ai_accumulated >= 50:
            return 1

        # Calculate accumulative force if OverPower is used on this round
        if not used_overpower and not overpower_applied:
            overpower_force = (A[i] * 3) // 2  # Using OverPower
            additional_force = overpower_force - A[i]
            junie_accumulated = junie_accumulated - A[i] + overpower_force
            overpower_applied = True

            # Apply debuff to next round if there is one
            if i + 1 < N:
                A[i + 1] = max(A[i + 1] - additional_force, 0)

            # Mark OverPower as used
            used_overpower = True

    return 0

def main():
    data = input().splitlines()
    N, K = map(int, data[0].split())
    A = map(int, (line.split()[0] for line in data[1:N + 1]))
    B = map(int, (line.split()[1] for line in data[1:N + 1]))

    result = overpower_duel(N, K, list(A), list(B))
    print(result)

if __name__ == "__main__":
    main()