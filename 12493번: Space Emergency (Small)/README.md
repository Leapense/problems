# 12493번: Space Emergency (Small) - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12493)


<p>There's an emergency—in space! You need to send your fleet's flagship as quickly as possible from star 0 to star&nbsp;<strong>N</strong>, traveling through the other stars in increasing numerical order along the way (0→1→...→<strong>N</strong>). Your flagship normally travels at a speed of 0.5 parsecs per hour.</p>

<p>In addition to sending your flagship, you can order your engineers to build up to&nbsp;<strong>L</strong>&nbsp;speed boosters at different stars. Building a speed booster takes&nbsp;<strong>t</strong>&nbsp;hours, and all&nbsp;<strong>L</strong>&nbsp;speed boosters can be built in parallel. While your flagship travels from a star with a completed speed booster to the next star, its speed is 1 parsec per hour.</p>

<p>If a speed booster is completed at a star while your flagship is traveling from that star to the next one, your flagship will start moving faster as soon as the speed booster is completed.</p>

<p>How many hours does it take your flagship to get to star&nbsp;<strong>N</strong>&nbsp;if you build speed boosters to make it arrive as soon as possible?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;lines follow. Each contains integers,&nbsp;<strong>L</strong>,&nbsp;<strong>t</strong>,&nbsp;<strong>N</strong>&nbsp;and&nbsp;<strong>C</strong>, followed by&nbsp;<strong>C</strong>&nbsp;integers&nbsp;<strong>a<sub>i</sub></strong>, all separated by spaces.&nbsp;&nbsp;<strong>a<sub>i</sub></strong>&nbsp;is the number of parsecs between star&nbsp;<strong>k*C</strong>+i and star&nbsp;<strong>k*C</strong>+i+1, for all integer values of&nbsp;<strong>k</strong>.</p>

<p>For example, with&nbsp;<strong>N</strong>=8,&nbsp;<strong>C</strong>=3,&nbsp;<strong>a<sub>0</sub></strong>=3,&nbsp;<strong>a<sub>1</sub></strong>=5 and&nbsp;<strong>a<sub>2</sub></strong>=4, the distances between stars are [3, 5, 4, 3, 5, 4, 3, 5].</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>C</strong>&nbsp;≤ 1000.</li>
<li><strong>C</strong>&nbsp;≤&nbsp;<strong>N</strong>.</li>
<li>1 ≤&nbsp;<strong>a<sub>i</sub></strong>&nbsp;≤ 10<sup>4</sup>.</li>
<li>0 ≤&nbsp;<strong>t</strong>&nbsp;≤ 10<sup>11</sup>.</li>
<li><strong>t</strong>&nbsp;is even.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 1000.</li>
<li>0 ≤&nbsp;<strong>L</strong>&nbsp;≤ 2.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is a single integer: the number of hours it takes to reach star&nbsp;<strong>N</strong>. The answer is guaranteed to always be an integer.</p>



## 소스코드

[소스코드 보기](Space%20Emergency%20(Small).cpp)