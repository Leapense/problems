import sys,random

subtask1 = random.randint(0, 1001)
subtask2 = random.randint(0, 10001)
subtask3 = random.randint(0, 10**12 + 1)
subtask4 = random.randint(-1000, 1001)
subtask5 = random.randint(-10000, 10001)
subtask6 = random.randint(-10**12, 10**12 + 1)

def main():
    if len(sys.argv) != 2:
        print(f"사용법: {sys.argv[0]} <서브태스크 번호>")
        print("서브태스크 1: 0 이상 1,000 이하의 정수 k")
        print("서브태스크 2: 0 이상 10,000 이하의 정수 k")
        print("서브태스크 3: 0 이상 10^12 이하의 정수 k")
        print("서브태스크 4: -1,000 이상 1,000 이하의 정수 k")
        print("서브태스크 5: -10,000 이상 10,000 이하의 정수 k")
        print("서브태스크 6: -10^12 이상 10^12 이하의 정수 k")
        sys.exit(1)
    subtask_num = int(sys.argv[1])
    if subtask_num == 1:
        print(subtask1)
    elif subtask_num == 2:
        print(subtask2)
    elif subtask_num == 3:
        print(subtask3)
    elif subtask_num == 4:
        print(subtask4)
    elif subtask_num == 5:
        print(subtask5)
    elif subtask_num == 6:
        print(subtask6)

if __name__ == '__main__':
    main()