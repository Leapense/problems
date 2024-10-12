# 23274번: Joint Jog Jam - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23274)


<p>Like so many good stories, this one begins with a claim that Kari is a faster runner than Ola, who of course challenges Kari to a run-down.</p>

<p>Dubbed (rather ironically) Non-Competitive Pace Challenge,</p>

<p>they want to see who can run the furthest in a certain amount of time $t$. &nbsp;Clearly they both choose to run in straight lines with constant speed.</p>

<p>Kari wrote an app to make sure that Ola does not cheat, but the app requires that their phones constantly communicate over Bluetooth.</p>

<p>After their run, Kari needs to ensure that they were never too far apart from each other at any time during the run. &nbsp;Write a program that computes the maximum distance between Kari and Ola at any point during the run.</p>



## 입력


<p>The input consists of a single line containing eight integers describing four points:</p>

<ul>
<li>the starting position of Kari,</li>
<li>the starting position of Ola,</li>
<li>the ending position of Kari, and</li>
<li>the ending position of Ola,</li>
</ul>

<p>in that order. &nbsp;Each point is given by two integers $x$ and $y$ ($0 \le x, y \le 10^4$), the coordinates of the point.</p>



## 출력


<p>Output the maximum distance between Kari and Ola during their run, with an absolute or relative error of at most $10^{-6}$.</p>



## 소스코드

[소스코드 보기](Joint%20Jog%20Jam.py)