import sys
from datetime import date

for line in sys.stdin:
    s = line.strip()
    if s == 'end':
        break
    gender = 'boy'
    valid = True
    if s.count('/') != 1:
        valid = False
    else:
        p1, p2 = s.split('/')
        if len(p1) != 6 or not p1.isdigit() or len(p2) not in (3, 4) or not p2.isdigit():
            valid = False
        else:
            yy = int(p1[0:2])
            mm = int(p1[2:4])
            dd = int(p1[4:6])
            if mm > 50:
                mm -= 50
                gender = 'girl'
            year = 2000 + yy if yy <= 9 else 1900 + yy
            try:
                id_date = date(year, mm, dd)
            except ValueError:
                valid = False
            else:
                if not (1920 <= year <= 2009):
                    valid = False
                else:
                    cutoff = date(1954, 1, 1)
                    if id_date < cutoff:
                        if len(p2) != 3:
                            valid = False
                    else:
                        if len(p2) != 4 or int(p1 + p2) % 11 != 0:
                            valid = False
    print(gender if valid else 'invalid')
