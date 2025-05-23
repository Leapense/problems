# 12639번: Center of Mass (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12639)


<p>You are studying a swarm of&nbsp;<strong>N</strong>&nbsp;fireflies. Each firefly is moving in a straight line at a constant speed. You are standing at the center of the universe, at position&nbsp;(0, 0, 0). Each firefly has the same mass, and you want to know how close the center of the swarm will get to your location (the origin).</p>

<p>You know the position and velocity of each firefly at t = 0, and are only interested in&nbsp;t ≥ 0. The fireflies have constant velocity, and may pass freely through all of space, including each other and you. Let M(t) be the location of the center of mass of the&nbsp;<strong>N</strong>&nbsp;fireflies at time t. Let d(t) be the distance between your position and M(t) at time t. Find the minimum value of d(t), d<sub>min</sub>, and the earliest time when d(t) = d<sub>min</sub>, t<sub>min</sub>.</p>



## 입력


<p>The first line of input contains a single integer&nbsp;<strong>T</strong>, the number of test cases. Each test case starts with a line that contains an integer&nbsp;<strong>N</strong>, the number of fireflies, followed by&nbsp;<strong>N</strong>&nbsp;lines of the form</p>

<pre>x y z vx vy vz</pre>

<p>Each of these lines describes one firefly: (x, y, z) is its initial position at time t = 0, and (vx, vy, vz) is its velocity.</p>

<p>Limits</p>

<ul>
<li>All the numbers in the input will be integers.</li>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100</li>
<li>The values of x, y, z, vx, vy and vz will be between -5000 and 5000, inclusive.</li>
<li>3 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10</li>
</ul>



## 출력


<p>For each test case, output</p>

<pre>Case #X: d<sub>min</sub> t<sub>min</sub></pre>

<p>where&nbsp;<strong>X</strong>&nbsp;is the test case number, starting from 1. Any answer with absolute or relative error of at most 10<sup>-5</sup>&nbsp;will be accepted.</p>



## 소스코드

[소스코드 보기](Center%20of%20Mass%20(Small).cpp)