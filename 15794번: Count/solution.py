import sys
def solve():
    try:
        n_str = sys.stdin.readline()
        if not n_str:
            return
        n = int(n_str)
        a = list(map(int, sys.stdin.readline().split()))
        v = int(sys.stdin.readline())
    except (IOError, ValueError):
        return
    
    a.sort()
    min_diff = float('inf')
    left, right = 0, n - 1
    while left < right:
        current_sum = a[left] + a[right]
        diff = abs(current_sum - v)

        if diff < min_diff:
            min_diff = diff
        
        if current_sum < v:
            left += 1
        elif current_sum > v:
            right -= 1
        else:
            min_diff = 0
            break
    if n < 2:
        print(0)
        return
    
    total_count = 0
    target1 = v - min_diff
    target2 = v + min_diff

    total_count += count_pairs_for_target(a, n, target1)
    if target1 != target2:
        total_count += count_pairs_for_target(a, n, target2)
    
    print(total_count)

def count_pairs_for_target(arr, size, target):
    count = 0
    left, right = 0, size - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum < target:
            left += 1
        elif current_sum > target:
            right -= 1
        else:
            if arr[left] == arr[right]:
                num_equal = right - left + 1
                count += num_equal * (num_equal - 1) // 2
                break

            l_val = arr[left]
            r_val = arr[right]
            l_count = 0
            r_count = 0

            temp_l = left
            while temp_l < right and arr[temp_l] == l_val:
                l_count += 1
                temp_l += 1

            temp_r = right
            while temp_r > left and arr[temp_r] == r_val:
                r_count += 1
                temp_r -= 1
            
            count += l_count * r_count
            left = temp_l
            right = temp_r
    return count

if __name__ == "__main__":
    solve()