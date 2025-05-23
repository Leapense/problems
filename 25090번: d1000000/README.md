# 25090번: d1000000 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25090)


<p>While the most typical type of dice have $6$ sides, each of which shows a different integer $1$ through $6$, there are many games that use other types. In particular, a $dk$ is a die with $k$ sides, each of which shows a different integer $1$ through $k$. A $d6$ is a typical die, a $d4$ has four sides, and a $d1000000$ has one million sides.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/71c9cbbf-a002-47f1-8afa-4843d4be1ca0/-/preview/"></p>

<p>In this problem, we start with a collection of $N$ dice. The $i$-th die is a $dS_i$, that is, it has $S_i$ sides showing integers $1$ through $S_i$. A straight of length $ℓ$ starting at $x$ is the list of integers $x,x+1,\dots ,x+(ℓ-1)$. We want to choose some of the dice (possibly all) and pick one number from each to form a straight. What is the longest straight we can form in this way?</p>



## 입력


<p>The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case is described in two lines. The first line of a test case contains a single integer $N$, the number of dice in the game. The second line contains $N$ integers $S_1,S_2, \dots ,S_N$, each representing the number of sides of a different die.</p>



## 출력


<p>For each test case, output one line containing <code>Case #x: y</code>, where $x$ is the test case number (starting from 1) and $y$ is the maximum number of input dice that can be put in a straight.</p>



## 소스코드

[소스코드 보기](d1000000.py)