n, *rest = map(int, open(0).read().split())
ids = rest[:n]

E = sum(1 for x in ids if x % 2 == 0)
O = n - E

def can_form_k_groups(K, E, O):
    num_even_groups = (K + 1) // 2  # ceil(K / 2)
    num_odd_groups = K // 2         # floor(K / 2)
    
    even_cows_used = min(E, num_even_groups)
    odd_cows_needed_in_even_groups = max(0, num_even_groups - E) * 2
    odd_cows_needed_in_odd_groups = num_odd_groups
    
    odd_cows_needed = odd_cows_needed_in_even_groups + odd_cows_needed_in_odd_groups
    
    if odd_cows_needed > O:
        return False
    
    remaining_odd_cows = O - odd_cows_needed
    
    if remaining_odd_cows % 2 != 0:
        return False
    
    return True

for K in range(n, 0, -1):
    if can_form_k_groups(K, E, O):
        print(K)
        break
