# 23914번: High Buildings - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23914)


<p>In an unspecified country, Google has an office campus consisting of&nbsp;<b>N</b>&nbsp;office buildings in a line, numbered from 1 to&nbsp;<b>N</b>&nbsp;from left to right. When represented in meters, the height of each building is an integer between 1 to&nbsp;<b>N</b>, inclusive.</p>

<p>Andre and Sule are two Google employees working in this campus. On their lunch break, they wanted to see the skyline of the campus they are working in. Therefore, Andre went to the leftmost point of the campus (to the left of building 1), looking towards the rightmost point of the campus (to the right of building&nbsp;<b>N</b>). Similarly, Sule went to the rightmost point of the campus, looking towards the leftmost point of the campus.</p>

<p>To Andre, a building x is visible if and only if there is no building to the left of building x that is strictly higher than building x. Similarly, to Sule, a building x is visible if and only if there is no building to the right of building x that is strictly higher than building x.</p>

<p>Andre learned that there are&nbsp;<b>A</b>&nbsp;buildings that are visible to him, while Sule learned that there are&nbsp;<b>B</b>&nbsp;buildings that are visible to him. After they regrouped and exchanged information, they also learned that there are&nbsp;<b>C</b>&nbsp;buildings that are visible to both of them.</p>

<p>They are wondering about the height of each building. They are giving you the value of&nbsp;<b>N</b>,&nbsp;<b>A</b>,&nbsp;<b>B</b>, and&nbsp;<b>C</b>&nbsp;for your information. As their friend, you would like to construct a possible height for each building such that the information learned on the previous paragraph is correct, or indicate that there is no possible height construction that matches the information learned (thus at least one of them must have been mistaken).</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow. Each consists of a single line with four integers&nbsp;<b>N</b>,&nbsp;<b>A</b>,&nbsp;<b>B</b>, and&nbsp;<b>C</b>: the information given by Andre and Sule.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is&nbsp;<code>IMPOSSIBLE</code>&nbsp;if there is no possible height for each building according to the above information, or&nbsp;<b>N</b>&nbsp;space-separated integers otherwise. The i-th integer in&nbsp;<code>y</code>&nbsp;must be the height of the i-th building (in meters) between 1 to&nbsp;<b>N</b>.</p>



## 소스코드

[소스코드 보기](High%20Buildings.py)