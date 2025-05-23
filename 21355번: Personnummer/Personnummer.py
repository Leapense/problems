def main():
    social_security_number = input().strip()

    result = ""

    if '-' not in social_security_number:
        if social_security_number[:2] < "20":
            result = "19" + social_security_number
        else:
            result = "18" + social_security_number
    else:
        if social_security_number[:2] <= "20":
            result = "20" + social_security_number
        else:
            result = "19" + social_security_number

    for char in result:
        if char in ('+', '-'):
            continue
        print(char, end='')

    print()

if __name__ == "__main__":
    main()
