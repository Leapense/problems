# 24064번: Intersections - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24064)


<p>You are given the following&nbsp;two functions.&nbsp;($\mathbb{N}_0$ denotes the set of non-negative integers.)</p>

<p>$$f(x)= \begin{cases} 0,&nbsp;&amp; \mbox{if } x &lt; 0 \\ x - 2k, &amp; \mbox{if } 2k \le x &lt; 2k+1 \, (k \in \mathbb{N}_0) \\ -x + 2(k+1)&nbsp;&amp; \mbox{if } 2k + 1 \le x &lt; 2k+2 \,&nbsp;(k \in \mathbb{N}_0) \end{cases}$$</p>

<p>$$g(x)&nbsp;= {x \over a}$$</p>

<p>How many intersections between the graphs of&nbsp;$y=f(x)$ and&nbsp;$y=g(x)$ exist on&nbsp;the XY-plane?</p>



## 입력


<p>The first and only line of the input contains a single integer $a$.</p>



## 출력


<p>Print the number of intersections between&nbsp;the graphs of $y = f(x)$ and $y = g(x)$.&nbsp;If there are infinitely many intersections, print <code>INF</code>.</p>



## 소스코드

[소스코드 보기](Intersections.py)