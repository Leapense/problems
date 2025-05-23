# 20626번: AiGo - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20626)


<p>Recently, AIs which play Go (a traditional board game) are well investigated. Your friend Hikaru is planning to develop a new awesome Go AI named Sai and promote it to company F or company G in the future. As a first step, Hikaru has decided to develop an AI for 1D-Go, a restricted version of the original Go.</p>

<p>In both of the original Go and 1D-Go, capturing stones is an important strategy. Hikaru asked you to implement one of the functions of capturing.</p>

<p>In 1D-Go, the game board consists of $L$ grids lie in a row. A state of 1D-go is described by a string $S$ of length $L$. The $i$-th character of $S$ describes the $i$-th grid as the following:</p>

<ul>
<li>When the $i$-th character of $S$ is '<code>B</code>', the $i$-th grid contains a stone which is colored black.</li>
<li>When the $i$-th character of $S$ is '<code>W</code>', the $i$-th grid contains a stone which is colored white.</li>
<li>When the $i$-th character of $S$ is '<code>.</code>', the $i$-th grid is empty.</li>
</ul>

<p>Maximal continuous stones of the same color are called a chain. When a chain is surrounded by stones with opponent's color, the chain will be captured.</p>

<p>More precisely, if $i$-th grid and $j$-th grids ($1&lt; i+1&lt;j \le L$) contain white stones and every grid of index $k$ ($i&lt;k&lt;j$) contains a black stone, these black stones will be captured, and vice versa about color.</p>

<p>Please note that some of the rules of 1D-Go are quite different from the original Go. Some of the intuition obtained from the original Go may curse cause some mistakes.</p>

<p>You are given a state of 1D-Go that next move will be played by the player with white stones. The player can put a white stone into one of the empty cells. However, the player can not make a chain of white stones which is surrounded by black stones even if it simultaneously makes some chains of black stones be surrounded. It is guaranteed that the given state has at least one grid where the player can put a white stone and there are no chains which are already surrounded.</p>

<p>Write a program that computes the maximum number of black stones which can be captured by the next move of the white stones player.</p>



## 입력


<p>First line of the input contains one integer $L$ ($1 \le L \le 100$) means the length of the game board and $S$ ($|S|=L$) is a string which describes the state of 1D-Go. The given state has at least one grid where the player can put a white stone and there are no chains which are already surrounded.</p>



## 출력


<p>Output the maximum number of stones which can be captured by the next move in a line.</p>



## 소스코드

[소스코드 보기](AiGo.cpp)