# 21269번: Edge Subsets - <img src="https://static.solved.ac/tier_small/26.svg" style="height:20px" /> Ruby V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21269)


<p>You are given integers $A,B$, and a simple undirected graph of $N$ vertices and $M$ edges. The vertices are numbered from $1$ through $N$, and the edges from $1$ through $M$. The edge $i$ connects the vertices $U_i$ and $V_i$. Here, it is guaranteed that $V_i-U_i=A$ or $V_i-U_i=B$.</p>

<p>Find the number of matchings of the graph, modulo $998244353$. Note that a matching of the graph is a subset of edges whose end-points are all distinct.</p>



## 입력


<p>The first line contains integers $N$ ($3 \leq N \leq 200$), $M$ ($1 \leq M \leq 400$), $A$, and $B$ ($1 \leq A &lt; B \leq N-1$).</p>

<p>The following $M$ lines describe the edges. The $i$-th of those lines contains integers $U_i$ and $V_i$ ($1 \leq U_i &lt; V_i \leq N$, $V_i-U_i=A$ or $V_i-U_i=B$). There are no self-loops or multi-edges.</p>



## 출력


<p>Print the answer.</p>



## 소스코드

[소스코드 보기](Edge%20Subsets.cpp)