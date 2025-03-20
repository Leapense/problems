# 14766번: Bumper-To-Bumper Traffic - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14766)


<p>It’s the slow crawl of rush hour. At any point of time, each vehicle is either stopped or is moving at the extremely slow speed of 1 meter per second. Lately, vehicles come equipped with a simple “black box” that record all changes in a vehicle’s speed. In this problem, speeds change instantaneously.</p>

<p>The road is modelled as the real line (units in meters). So a car is identified with its position on the line. Also, cars are 4.4 meters long.</p>

<p>Given initial positions of two cars that are driving along the real line in the positive direction and a transcript of their speed changes, did these cars ever collide? While such a collision would be very slow speed (a “bumper tap”), any collision could result in erroneous readings from the black box in the future so the portions of the transcripts after a collision might not make sense.</p>



## 입력


<p>There is only one test case. The first line contains two integers 0 ≤ X<sub>1</sub>, X<sub>2</sub> ≤ 10<sup>6</sup> indicating the initial positions of the rears of the two vehicles in meters. You are guaranteed either X<sub>1</sub>+5 ≤ X<sub>2</sub> or X<sub>2</sub>+5 ≤ X<sub>1</sub>. Initially (at time 0), the two cars are stopped.</p>

<p>The second line begins with a number 0 ≤ N<sub>1</sub> ≤ 10<sup>5</sup> indicating the number of times the speed of the first car changed. The rest of the line contains N<sub>1</sub> integers 0 &lt; T<sub>1</sub> &lt; T<sub>2</sub> &lt; . . . &lt; T<sub>N<sub>1</sub></sub> ≤ 10<sup>6</sup> indicating the times (in seconds) the first vehicle changed speeds. So at time T<sub>1</sub> it begins driving at 1 m/s, at time T<sub>2</sub> it stops, at time T<sub>3</sub> it begins driving at 1 m/s, and so on.</p>

<p>The last line begins with a number 0 ≤ N<sub>2</sub> ≤ 10<sup>5</sup> and is followed by N2 integers 0 &lt; T'<sub>1</sub> &lt; T'<sub>2</sub> &lt; . . . &lt; T'<sub>N<sub>2</sub></sub> ≤ 10<sup>6</sup> that describe the times the second vehicle starts and stops.</p>



## 출력


<p>If the vehicles collide, output the message <code>bumper tap at time S</code> on a single line where S is the number of seconds from time 0 that the vehicles first collide, rounded up to the nearest second. If the vehicles do not collide, output the message <code>safe and sound</code> on a single line.</p>



## 소스코드

[소스코드 보기](Bumper-To-Bumper%20Traffic.cpp)