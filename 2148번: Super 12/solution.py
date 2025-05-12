#!/usr/bin/env python3
import sys

def solve():
    data = sys.stdin.read().strip().splitlines()
    idx = 0

    teams = []
    while idx < len(data) and data[idx] != '#':
        teams.append(data[idx].strip())
        idx += 1
    idx += 1

    n = len(teams)
    stats = {
        name: {
            "points": 0,
            "scored": 0,
            "conceded": 0,
            "tries_for": 0,
            "tries_against": 0
        }
        for name in teams
    }

    games = []

    while idx < len(data) and data[idx] != '#':
        parts = data[idx].split()
        home = parts[0]
        away = parts[1]
        hs, as_, ht, at = map(int, parts[2:])
        games.append((home, away, hs, as_, ht, at))
        idx += 1
    
    round_size = n // 2
    game_count = 0
    round_num = 1

    def print_round():
        nonlocal round_num
        sorted_teams = sorted(
            teams,
            key=lambda name: (
                -stats[name]["points"],
                -(stats[name]["scored"] - stats[name]["conceded"]),
                -stats[name]["tries_for"],
                name
            )
        )

        print(f"Round {round_num}")
        for name in sorted_teams:
            st = stats[name]
            line = (
                f"{name:<21}"
                f"{st['points']:>2}"
                f"{st['scored']:>4}"
                f"{st['conceded']:>4}"
                f"{st['tries_for']:>3}"
                f"{st['tries_against']:>3}"
            )
            print(line)

        round_num += 1


    for home, away, hs, as_, ht, at in games:
        stats[home]["scored"] += hs
        stats[home]["conceded"] += as_
        stats[away]["scored"] += as_
        stats[away]["conceded"] += hs
        stats[home]["tries_for"] += ht
        stats[home]["tries_against"] += at
        stats[away]["tries_for"] += at
        stats[away]["tries_against"] += ht

        if hs > as_:
            stats[home]["points"] += 4
        elif hs < as_:
            stats[away]["points"] += 4
        else:
            stats[home]["points"] += 2
            stats[away]["points"] += 2

        if ht >= 4:
            stats[home]["points"] += 1
        if at >= 4:
            stats[away]["points"] += 1

        if hs < as_ and (as_ - hs) < 8:
            stats[home]["points"] += 1
        if as_ < hs and (hs - as_) < 8:
            stats[away]["points"] += 1
        
        game_count += 1
        if game_count == round_size:
            print_round()
            if games.index((home, away, hs, as_, ht, at)) != len(games) - 1:
                print()
            game_count = 0

if __name__ == "__main__":
    solve()