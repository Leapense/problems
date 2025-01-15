def find_item_to_buy():
    b = int(input().strip())
    watermelon_price = int(input().strip())
    pomegranate_price = int(input().strip())
    nuts_price = int(input().strip())

    if b >= watermelon_price:
        print("Watermelon")
    elif b >= pomegranate_price:
        print("Pomegranates")
    elif b >= nuts_price:
        print("Nuts")
    else:
        print("Nothing")

if __name__ == '__main__':
    find_item_to_buy()