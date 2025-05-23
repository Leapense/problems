import sys
import math

def smooth_speeds(t_f, t_r, speeds):
    result = []
    last_display = None
    
    for s in speeds:
        if 0 < s < 1:
            display = 1
        else:
            i = int(math.floor(s))
            lower_threshold = i + t_f
            upper_threshold = i + t_r

            if s < lower_threshold:
                display = i
            elif s >= upper_threshold:
                display = i + 1
            else:
                if last_display == i + 1:
                    display = i + 1
                else:
                    display = i
        result.append(display)
        last_display = display
    return result

def main():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    
    t_f = float(input_data[0])
    t_r = float(input_data[1])
    speeds = list(map(float, input_data[2:]))

    result = smooth_speeds(t_f, t_r, speeds)
    for r in result:
        sys.stdout.write(str(r) + "\n")

if __name__ == "__main__":
    main()