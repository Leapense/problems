import math

def time_to_minutes(time_str):
    parts = time_str.split(':')
    hours = int(parts[0])
    minutes = int(parts[1])
    return hours * 60 + minutes

def minutes_to_time_str(minutes):
    hours = minutes // 60
    mins = minutes % 60
    return "{:02d}:{:02d}".format(hours, mins)

def solve():
    n = int(input())
    zagreb_graz_trips = []
    graz_wroclaw_trips = []
    for _ in range(n):
        line = input().split()
        route_cities = line[0].split('-')
        departure_city = route_cities[0]
        arrival_city = route_cities[1]
        time_range = line[1].split('--')
        departure_time_str = time_range[0]
        arrival_time_str = time_range[1]
        departure_time_minutes = time_to_minutes(departure_time_str)
        arrival_time_minutes = time_to_minutes(arrival_time_str)
        if departure_city == "Zagreb" and arrival_city == "Graz":
            zagreb_graz_trips.append({'departure': departure_time_minutes, 'arrival': arrival_time_minutes})
        elif departure_city == "Graz" and arrival_city == "Wroclaw":
            graz_wroclaw_trips.append({'departure': departure_time_minutes, 'arrival': arrival_time_minutes})
            
    min_travel_time = float('inf')
    found_route = False
    
    for zg_trip in zagreb_graz_trips:
        for gw_trip in graz_wroclaw_trips:
            arrival_graz_time = zg_trip['arrival']
            departure_graz_time = gw_trip['departure']
            departure_zagreb_time = zg_trip['departure']
            arrival_wroclaw_time = gw_trip['arrival']
            
            if arrival_graz_time < departure_graz_time:
                travel_time = arrival_wroclaw_time - departure_zagreb_time + 1
            else:
                travel_time = 1440 + arrival_wroclaw_time - departure_zagreb_time + 1
                
            min_travel_time = min(min_travel_time, travel_time)
            found_route = True
            
    if not found_route or min_travel_time == float('inf'):
        print("NEMOGUCE")
    else:
        print(minutes_to_time_str(min_travel_time))

if __name__ == '__main__':
    solve()