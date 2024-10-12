def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read dimensions
    t1_cm, t1_mm, t2_cm, t2_mm = map(int, data[0:4])
    b1_l_cm, b1_l_mm, b1_h_cm, b1_h_mm = map(int, data[4:8])
    b2_l_cm, b2_l_mm, b2_h_cm, b2_h_mm = map(int, data[8:12])
    
    # Convert all to millimeters
    t1 = t1_cm * 10 + t1_mm
    t2 = t2_cm * 10 + t2_mm
    b1_l = b1_l_cm * 10 + b1_l_mm
    b1_h = b1_h_cm * 10 + b1_h_mm
    b2_l = b2_l_cm * 10 + b2_l_mm
    b2_h = b2_h_cm * 10 + b2_h_mm
    
    # Calculate actual widths and heights for textbook and bindings
    textbook_width = min(t1, t2)
    textbook_height = max(t1, t2)
    
    binding1_width = min(b1_l, b1_h)
    binding1_height = max(b1_l, b1_h)
    binding2_width = min(b2_l, b2_h)
    binding2_height = max(b2_l, b2_h)
    
    # Binding suitability
    suitable_binding = 0
    selected_width = 0
    selected_height = 0
    
    # Check if binding 1 is suitable
    suitable1 = (binding1_width >= textbook_width + 10 and binding1_height >= textbook_height)
    
    # Check if binding 2 is suitable
    suitable2 = (binding2_width >= textbook_width + 10 and binding2_height >= textbook_height)
    
    if suitable1 and suitable2:
        # Choose the one with the smaller width
        if binding1_width < binding2_width:
            suitable_binding = 1
            selected_width = binding1_width
            selected_height = binding1_height
        else:
            suitable_binding = 2
            selected_width = binding2_width
            selected_height = binding2_height
    elif suitable1:
        suitable_binding = 1
        selected_width = binding1_width
        selected_height = binding1_height
    elif suitable2:
        suitable_binding = 2
        selected_width = binding2_width
        selected_height = binding2_height
    
    # Output the result
    if suitable_binding == 0:
        print(0)
    else:
        print(suitable_binding)
        # Print dimensions in cm and mm
        cm = selected_width // 10
        mm = selected_width % 10
        print(f"{cm}.{mm}", end=" ")
        cm = selected_height // 10
        mm = selected_height % 10
        print(f"{cm}.{mm}")

if __name__ == "__main__":
    solve()