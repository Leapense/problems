import sys

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    # 첫 번째 줄 처리
    first_line = data[0].split()
    N = int(first_line[0])
    S = first_line[1]
    
    total_deleted = 0

    # 아이템 정보 처리
    for i in range(1, N + 1):
        item_info = data[i].split()
        item_name = item_info[0]
        item_quantity = int(item_info[1])
        
        # 아이템 이름을 '_'로 나누어 단어 리스트 생성
        words = item_name.split('_')
        
        # S가 포함된 경우 수량 추가
        if S in words:
            total_deleted += item_quantity
    
    # 결과 출력
    print(total_deleted)

if __name__ == "__main__":
    main()