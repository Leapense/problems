def main():
    import sys

    inp = sys.stdin.read
    data = inp().splitlines()

    idx = 0
    n = int(data[idx]); idx += 1

    for case_num in range(1, n + 1):
        user_dirs = dict()
        all_fids = set()

        while data[idx] != "-1":
            parts = list(map(int, data[idx].split()))
            fid, uids = parts[0], parts[1:]
            all_fids.add(fid)
            for uid in uids:
                user_dirs.setdefault(uid, set()).add(fid)
            idx += 1

        idx += 1

        class_map = dict()
        for uid, dirs in user_dirs.items():
            sig = frozenset(dirs)
            class_map.setdefault(sig, set()).add(uid)

        result = []
        for members in class_map.values():
            if len(members) >= 2:
                smallest_uid = min(members)
                result.append((len(members), smallest_uid))

        result.sort(key=lambda x : (-x[0], x[1]))

        print(f"Case {case_num}")
        if not result:
            print("no prototypes found")
        else:
            for size, min_uid in result:
                print(f"{size} {min_uid}")

if __name__ == "__main__":
    main()