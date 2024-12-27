# 12599번: Qualification Round (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12599)


<p>You've just advanced from the Qualification Round of Google Code Jam Africa 2010, and you want to know how many of your fellow contestants advanced with you. To give yourself a challenge, you've decided only to look at how many people solved each problem.</p>

<p>The Qualification Round consisted of&nbsp;<strong>P</strong>&nbsp;problems; the i<sup>th</sup>&nbsp;problem was fully solved by&nbsp;<strong>S<sub>i</sub></strong>contestants. Contestants had to solve&nbsp;<strong>C</strong>&nbsp;problems in order to advance to the next round. Your job is to figure out, using only that information, the maximum number of contestants who could have advanced.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>. T lines follow. Each will consist only of space-separated integers: first&nbsp;<strong>P</strong>, then&nbsp;<strong>C</strong>, then P integers&nbsp;<strong>S<sub>0</sub>...S<sub>P-1</sub></strong>.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤ T ≤ 100</li>
<li>1 ≤ C ≤ P</li>
<li>1 ≤ P ≤ 6</li>
<li>0 ≤ S<sub>i</sub>&nbsp;≤ 1000</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the maximum number of contestants who could have advanced (in other words, the maximum number of contestants who could have solved at least&nbsp;<strong>C</strong>problems).</p>



## 소스코드

[소스코드 보기](Qualification%20Round%20(Small).cpp)