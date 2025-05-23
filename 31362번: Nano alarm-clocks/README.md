# 31362번: Nano alarm-clocks - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31362)


<p>An old watchmaker has $n$ stopped nano alarm-clocks numbered with integers from $1$ to $n$. Nano alarm-clocks count time in hours, and in one hour there are million minutes, each minute lasting a million seconds. In order to repair them all the watchmaker should synchronize the time on all nano alarm-clocks. In order to do this he moves clock hands a certain time forward (may be zero time). Let’s name this time shift a transfer time.</p>

<p>Your task is to calculate the minimal total transfer time required for all nano alarm-clocks to show the same time.</p>



## 입력


<p>The first line contains a single integer $n$ --- the number of nano alarm-clocks ($2 \le n \le 10^5$). In each $i$-th of the next $n$ lines the time $h$, $m$, $s$, shown on the $i$-th clock. Integers $h$, $m$ and $s$ show the number of hours, minutes and seconds respectively. ($0 \le h &lt; 12$, $0 \le m &lt; 10^6$, $0 \le s &lt; 10^6$).</p>



## 출력


<p>Output three integers separated with spaces $h$, $m$ and $s$ --- total minimal transfer time, where $h$, $m$ and $s$ --- number of hours, minutes and seconds respectively ($0 \le m &lt; 10^6$, $0 \le s &lt; 10^6$).</p>



## 소스코드

[소스코드 보기](Nano%20alarm-clocks.cpp)