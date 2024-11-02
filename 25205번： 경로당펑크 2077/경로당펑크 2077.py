def has_final_consonant(s):
    # 종성에 해당하는 두벌식 자판의 문자들 (순서대로)
    final_consonants = {
        'r', 'R', 's', 'e', 'E', 'f', 'a', 'q', 'Q', 't',
        'T', 'd', 'w', 'W', 'c', 'z', 'x', 'v', 'g'
    }
    
    # 문자열의 마지막 글자의 종성 여부를 판단
    if s[-1] in final_consonants:
        return 1
    else:
        return 0

# 입력 처리
N = int(input())
s = input().strip()

# 결과 출력
print(has_final_consonant(s))
