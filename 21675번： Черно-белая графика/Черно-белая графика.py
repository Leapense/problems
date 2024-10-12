def combine_images(w, h, img1, img2, truth_table):
    result_image = []
    for i in range(h):
        result_row = ""
        for j in range(w):
            pixel1 = int(img1[i][j])
            pixel2 = int(img2[i][j])
            # Determine the index in the truth table
            index = pixel1 * 2 + pixel2
            result_row += str(truth_table[index])
        result_image.append(result_row)
    return result_image

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    w = int(data[0])
    h = int(data[1])
    
    img1 = []
    img2 = []
    
    offset = 2
    for i in range(h):
        img1.append(data[offset + i])
    
    for i in range(h):
        img2.append(data[offset + h + i])
    
    truth_table = list(map(int, data[-1]))
    
    result = combine_images(w, h, img1, img2, truth_table)
    
    for row in result:
        print(row)

if __name__ == "__main__":
    main()
