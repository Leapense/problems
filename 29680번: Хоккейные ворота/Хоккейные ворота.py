import math

H,W,w1,w2 = map(float,input().split())
delta_w = w1-w2
back_area = W*math.hypot(H,delta_w)
side_area = H * (w1+w2)
top_area = W*w1
total_area = back_area+side_area+top_area

print(f"{total_area:.5f}")