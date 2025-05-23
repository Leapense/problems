# 30559번: Boat Commuter - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30559)


<p>The Bulgarian city of Nodnol runs a boat service to ferry its residents between the trendy areas in which they live and the large metallic structures in which they work on the next recession.</p>

<p>TFN (Transport For Nodnol) has issued $m$ travel cards (known affectionally as "Retsyo"), which are numbered from $1$ to $m$. Each pier has a card terminal at which passengers are required to tap "in" when starting the trip and to tap "out" when finishing it.</p>

<p>As there is only one card terminal on each pier, passengers use the same device to tap in and to tap out.</p>

<p>Trip cost depends on the distance travelled and is determined as follows:</p>

<ul>
<li>if the trip started at the pier $i$ and finished at the pier $j$ ($i \ne j$), then its cost is $|i-j|$ pounds;</li>
<li>if the trip started somewhere and was not finished with a tap out, then it costs \pounds100;</li>
<li>if the trip started and finished in the same place, then it also costs \pounds100, as it is interpreted as an attempt to game the system.</li>
</ul>

<p>You are given a sequence of tapping events --- for each you have the pier $p_i$ and card number $c_i$ recorded. You are to determine how much the transport authority should charge each of the cards</p>



## 입력


<ul>
<li>One line containing three integer numbers: the number of piers $n$, the number of travel cards $m$, and the number of events $k$ ($2 \le n \le 50$, $1 \le m, k \le 10^5$).</li>
<li>$k$ further lines, each describing tap events in chronological order.
<ul>
<li>The $i$-th event is described by two integers $p_i$ and $c_i$ ($1 \le p_i \le n$, $1 \le c_i \le m$).</li>
</ul>
</li>
</ul>



## 출력


<p>Output $m$ integers separated by spaces --- the $i$-th integer giving the total charge to be applied to the $i$-th card.</p>



## 소스코드

[소스코드 보기](Boat%20Commuter.cpp)