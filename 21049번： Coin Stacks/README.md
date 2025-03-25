# 21049번: Coin Stacks - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21049)


<p>A and B are playing a collaborative game that involves $n$ stacks of coins, numbered from $1$ to $n$. Every round of the game, they select a nonempty stack each, but they are not allowed to choose the same stack. They then remove a coin from both the two selected stacks and then the next round begins.</p>

<p>The players win the game if they manage to remove all the coins. Is it possible for them to win the game, and if it is, how should they play?</p>



## 입력


<p>The first line of input contains an integer $n$ ($2 \le n \le 50$), the number of coin stacks. Then follows a line containing $n$ nonnegative integers $a_1, a_2, \ldots, a_n$, where $a_i$ is the number of coins in the $i$'th stack. The total number of coins is at most $1\,000$.</p>



## 출력


<p>If the players can win the game, output a line containing "<code>yes</code>", followed by a description of the moves. &nbsp;Otherwise output a line containing "<code>no</code>". &nbsp;When describing the moves, output one move per line, each move being described by two distinct integers $a$ and $b$ (between $1$ and $n$) indicating that the players remove a coin from stacks $a$ and $b$. &nbsp;If there are several possible solutions, output any one of them.</p>



## 소스코드

[소스코드 보기](Coin%20Stacks.cpp)