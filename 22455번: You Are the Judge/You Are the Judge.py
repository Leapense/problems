def process_icpc_logs():
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")

    results = []
    idx = 0

    while True:
        T, P, R = map(int, data[idx].split())
        if T == 0 and P == 0 and R == 0:
            break

        idx += 1
        logs = data[idx:idx+R]
        idx += R

        teams = [
            {"id": t, "solved": 0, "penalty": 0, "attempts": {p: 0 for p in range(1, P + 1)}, "solved_problems": set()}
            for t in range(1, T + 1)
        ]

        for log in logs:
            tID, pID, time, message = log.split()
            tID, pID, time = int(tID), int(pID), int(time)
            team = teams[tID - 1]

            if message == "CORRECT":
                if pID not in team["solved_problems"]:
                    team["solved"] += 1
                    team["penalty"] += team["attempts"][pID] * 1200 + time
                    team["solved_problems"].add(pID)
            elif message == "WRONG":
                if pID not in team["solved_problems"]:
                    team["attempts"][pID] += 1

        teams.sort(key=lambda x: (-x["solved"], x["penalty"], x["id"]))
        results.append("\n".join(f"{team['id']} {team['solved']} {team['penalty']}" for team in teams))

    print("\n".join(results))

process_icpc_logs()