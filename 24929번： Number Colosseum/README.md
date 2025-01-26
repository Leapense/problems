# 24929번: Number Colosseum - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24929)


<p>Welcome to the Number Colosseum, where two teams of integers are preparing to battle! On the left side of the number line we have team&nbsp;<i>Negatives</i>&nbsp;while on the right side we have team&nbsp;<i>Positives</i>. Every integer fighting in the colosseum is on one of these two teams.</p>

<p>At the start of the battle, the contestants line up outside the colosseum. One by one, the contestants enter the colosseum and follow these rules:</p>

<ul>
<li>If there are no contestants from the other team, this contestant will wait and become the most recent contestant to have entered the colosseum.</li>
<li>If at least one contestant of the opposing team is in the colosseum, this contestant will fight the contestant on the opposing team who has most recently entered the colosseum. The winner of a fight between a negative integer and positive integer is the one with the highest absolute value. After a fight occurs, the value of the winner becomes the sum of two fighting integers while the loser leaves. Note that if the two integers have the same absolute value, they both lose and both leave. If there is a winner, they will continue fighting as long as there are more opposing contestants. Otherwise, they will wait.</li>
</ul>

<p>After all of the integers have entered the colosseum, only one team may be declared the winners of the Number Colosseum! Given the lineup of contestants for the upcoming battle, write a program to determine which team will triumph as well as the state of the colosseum after all fights have occurred.</p>



## 입력


<p>The first line contains a single integer $N$ ($1≤N≤5⋅10^5$), which is the number of contestants who will enter the colosseum. The second line contains the lineup of contestants. This will contain&nbsp;$N$&nbsp;space-separated integers&nbsp;$x_1,x_2, \dots ,x_N$&nbsp;($1≤|x_i|≤10^6$&nbsp;for each&nbsp;$1≤i≤N$), the value of the&nbsp;$i$th contestant entering the colosseum.</p>



## 출력


<p>Display the winning team with either&nbsp;<code>Positives win!</code>&nbsp;or&nbsp;<code>Negatives win!</code>. On the following line display the list of integers remaining in the colosseum after all fighting has finished. Display these integers in the order of arrival into the colosseum.</p>

<p>If neither team wins, display&nbsp;<code>Tie!</code>&nbsp;instead.</p>



## 소스코드

[소스코드 보기](Number%20Colosseum.py)