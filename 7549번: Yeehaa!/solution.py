import sys
import math

def compute_r(R: float, n: int) -> float:
    """
    반지름 R인 큰 원 내부에 작은 원 n개가
    서로 맞닿고 경계에 접하도록 할 때,
    작은 원 반지름 r을 계산한다.
    """
    angle = math.pi / n
    sin_val = math.sin(angle)
    return R * sin_val / (1.0 + sin_val)

def main():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    idx = 1

    for i in range(1, t + 1):
        R = float(data[idx])
        n = int(data[idx + 1])
        idx += 2

        r = compute_r(R, n)
        print(f"Scenario #{i}:")
        print(f"{r:.3f}\n")

if __name__ == "__main__":
    main()