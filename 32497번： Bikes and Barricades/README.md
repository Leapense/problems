# 32497번: Bikes and Barricades - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32497)


<p>Scott wants to ride his bike along a straight road. But the road has some barricades! Scott will ride his bike up to the first barricade and stop.</p>

<p>Model Scott’s straight road as the positive $Y$ axis, with Scott starting at the origin. The barricades are line segments, specified by their endpoints. Determine how far Scott can ride, or if his path is completely unobstructed.</p>



## 입력


<p>The first line of input contains a single integer $n$ ($1≤n≤1\,000$), which is the number of barricades.</p>

<p>Each of the next 𝑛n lines contains four integers $x_1$, $y_1$, $x_2$ and $y_2$ ($-100≤x_1,y_1,x_2,y_2≤100$, $x_1 \ne 0$, $x_2 \ne 0$), representing a barricade that runs from $(x_1,y_1)$ to $(x_2,y_2)$. It is guaranteed that no barricade will run through the origin.</p>



## 출력


<p>Output a single real number, which is how far Scott can ride before he hits the closest barricade, or $-1.0$ if no barricades get in Scott’s way. This output will be considered correct if it is within an absolute or relative error of $10^{-2}$.</p>



## 소스코드

[소스코드 보기](Bikes%20and%20Barricades.py)