import sys
import math

def main():
    cities = {}
    for line in sys.stdin:
        line = line.strip()
        if line == "#":
            break

        parts = line.split()
        name = parts[0]
        lat = float(parts[1])
        lon = float(parts[2])
        cities[name] = (math.radians(lat), math.radians(lon))

    for line in sys.stdin:
        line = line.strip()
        if line == "# #":
            break
        a, b = line.split()
        print(f"{a} - {b}")
        if a not in cities or b not in cities:
            print("Unknown")
        else:
            lat1, lon1 = cities[a]
            lat2, lon2 = cities[b]
            delta = abs(lon1 - lon2)
            inner = math.sin(lat1) * math.sin(lat2) + math.cos(lat1) * math.cos(lat2) * math.cos(delta)
            angle = math.acos(min(1, max(-1, inner)))
            distance = round(6378 * angle)
            print(f"{distance} km")
        print()

if __name__ == "__main__":
    main()