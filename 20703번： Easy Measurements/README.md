# 20703번: Easy Measurements - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20703)


<p>Edward was tasked to measure the pumping rate of two water pumps. To do so, he used the pumps to pump water into a water tank and checked how much water was pumped into the tank in a specific time.</p>

<p>He found out that the first pump pumps $a$ liters of water in $b$ seconds, and the second pump pumps $c$ liters of water in $d$ seconds. He also discovered that when both pumps are used at the same time, together they pump $b$ liters of water in $d$ seconds.</p>

<p>Unfortunately, Edward has spilled some water on his records, so now he can't recover the values $a$ and $c$. However, he remembers that these values were positive integers. Now he wonders how many ways are there to choose the values $a$ and $c$ that are consistent with his measurements.</p>



## 입력


<p>The first line contains an integer $n$ ($1\le n\le1000$) --- the number of test cases.</p>

<p>Each of the next $n$ lines contains two integers $b$ and $d$ ($1\le b,d\le10^9$).</p>



## 출력


<p>For each test case, output a single integer --- the number of ways to choose $a$ and $c$. Output each answer on a separate line.</p>



## 소스코드

[소스코드 보기](Easy%20Measurements.cpp)