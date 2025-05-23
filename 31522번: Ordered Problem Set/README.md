# 31522번: Ordered Problem Set - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31522)


<p>You are running a programming contest that features $n$ problems of distinct difficulties. You wish to announce ahead of time that the problems are ordered in such a way that, if the problems are divided into $k$ sections numbered $1$ through $k$, each with exactly $\frac{n}{k}$ problems, and problem $p$ is assigned to section $\left \lceil \frac{kp}{n} \right \rceil$, then for every pair of sections $i$ and $j$ with $i &lt; j$, every problem in section $i$ is easier than every problem in section $j$. Note that $k$ must be greater than $1$ and be a factor of $n$.</p>

<p>However, you have just sent your problems to the printer so the order cannot be changed. For what values of $k$ would this claim be true?</p>



## 입력


<p>The first line of input contains a single integer $n$ ($2 \le n \le 50$), which is the number of problems.</p>

<p>Each of the next $n$ lines contains a single integer $d$ ($1 \le d \le n$). These are the difficulties for the problems in the order that they appear in the problem set. The difficulties are distinct. The problem with difficulty $1$ is the easiest problem and the problem with difficulty $n$ is the hardest problem.</p>



## 출력


<p>Output a list of integers, one per line. The integers are all valid values of $k$ in increasing order. If no such values exist, output $-1$.</p>



## 소스코드

[소스코드 보기](Ordered%20Problem%20Set.cpp)