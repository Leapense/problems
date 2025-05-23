# 6753번: Chances of winning - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6753)


<p>You want to determine the chances that your favourite team will be the champion of a small tournament.</p>

<p>There are exactly four teams. At the end of the tournament, a total of six games will have been played with each team playing every other team exactly once. For each game, either one team wins (and the other loses), or the game ends in a tie. If the game does not end in a tie, the winning team is awarded three points and the losing team is awarded zero points. If the game ends in a tie, each team is awarded one point.</p>

<p>Your favourite team will only be the champion if it ends the tournament with strictly more total points than every other team (i.e., a tie for first place is not good enough for your favourite team).</p>

<p>The tournament is not over yet but you know the scores of every game that has already been played. You want to consider all possible ways points could be awarded in the remaining games that have not yet been played and determine in how many of these cases your favourite team will be the tournament champion.</p>



## 입력


<p>The first line of input will contain an integer T which is your favourite team (1 ≤ T ≤ 4). The second line will contain an integer G, the number of games already played (0 ≤ G ≤ 5). The next G lines will give the results of games that have already been played. Each of these lines will consist of four integers A, B, S<sub>A</sub>, S<sub>B</sub> separated by single spaces where 1 ≤ A &lt; B ≤ 4, and S<sub>A</sub>, S<sub>B</sub> ≥ 0 . This corresponds to a game between team A (which had score S<sub>A</sub>) and team B (which had score S<sub>B</sub>) where team A won if S<sub>A</sub> &gt; S<sub>B</sub>, team B won if S<sub>A</sub> &lt; S<sub>B</sub> and the game ended in a tie if S<sub>A</sub> = S<sub>B</sub>. The pairs A and B on the input lines are distinct, since no pair of teams plays twice.</p>



## 출력


<p>The output will consist of a single integer which is the number of times that team T is the champion over all possible awarding of points in the remaining games in the tournament.</p>



## 소스코드

[소스코드 보기](Main.java)