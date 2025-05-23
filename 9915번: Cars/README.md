# 9915번: Cars - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9915)


<p>On a straight single-lane road, there are n cars parked with a space of d meters wide separating every two adjacent cars. &nbsp;The cars will start to move successively in the same direction as follows.</p>

<p>At the beginning, the first car moves at a speed of v meters per second, while the other cars are standing still. &nbsp;After every 5 seconds from the beginning, every car checks the distance to the car in front or behind, and adapts its speed, if necessary.</p>

<p>The first car adapts as follows. &nbsp;If there is less than 80 meters space to the car behind it, it immediately increases its speed by 5 meters per second; if there is more than 100 meters space to the car behind it, it immediately decreases its speed by 5 meters per second; and otherwise it keeps its speed.</p>

<p>All the other cars adapt as follows. &nbsp;If there is less than 80 meters space to the car in front, it immediately decreases its speed by 5 meters per second; if there is more than 100 meters space to the car in front, it immediately increases its speed by 5 meters per second; and otherwise it keeps its speed.</p>

<p>Against the laws of physics, any change of speed takes immediate effect. &nbsp;If a car stands still and needs to decrease speed, it will remain standing still; the cars never go backwards. &nbsp;A collision occurs, if the space between two cars becomes 0 or less.</p>

<p>The goal is to find out, if a collision has occurred after t 5-second-intervals, and if not, how far the first car will have traveled.</p>

<p>Note that the length of the cars is irrelevant.</p>



## 입력


<p>The input consists of a line containing the four integers n, v, d, and t in this order, and 1 ≤ n, v, d, t ≤ 1000.</p>



## 출력


<p>The output contains the number of meters traveled by the first car if there is no collision. &nbsp;If there is a collision, the output file should contain -1.</p>



## 소스코드

[소스코드 보기](Cars.cpp)