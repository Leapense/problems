import sys

def main():
    lines = sys.stdin.read().splitlines()
    pointer =0
    tri =1
    output = []
    while pointer < len(lines):
        if lines[pointer].strip() == '':
            pointer +=1
            continue
        n = int(lines[pointer])
        pointer +=1
        if n ==0:
            break
        grid = []
        for k in range(n):
            if pointer >= len(lines):
                line = ''
            else:
                line = lines[pointer]
                pointer +=1
            stripped_line = line.lstrip()
            padded_line = ' ' *k + stripped_line
            if len(padded_line) <2*n -1:
                padded_line += ' ' * (2*n -1 - len(padded_line))
            elif len(padded_line) >2*n -1:
                padded_line = padded_line[:2*n -1]
            grid.append(list(padded_line))
        # Compute h_up
        h_up = [ [0]*(2*n -1) for _ in range(n)]
        for i in range(n-1, -1, -1):
            for j in range(2*n -1):
                if grid[i][j] == '-':
                    if i ==n-1 or j ==0 or j ==2*n -2:
                        h_up[i][j] =1
                    else:
                        if grid[i+1][j-1] == '-' and grid[i+1][j] == '-' and grid[i+1][j+1] == '-':
                            h_up[i][j] =1 + min(h_up[i+1][j-1], h_up[i+1][j], h_up[i+1][j+1])
                        else:
                            h_up[i][j] =1
                else:
                    h_up[i][j] =0
        # Compute h_down
        h_down = [ [0]*(2*n -1) for _ in range(n)]
        for i in range(n):
            for j in range(2*n -1):
                if grid[i][j] == '-':
                    if i ==0 or j ==0 or j ==2*n -2:
                        h_down[i][j] =1
                    else:
                        if grid[i-1][j-1] == '-' and grid[i-1][j] == '-' and grid[i-1][j+1] == '-':
                            h_down[i][j] =1 + min(h_down[i-1][j-1], h_down[i-1][j], h_down[i-1][j+1])
                        else:
                            h_down[i][j] =1
                else:
                    h_down[i][j] =0
        # Find max_h
        max_h =0
        for i in range(n):
            for j in range(2*n -1):
                if grid[i][j] == '-':
                    h = h_up[i][j] + h_down[i][j] -1
                    if h > max_h:
                        max_h =h
        area = max_h * max_h
        output.append(f"Triangle #{tri}")
        output.append(f"The largest triangle area is {area}.")
        output.append("")
        tri +=1
    if output and output[-1] == '':
        output.pop()
    print('\n'.join(output))

if __name__ == "__main__":
    main()