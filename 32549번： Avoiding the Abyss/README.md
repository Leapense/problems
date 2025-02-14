# 32549번: Avoiding the Abyss - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32549)


<p>You are standing on a point with integer coordinates $(x_s, y_s)$. You want to walk to the point with integer coordinates $(x_t, y_t)$. To do this, you can walk along a sequence of line segments. But there is a swimming pool in your way. The swimming pool is an axis aligned rectangle whose lower left corner is on the point $(x_l, y_l)$ and the upper right corner is on the point $(x_r, y_r)$. You cannot ever cross the swimming pool, not even on the border. However, it is dark and you do not know the coordinates $(x_l, y_l)$ and $(x_r, y_r)$. Instead, you threw a rock into the pool which revealed that the point $(x_p, y_p)$ is in the pool (or on the boundary).</p>

<p>Find a way to walk from the start to the end point along a sequence of line segments, so that you never cross the swimming pool.</p>



## 입력


<p>The first line contains two integers $x_s$ and $y_s$ ($-10^4 \leq x_s, y_s \leq 10^4$).</p>

<p>The second line contains two integers $x_t$ and $y_t$ ($-10^4 \leq x_t, y_t \leq 10^4$).</p>

<p>The third line contains two integers $x_p$ and $y_p$ ($-10^4 \leq x_p, y_p \leq 10^4$).</p>

<p>The problem is not adaptive, i.e. for every test case there exist four integers $x_l, y_l, x_r, y_r$ ($-10^4 \leq x_l &lt; x_r \leq 10^4$, $-10^4 \leq y_l &lt; y_r \leq 10^4$) that constitute a swimming pool. The start and end points are always strictly outside the swimming pool, and the point $(x_p,y_p)$ is inside (or on the border). The start and end points are always distinct.</p>



## 출력


<p>First, print one integer $N$ ($0 \leq N \leq 10$), the number of points in between the start and end point that you want to visit. Then, print $N$ lines, the $i$th containing two integers $x_i, y_i$. These coordinates must satisfy $-10^9 \leq x_i, y_i \leq 10^9$. Note that these are not the same bounds than on the other coordinates.</p>

<p>This means that you will walk along straight line segments between $(x_s, y_s), (x_1, y_1), \dots, (x_N, y_N), (x_t, y_t)$ such that none of the line segments touch the swimming pool. It can be proven that a solution always exists.</p>



## 소스코드

[소스코드 보기](Main.java)