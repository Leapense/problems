# 30544번: Cuckoo! Cuckoo! - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30544)


<p>The cuckoo bird pops out of the cuckoo clock and sounds off once on the quarter hour, half hour, and three-quarter hour. At the beginning of each hour, it sounds off the hour (1--12). Given the current time and a target number $N$, your task is to determine what time it will be when the cuckoo bird finishes sounding off $N$ times. If the cuckoo bird would be sounding off at the starting time, include those sounds in the count.</p>

<p>If the count is reached on the hour, report the time at the start of that hour. That is, you may assume the cuckoo finishes sounding off before the minute is up.</p>



## 입력


<p>The input consists of 2 lines. The first line contains the current time in the form <code>HH:MM</code> where $1 \leq$ <code>HH</code> $\leq 12$ and $0 \leq$ <code>MM</code> $\leq 59$, with leading 0's if necessary. The second line contains a single integer representing the target number $N$ such that $1 \leq N \leq 200$.</p>



## 출력


<p>Print the time at which the cuckoo bird has sounded off $N$ times. The time should be printed in the same format as the input.</p>



## 소스코드

[소스코드 보기](Cuckoo!%20Cuckoo!.cpp)