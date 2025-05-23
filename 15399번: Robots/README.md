# 15399번: Robots - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15399)


<p>You’re the leading designer of a complex robot, that will explore human unreachable locations. Your job is to design a robot that will go as far as possible. To do this, you have n available energy sources. The i th source is capable of accelerating the robot by a rate of ai (m/s<sup>2</sup>) and can do this for a total of s<sub>i</sub> seconds. The robot is initially at rest (its initial velocity is zero). You have to decide the order in which to use the sources in order to maximize the total distance traveled by the robot. You will use one source until s<sub>i</sub> seconds have elapsed, then immediately switch to another unused source (the switch is instantaneous). Each source can be used only once.</p>

<p>Given the accelerations and durations of each source, write an efficient program to determine the optimal order of the sources, in order to maximize the total distance traveled. Your program must compute the difference between the traveled distance in the optimal case and in the default case (the order given by the input data).</p>

<p>Physics background: if the velocity is v before you start using a source whose acceleration is a then, after t seconds, the robot has traveled a total vt+1/2at<sup>2</sup> meters, and the final velocity will be v' = v+at.</p>



## 입력


<p>The input file starts with the number n (1 ≤ n ≤ 10<sup>4</sup>) of sources. Starting from a different line follows the n space-separated acceleration and duration for each source (positive integer numbers).</p>



## 출력


<p>The output file contains the computed difference between the traveled distance in the optimal case and in the default case (the order given by the input data), with one decimal.</p>



## 소스코드

[소스코드 보기](Robots.cpp)