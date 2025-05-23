def is_valid(password: str) -> bool:
    # 1. 길이 검사
    if not (9 <= len(password) <= 20):
        return False

    # 검사를 위한 문자 분류
    lower_count = 0
    upper_count = 0
    digit_count = 0
    special_count = 0
    special_chars = set("!@#$%^&*.,;/?")

    for ch in password:
        if ch.islower():
            lower_count += 1
        elif ch.isupper():
            upper_count += 1
        elif ch.isdigit():
            digit_count += 1
        elif ch in special_chars:
            special_count += 1

    # 2. 소문자 2개 이상, 3. 대문자 2개 이상, 4. 숫자 1개 이상, 5. 특수문자 2개 이상 검사
    if lower_count < 2 or upper_count < 2 or digit_count < 1 or special_count < 2:
        return False

    # 6. 연속된 동일 문자 3개 이상 금지
    for i in range(len(password) - 2):
        if password[i] == password[i+1] == password[i+2]:
            return False

    # 7, 8 검사
    # 비영문숫자 제거 및 대소문자 무시
    alphanumeric_sequence = [ch.lower() for ch in password if ch.isalnum()]

    # 7. 알파뉴메릭 부분이 palindrome 인지 확인
    if alphanumeric_sequence == alphanumeric_sequence[::-1]:
        return False

    # 8. 특정 단어 패턴 검사 (순방향, 역방향 모두)
    forbidden_words = ["password", "virginia", "cavalier", "code"]
    seq_str = "".join(alphanumeric_sequence)
    for word in forbidden_words:
        rev_word = word[::-1]
        # subsequence 여부 확인을 위해 투포인터 사용
        # 알파뉴메릭 시퀀스가 word를 subsequence로 포함하는지 검사
        def is_subsequence(s, t):
            # s 안에 t가 subsequence로 존재하는지 확인
            it = iter(s)
            return all(c in it for c in t)
        
        if is_subsequence(seq_str, word) or is_subsequence(seq_str, rev_word):
            return False

    return True


if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().strip().split("\n")
    N = int(input_data[0])
    for i in range(1, N+1):
        pw = input_data[i].strip()
        if is_valid(pw):
            print("Valid Password")
        else:
            print("Invalid Password")