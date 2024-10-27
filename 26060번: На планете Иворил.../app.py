#=====================================================================
#   26060번:    На планете Иворил...                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/26060  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

def main():
    import sys
    def input():
        return sys.stdin.read()
    
    data = sys.stdin.read().split()
    N = int(data[0])
    words = data[1:]

    vowels = set('aeiouy')

    total_errors = 0

    for word in words:
        cost_verb = 0
        for c in word:
            if c not in vowels:
                cost_verb += 1

        cost_noun_vowel = 0

        for i, c in enumerate(word):
            if i % 2 == 0:
                if c not in vowels:
                    cost_noun_vowel += 1
            else:
                if c in vowels:
                    cost_noun_vowel += 1

        cost_noun_consonant = 0
        for i, c in enumerate(word):
            if i % 2 == 0:
                if c in vowels:
                    cost_noun_consonant += 1
            else:
                if c not in vowels:
                    cost_noun_consonant += 1

        cost_noun = min(cost_noun_consonant, cost_noun_vowel)

        total_errors += min(cost_verb, cost_noun)
    
    print(total_errors)

main()

