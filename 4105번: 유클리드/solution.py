import sys

def cross(ax: float, ay: float, bx: float, by: float) -> float:
    """2-D cross product (ax,ay) × (bx,by)."""
    return ax * by - ay * bx


def solve() -> None:
    data = list(map(float, sys.stdin.buffer.read().split()))
    out_lines = []

    for i in range(0, len(data), 12):
        block = data[i:i + 12]
        if len(block) < 12:
            break
        if all(abs(v) < 1e-9 for v in block):
            break        # terminating line

        Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, Ex, Ey, Fx, Fy = block

        # vectors
        ABx, ABy = Bx - Ax, By - Ay
        ACx, ACy = Cx - Ax, Cy - Ay

        den = abs(cross(ABx, ABy, ACx, ACy))          # |cross(AB, AC)|
        # guaranteed non-zero by the statement (C not on AB)

        EDx, EDy = Ex - Dx, Ey - Dy
        FDx, FDy = Fx - Dx, Fy - Dy
        numer = abs(cross(EDx, EDy, FDx, FDy))        # |cross(E-D, F-D)|

        t = numer / (2.0 * den)                       # <<< fixed line

        # coordinates of H and G
        Hx, Hy = Ax + t * ACx, Ay + t * ACy
        Gx, Gy = Bx + t * ACx, By + t * ACy

        out_lines.append(f"{Gx:.3f} {Gy:.3f} {Hx:.3f} {Hy:.3f}")

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    solve()