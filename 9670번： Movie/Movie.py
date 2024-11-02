# List of devices with their resolutions (height, width) and prices
devices = [
    (1024, 768, 319),
    (1024, 600, 419),
    (960, 640, 450),
    (2048, 1536, 519),
    (1136, 640, 599),
    (1280, 800, 600),
    (1080, 1920, 630),
    (1136, 640, 719)
]

def calculate_max_usage_ratio(H, W, dev_H, dev_W):
    # Calculate scaling factors and usage areas for both orientations
    scale_normal = min(dev_H / H, dev_W / W)
    area_normal = (scale_normal * H) * (scale_normal * W)
    usage_ratio_normal = area_normal / (dev_H * dev_W)
    
    # Calculate for the rotated screen
    scale_rotated = min(dev_W / H, dev_H / W)
    area_rotated = (scale_rotated * H) * (scale_rotated * W)
    usage_ratio_rotated = area_rotated / (dev_H * dev_W)
    
    # Return the maximum usage ratio from both orientations
    return max(usage_ratio_normal, usage_ratio_rotated)

def find_best_device(H, W):
    best_ratio = 0
    best_price = float('inf')

    # Iterate through each device to calculate the best usage ratio
    for dev_H, dev_W, price in devices:
        usage_ratio = calculate_max_usage_ratio(H, W, dev_H, dev_W)
        
        # Check if the current device has a better usage ratio or a better price in case of a tie
        if usage_ratio > best_ratio or (usage_ratio == best_ratio and price < best_price):
            best_ratio = usage_ratio
            best_price = price

    return best_price

# Process each test case input
while True:
    H, W = map(int, input().split())
    if H == 0 and W == 0:
        break
    print(find_best_device(H, W))