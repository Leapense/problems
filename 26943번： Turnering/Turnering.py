def main():
    posses, turns = map(int, input().split())
    turns -= 1

    vec = [i for i in range(1, posses)]

    if turns > 0:
        vec = vec[-turns:] + vec[:-turns]

    vec.append(posses)

    half = posses // 2
    for i in range(half):
        print(f"{vec[i]}-{vec[posses - i - 1]}")

if __name__ == "__main__":
    main()