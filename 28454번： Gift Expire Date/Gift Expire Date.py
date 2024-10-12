from datetime import datetime

# 입력
current_date_str = input().strip()
current_date = datetime.strptime(current_date_str, "%Y-%m-%d")

N = int(input().strip())
valid_gifticon_count = 0

for _ in range(N):
    gifticon_date_str = input().strip()
    gifticon_date = datetime.strptime(gifticon_date_str, "%Y-%m-%d")
    
    if gifticon_date >= current_date:
        valid_gifticon_count += 1

# 결과 출력
print(valid_gifticon_count)