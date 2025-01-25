# 24469번: Autići - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24469)


<p>There are $n$ friends. Each friend has a remote control toy car and a garage in which the car is stored. Every friend also has a pack of road parts used to build the track for the cars. All the road parts in the $i$-th friend’s pack have the same length $d_i$.</p>

<p>Two different friends $a$ and $b$ may connect their garages with a road. To build this road, they will both take a road part from their pack and join them, obtaining a road of length $d_a+d_b$. Some pairs of friends are going to connect their garages in the described way, so that everyone’s garages are connected. In other words, starting from any garage it should be possible to reach any other garage using the roads.</p>

<p>What is the minimum total road length needed to make a road network in which all the garages are connected?</p>



## 입력


<p>The first line contains a positive integer $n$ ($1 ≤ n ≤ 100\,000$), the number of friends.</p>

<p>The next line contains $n$ positive integers $d_i$ ($1 ≤ d_i ≤ 10^9$), the length of the road parts in the $i$-th friend’s pack.</p>



## 출력


<p>In the only line print the minimum total road length needed to make all the garages connected.</p>



## 소스코드

[소스코드 보기](Autići.cpp)