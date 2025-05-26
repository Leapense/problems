import sys
from collections import defaultdict
from typing import List, Tuple

def max_events_in_one_day(events: List[Tuple[int, int]]) -> int:
    """
    주어진 날짜의 경기 리스트에서
    그리디로 최대 관람 개수를 반환한다.
    events: List of (start_time, end_time)
    """
    sorted_events = sorted(events, key=lambda x: x[1])
    count = 0
    last_end_time = -1

    for start_time, end_time in sorted_events:
        if start_time >= last_end_time:
            count += 1
            last_end_time = end_time

    return count

def main() -> None:
    input_data = sys.stdin.read().split()
    it = iter(input_data)

    t = int(next(it))
    output_lines = []

    for scenario in range(1, t + 1):
        m = int(next(it))
        events_by_day: defaultdict[int, List[Tuple[int, int]]] = defaultdict(list)

        for _ in range(m):
            day = int(next(it))
            start = int(next(it))
            end = int(next(it))
            events_by_day[day].append((start, end))
        
        total_count = 0
        for day, events in events_by_day.items():
            total_count += max_events_in_one_day(events)

        output_lines.append(f"Scenario #{scenario}:")
        output_lines.append(str(total_count))
        output_lines.append("")

    if output_lines and output_lines[-1] == "":
        output_lines.pop()

    sys.stdout.write("\n".join(output_lines))

if __name__ == "__main__":
    main()