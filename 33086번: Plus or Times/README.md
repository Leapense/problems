# 33086번: Plus or Times - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/33086)


<p>Adrian is playing a game. When the game starts, Adrian will be given $P$ points as his initial points. The game consists of $N$ rounds, numbered from $1$ to $N$. During round $i$, Adrian has two options. Each option can be one of the following types:</p>

<ul>
<li><code>+</code> $c$ ($-1000 ≤ c ≤ 1000$) which will add his current points by $c$, or</li>
<li><code>x</code> $c$ ($-2 ≤ c ≤ 2$) which will multiply his current points by $c$.</li>
</ul>

<p>Adrian wants to maximize his points at the end of the game. Help Adrian to determine the maximum points he can achieve after completing all $N$ rounds!</p>



## 입력


<p>Input begins with two integers $N$ $P$ ($1 ≤ N ≤ 50$; $-1000 ≤ P ≤ 1000$) representing the number of rounds and the initial points during the game, respectively. Each of the next $N$ lines contains the two options in each round separated by a space. Each option is given in the format $T$ $c$ ($T ∈ \{$<code>+</code>, <code>x</code>$\}$; $-1000 ≤ c ≤ 1000$ if $T = $<code>+</code>, or $-2 ≤ c ≤ 2$ if $T = $<code>x</code>).</p>



## 출력


<p>Output an integer in a single line representing the maximum points Adrian can achieve at the end of the game.</p>



## 소스코드

[소스코드 보기](Plus%20or%20Times.py)