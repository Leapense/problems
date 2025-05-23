# 12504번: FreeCell Statistics (Large) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12504)


<p>I played&nbsp;<strong>D</strong>&nbsp;(<strong>D</strong>&nbsp;&gt; 0) games of FreeCell today. Each game of FreeCell ends in one of two ways -- I either win, or I lose. I've been playing for many years, and have so far played&nbsp;<strong>G</strong>games in total (obviously,&nbsp;<strong>G</strong>&nbsp;≥&nbsp;<strong>D</strong>).</p>

<p>At the end of the day, I look at the game statistics to see how well I have played. It turns out that I have won exactly&nbsp;<strong>P<sub>D</sub></strong>&nbsp;percent of the&nbsp;<strong>D</strong>&nbsp;games today, and exactly&nbsp;<strong>P<sub>G</sub></strong>&nbsp;percent of&nbsp;<strong>G</strong>total games I had ever played. Miraculously, there is no rounding necessary -- both percentages are exact! Unfortunately, I don't remember the exact number of games that I have played today (<strong>D</strong>), or the exact number of games that I have played in total (<strong>G</strong>). I do know that I could not have played more than&nbsp;<strong>N</strong>&nbsp;games today (<strong>D</strong>&nbsp;≤&nbsp;<strong>N</strong>).</p>

<p>Are the percentages displayed possible, or is the game statistics calculator broken?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;lines follow. Each line contains 3 integers --&nbsp;<strong>N</strong>,&nbsp;<strong>P<sub>D</sub></strong>&nbsp;and&nbsp;<strong>P<sub>G</sub></strong>.</p>

<h3>Limits</h3>

<ul>
<li>0 ≤&nbsp;<strong>P<sub>D</sub></strong>&nbsp;≤ 100;</li>
<li>0 ≤&nbsp;<strong>P<sub>G</sub></strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 2000;</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10<sup>15</sup>.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is either "Possible" or "Broken".</p>



## 소스코드

[소스코드 보기](FreeCell%20Statistics%20(Large).py)