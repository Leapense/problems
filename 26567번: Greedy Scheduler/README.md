# 26567번: Greedy Scheduler - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26567)


<p>A store has n cashiers numbered sequentially from 1 to n, with c customers in a queue. A customer at the front of the queue is constantly assigned to the first unoccupied cashier, (i.e., if more than one cashier is unoccupied select the cashier with the smallest number). The ith customer’s shopping cart takes ti seconds to process.</p>

<p>Find which cashier will process each customer’s shopping cart.</p>



## 입력


<p>The first line of input will contain a single integer m that indicates the number datasets to follow. Each dataset is comprised of two lines. The first line of input contains two space-separated integers n and c (1 ≤ n ≤ c ≤ 1000). The second line of input contains c space-separated integers t<sub>1</sub>, . . . , t<sub>c</sub>, representing the length of time required to handle that customer.</p>



## 출력


<p>For each dataset print, on a single line c integers separated by one space, where each integer is the cashier number that handles that customer.</p>



## 소스코드

[소스코드 보기](Greedy%20Scheduler.cpp)