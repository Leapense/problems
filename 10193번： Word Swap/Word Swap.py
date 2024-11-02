def costToSwap(word1, word2):
    total_coins = 0
    for i in range(len(word1)):
        if word1[i] != word2[i]:
            diff = abs(ord(word1[i]) - ord(word2[i]))
            if word1[i] < word2[i]:
                total_coins -= diff
            else:
                total_coins += diff
    return total_coins

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    
    test_cases = int(data[0])
    results = []
    
    for i in range(1, test_cases + 1):
        word1, word2 = data[i].split()
        coins = costToSwap(word1, word2)
        
        if coins == 0:
            results.append(f"Swapping letters to make {word1} look like {word2} was FREE.")
        elif coins > 0:
            results.append(f"Swapping letters to make {word1} look like {word2} earned {coins} coins.")
        else:
            results.append(f"Swapping letters to make {word1} look like {word2} cost {-coins} coins.")
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()