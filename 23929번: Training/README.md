# 23929번: Training - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23929)


<p>As the football coach at your local school, you have been tasked with picking a team of exactly&nbsp;<b>P</b>&nbsp;students to represent your school. There are&nbsp;<b>N</b>&nbsp;students for you to pick from. The i-th student has a&nbsp;<i>skill rating</i>&nbsp;<b>S<sub>i</sub></b>, which is a positive integer indicating how skilled they are.</p>

<p>You have decided that a team is&nbsp;<i>fair</i>&nbsp;if it has exactly&nbsp;<b>P</b>&nbsp;students on it and they all have the same skill rating. That way, everyone plays as a team. Initially, it might not be possible to pick a fair team, so you will give some of the students one-on-one coaching. It takes one hour of coaching to increase the skill rating of any student by 1.</p>

<p>The competition season is starting very soon (in fact, the first match has already started!), so you'd like to find the minimum number of hours of coaching you need to give before you are able to pick a fair team.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow. Each test case starts with a line containing the two integers&nbsp;<b>N</b>&nbsp;and&nbsp;<b>P</b>, the number of students and the number of students you need to pick, respectively. Then, another line follows containing&nbsp;<b>N</b>&nbsp;integers&nbsp;<b>S<sub>i</sub></b>; the i-th of these is the skill of the i-th student.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the minimum number of hours of coaching needed, before you can pick a fair team of&nbsp;<b>P</b>&nbsp;students.</p>



## 소스코드

[소스코드 보기](Training.py)