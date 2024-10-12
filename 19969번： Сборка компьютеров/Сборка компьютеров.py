def max_computer_sets(a1, a2, a3, b1, b2, b3):
    # Direct matches
    match_vga = min(a1, b1)
    match_dvi = min(a2, b2)
    
    # Use dual-interface items to resolve left-overs
    leftover_a1 = a1 - match_vga
    leftover_b1 = b1 - match_vga
    leftover_a2 = a2 - match_dvi
    leftover_b2 = b2 - match_dvi
    
    # Using dual-interface monitors (b3) for remaining a1 and a2
    match_a1_b3 = min(leftover_a1, b3)
    b3_after_a1 = b3 - match_a1_b3
    
    match_a2_b3 = min(leftover_a2, b3_after_a1)
    b3_after_a2 = b3_after_a1 - match_a2_b3
    
    # Using dual-interface PCs (a3) for remaining b1 and b2
    match_a3_b1 = min(a3, leftover_b1)
    a3_after_b1 = a3 - match_a3_b1
    
    match_a3_b2 = min(a3_after_b1, leftover_b2)
    a3_after_b2 = a3_after_b1 - match_a3_b2
    
    # Use remaining dual-interface against each other
    match_a3_b3 = min(a3_after_b2, b3_after_a2)
    
    # Sum all possible matches
    total_pairs = (match_vga + match_dvi + match_a1_b3 + match_a2_b3 +
                   match_a3_b1 + match_a3_b2 + match_a3_b3)
    
    return total_pairs

a1, a2, a3 = map(int, input().split())
b1, b2, b3 = map(int, input().split())

result = max_computer_sets(a1, a2, a3, b1, b2, b3)
print(result)