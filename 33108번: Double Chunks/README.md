# 33108번: Double Chunks - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/33108)


<p>You have a chocolate bar consisting of $N$ chunks (numbered from $1$ to $N$). Chunk $i$ contains $A_i$ peanut bits. You can divide the chocolate bar into several pieces, with each piece consisting of one or more consecutive chunks. Each chunk can only be part of one piece. The total number of peanut bits in a piece is simply the sum of the peanut bits from each of its chunks.</p>

<p>A piece is considered a <em>double chunk</em> if and only if it consists of exactly two chunks. You are required to divide the chocolate bar into as many double chunks as possible, all having the same total number of peanut bits. Determine the maximum number of double chunks you can get while satisfying this requirement.</p>



## 입력


<p>The first line consists of an integer $N$ ($2 ≤ N ≤ 100\, 000$).</p>

<p>The second line consists of $N$ integers $A_i$ ($1 ≤ A_i ≤ 10^9$).</p>



## 출력


<p>Output a single integer representing the maximum number of double chunks you can get while satisfying the requirement.</p>



## 소스코드

[소스코드 보기](Double%20Chunks.py)