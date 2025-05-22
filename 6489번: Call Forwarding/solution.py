#!/usr/bin/env python3
import sys

def main():
    reader = sys.stdin
    
    while True:
        header = reader.readline()
        if not header:
            return
        header = header.strip()
        if header:
            num_systems = int(header)
            break

    for system_index in range(1, num_systems + 1):
        forwards = {} # type: dict[str, list[tuple[int, int, str]]]
        while True:
            line = reader.readline()
            if not line:
                return
            parts = line.split()
            if not parts:
                continue
            src = parts[0]
            if src == "0000":
                break
            if len(parts) != 4:
                continue

            _, t0, dur, tgt = parts
            start = int(t0)
            end = start + int(dur)
            forwards.setdefault(src, []).append((start, end, tgt))

        print(f"SYSTEM {system_index}")
        while True:
            line = reader.readline()
            if not line:
                return
            parts = line.split()
            if not parts:
                continue
            time_str = parts[0]
            if time_str == "9000":
                break
            if len(parts) != 2:
                continue

            _, ext = parts
            call_time = int(time_str)
            final = resolve_call(ext, call_time, forwards)
            print(f"AT {time_str} CALL TO {ext} RINGS {final}")

def resolve_call(start_ext, call_time, forwards):
    seen = set()
    current = start_ext

    while True:
        if current in seen:
            return "9999"
        
        seen.add(current)

        rules = forwards.get(current)
        if not rules:
            return current
        
        next_ext = None
        for (st, ed, tgt) in rules:
            if st <= call_time <= ed:
                next_ext = tgt
                break

        if next_ext is None:
            return current
        
        current = next_ext

if __name__ == "__main__":
    main()