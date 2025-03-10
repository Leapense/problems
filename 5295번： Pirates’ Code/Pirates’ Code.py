def main():
    import sys
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    arr = data[1:]
    arr.sort()
    witness = None
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] == arr[j]:
                continue
            d = arr[j] - arr[i]
            candidate = arr[j] + d
            lo = j + 1
            hi = len(arr) - 1
            found = False
            while lo <= hi:
                mid = (lo + hi) // 2
                if arr[mid] == candidate:
                    witness = (arr[i], arr[j], candidate)
                    found = True
                    break
                elif arr[mid] < candidate:
                    lo = mid + 1
                else:
                    hi = mid - 1
            if found:
                break
        if witness:
            break
    if witness:
        sys.stdout.write("Sequence is not 3-free. Witness: " + str(witness[0]) + "," + str(witness[1]) + "," + str(witness[2]) + ".")
    else:
        sys.stdout.write("Sequence is 3-free.")

if __name__ == "__main__":
    main()