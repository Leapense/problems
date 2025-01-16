# 18979번: Triangle Partition - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18979)


<p>Chiaki has $3n$ points $p_1,p_2,\dots,p_{3n}$. It is guaranteed that no three points are collinear.</p>

<p>Chiaki would like to construct $n$ disjoint triangles where each vertex comes from the $3n$ points.</p>



## 입력


<p>There are multiple test cases. The first line of input contains an integer $T$, indicating the number of test cases. For each test case:</p>

<p>The first line contains an integer $n$ ($1 \le n \le 1000$) -- the number of triangle to construct.</p>

<p>Each of the next $3n$ lines contains two integers $x_i$ and $y_i$ ($-10^9 \le x_i, y_i \le 10^9$).</p>

<p>It is guaranteed that the sum of all $n$ does not exceed $10^4$.</p>



## 출력


<p>For each test case, output $n$ lines contain three integers $a_i,b_i,c_i$ ($1 \le a_i,b_i,c_i \le 3n$) each denoting the indices of points the $i$-th triangle use. If there are multiple solutions, you can output any of them.</p>



## 소스코드

[소스코드 보기](Triangle%20Partition.cpp)