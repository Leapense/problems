# 19076번: Competition - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19076)


<p>A wrestling competition will be held tomorrow. A total of $n$ players will take part in it. The $i$-th player's strength is $a_i$.</p>

<p>If there is a match between the $i$-th player and the $j$-th player, the result will depend solely on $|a_i - a_j|$. If $|a_i - a_j| &gt; K$, the player with the higher strength will win. Otherwise, each player will have a chance to win.</p>

<p>The competition rules are a little strange. For each fight, the referee will choose two players from all remaining players uniformly at random and hold a match between them. The loser will be eliminated. After $n - 1$ matches, the last remaining player will be the winner.</p>

<p>Given the numbers $n$ and $K$ and the array $a$, find how many players have a chance to win the competition.</p>



## 입력


<p>The first line of the input contains two integers $n$ and $K$ ($1 \leq n \leq 10^5$, $0 \leq K &lt; 10^9$).</p>

<p>The second line contains $n$ integers $a_i$ ($1 \leq a_i \leq 10^9$).</p>



## 출력


<p>Print a single line with a single integer: the number of players which have a chance to win the competition.</p>



## 소스코드

[소스코드 보기](Competition.cpp)