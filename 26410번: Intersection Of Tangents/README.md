# 26410번: Intersection Of Tangents - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26410)


<p>In this problem polygons are assumed to have no self-touchings or self-intersections.</p>

<p>A <strong>tangent</strong> to a polygon is a straight <strong>line</strong> that contains at least one point on the boundary of the polygon, and none of its interior points.</p>

<p>You are given a polygon with integer vertex coordinates. The polygon is not necessarily convex. Find a point with integer coordinates such that there exist two tangents to this polygon which both pass through this point and intersect at 90$^{\circ}$. It is guaranteed that at least one solution exists. If there are multiple solutions, output any of them.</p>



## 입력


<p>The first line of input contains a single integer $n$ ($3 \leq n \leq 1000$) --- the number of vertices in the polygon.</p>

<p>$n$ lines follow describing the vertices of the polygon. $i$-th of them contains two integers $x_i$ and $y_i$ ($-10^8 \leq x_i, y_i \leq 10^8$) --- the coordinates of $i$-th vertex. The vertices are given in counter-clockwise order.</p>

<p>The polygon has no self-touchings or self-intersections. There are no three consecutive points which lie on the same line.</p>

<p>It is guaranteed that an answer exists.</p>



## 출력


<p>Output two integers $x$ and $y$ ($-10^9 \leq x, y \leq 10^9$) --- the coordinates of the point you found.</p>



## 소스코드

[소스코드 보기](Intersection%20Of%20Tangents.cpp)