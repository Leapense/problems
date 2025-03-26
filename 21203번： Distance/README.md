# 21203번: Distance - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21203)


<p>The City of Manhattan is organized as a grid of streets and avenues, with streets running in the North-South direction and avenues running in the East-West direction. &nbsp;Streets are numbered from East to West starting from 1, and avenues are numbered from North to South starting from 1. &nbsp;Each intersection is labelled by the street and avenue number $(s, a)$. &nbsp;The distance between two intersections $(s_1, a_1)$ and $(s_2, a_2)$ is $|s_1-s_2| + |a_1-a_2|$.</p>

<p>Your company operates several food trucks at different intersections in Manhattan and you want to have them spread out so they do not compete with each other. &nbsp;To estimate how spread out they are, you have decided to compute the total distance between every distinct pair of your food trucks. &nbsp;A small total distance would mean that on average, a pair of food truck is too close together.</p>

<p>What is the total distance between every distinct pair of food trucks?</p>



## 입력


<p>The first line of input contains an integer $N$ ($2 \leq N \leq 200\,000$), which is the number of food trucks.</p>

<p>The next $n$ lines describe the food trucks' locations. Each of these lines contains two integers $s$ ($1 \leq s \leq 1\,000\,000$), which is the street number of this food truck, and $a$ ($1 \leq a \leq 1\,000\,000$), which is the avenue number of this food truck.</p>



## 출력


<p>Display the total distance between every distinct pair of food trucks.</p>



## 소스코드

[소스코드 보기](Main.java)