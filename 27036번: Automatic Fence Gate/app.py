#=====================================================================
#   27036번:    Automatic Fence Gate                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/27036  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

def parse_time(time_str):
    import re
    match = re.match(r'(\d{1,2}):(\d{2})(am|pm)', time_str.lower())
    if not match:
        raise ValueError(f"Invalid time format: {time_str}")

    hour, minute, period = match.groups()
    hour = int(hour)
    minute = int(minute)

    if period == 'am':
        if hour == 12:
            hour = 0
    elif period == 'pm':
        if hour != 12:
            hour += 12
    return hour * 60 + minute

def main():
    import sys
    N = int(sys.stdin.readline())
    instructions = []
    for idx in range(N):
        line = sys.stdin.readline().strip()
        if not line:
            continue
        time_part, h_i_str = line.split()
        t = parse_time(time_part)
        h_i = int(h_i_str)
        instructions.append((t, idx, h_i))

    instructions.sort()
    cumulative_sum = 0
    min_sum = 0

    for instr in instructions:
        _, _, h_i = instr
        cumulative_sum += h_i
        if cumulative_sum < min_sum:
            min_sum = cumulative_sum
    H0 = -min_sum

    current_H = H0
    last_time = 0
    total_closed = 0

    for instr in instructions:
        t_i, _, h_i = instr
        duration = t_i - last_time
        if current_H == 0:
            total_closed += duration
        current_H += h_i
        last_time = t_i
    duration = 1440 - last_time
    if current_H == 0:
        total_closed += duration
    print(total_closed)

if __name__ == '__main__':
    main()
        

