# 26461번: Stop & Go - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26461)


<p>Mr. Drive, a.k.a. Mr. D, is famous for his thorough safe driving. Not only he always drives a car at an exact legal speed, but also he immediately stops a car if a traffic light turns red from green when he just enters a crossing, and he immediately starts a car at an exact legal speed when a traffic light just turns green from red.</p>

<p>Mr. D's next driving course is a simple straight road with length $L$ and the legal speed limit $1$ per second. Mr.D will start his drive at time $0$. The road has $N$ traffic lights numbered $1$ through $N$. The traffic light $i$ is at a distance of $x_i$ from the start point. At time $0$, all the $N$ traffic lights are green. The $i$-th traffic light turns red from green after $g_i$ seconds, then turns green from red after $r_i$, and then turns red from green after $g_i$ seconds, then turns green from red after $r_i$, and so on.</p>

<p>In this situation, Mr. D will start from the start point and run a car at speed $1$ per second. If the $i$-th traffic light is green or just turns green from red (but not just turns red from green) when Mr. D reaches $x_i$, Mr. D won't stop and go through the crossing at speed $1$ per second. If the $i$-th traffic light is red or just turns red from green (but not just turns green from red) when Mr. D reaches $x_i$, Mr. D will stop until the $i$-th traffic light turns green.</p>

<p>Your task is to compute the time in seconds when Mr. D reaches point $L$, for given $N$ traffic lights.</p>



## 입력


<p>The first line of the input consists of two integers, the number $N$ ($1 ≤ N ≤ 100\,000$) of traffic lights on the road and the length $L$ ($1 ≤ L ≤ 10^9$) of the road. The $i$-th of the following $N$ lines has three integers $x_i$, $g_i$, and $r_i$, where $x_i$ ($1 ≤ x_i &lt; L$) is the position of the $i$-th traffic light from the start point, $g_i$ ($1 ≤ g_i ≤ 10^9$) is the duration the $i$-th traffic light is green, and $r_i$ ($1 ≤ r_i ≤ 10^9$) is the duration the $i$-th traffic light is red. You can assume all the positions of the traffic lights are different. In other words, $x_i \ne x_j$ holds for all $i \ne j$.</p>



## 출력


<p>Output in a line a single integer, which is the time in seconds when Mr. D reaches point $L$.</p>



## 소스코드

[소스코드 보기](Stop%20&%20Go.cpp)