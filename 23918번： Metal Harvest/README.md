# 23918번: Metal Harvest - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23918)


<p>You are in charge of deploying robots to harvest Kickium from a nearby asteroid. Robots are not designed to work as a team, so only one robot can harvest at any point of time. A single robot can be deployed for up to&nbsp;<b>K</b>&nbsp;units of time in a row before it returns for calibration, regardless of how much time it spends on harvesting during that period. Harvesting can only be done during specific time intervals. These time intervals do not overlap. Given&nbsp;<b>K</b>&nbsp;and the time intervals in which harvesting is allowed, what is the minimum number of robot deployments required to harvest at all possible times?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow.</p>

<p>The first line of each test case gives two space separated integers&nbsp;<b>N</b>&nbsp;and&nbsp;<b>K</b>: the number of time intervals in which harvesting is allowed, and the maximum duration a robot can be deployed for before returning for calibration.</p>

<p>The next&nbsp;<b>N</b>&nbsp;lines contain a pair of space separated integers&nbsp;<b>S<sub>i</sub></b>&nbsp;and&nbsp;<b>E<sub>i</sub></b>: the start time and the end time of the i-th interval respectively. Please note that intervals don't include the time unit starting at the moment&nbsp;<b>E<sub>i</sub></b>, so for example an interval with (<b>S<sub>i</sub></b>&nbsp;= 2;&nbsp;<b>E<sub>i</sub></b>&nbsp;= 5) has duration of 3 time units.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the number of times robot deployment is needed so that for each interval there is one robot harvesting at that time.</p>



## 소스코드

[소스코드 보기](Metal%20Harvest.py)