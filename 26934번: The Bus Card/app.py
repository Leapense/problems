#=====================================================================
#   26934번:    The Bus Card                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/26934  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

def min_transactions(K):
    denominations = [100, 200, 500]
    max_denom = max(denominations)
    max_amount = K + max_denom

    INF = float('inf')
    dp = [(INF, INF)] * (max_amount + 1)
    dp[0] = (0, 0)

    for denom in denominations:
        for amount in range(max_amount - denom + 1):
            if dp[amount][0] < INF:
                new_amount = amount + denom
                overcharge = max(0, new_amount - K)
                current_overcharge, current_tx = dp[new_amount]
                new_overcharge = overcharge
                new_tx = dp[amount][1] + 1

                if new_overcharge < current_overcharge or (new_overcharge == current_overcharge and new_tx < current_tx):
                    dp[new_amount] = (new_overcharge, new_tx)

    min_overcharge = INF
    min_tx = INF
    for amount in range(K, max_amount + 1):
        overcharge, tx = dp[amount]
        if overcharge < min_overcharge:
            min_overcharge = overcharge
            min_tx = tx
        elif overcharge == min_overcharge and tx < min_tx:
            min_tx = tx

    return min_tx

if __name__ == '__main__':
    K = int(input())
    print(min_transactions(K))

