def find_special_card_index(n, card_values):
    total_sum = sum(card_values)
    
    for index in range(n):
        if card_values[index] * 2 == total_sum:
            return index + 1
        
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    card_values = list(map(int, data[1:]))
    
    print(find_special_card_index(n, card_values))

if __name__ == "__main__":
    main()