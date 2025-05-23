# 21113번: Returning Lights To Box - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21113)


<p>Wesley needs to take down his holiday lights. He has a line of $N$ lights, some of which may be on, and Wesley needs all the lights to be off before he can unplug them (or else he will receive a deadly electrical shock).&nbsp;</p>

<p>Each light has a corresponding switch that can be used to turn the light on or off, and Wesley can use at most one of these switches every second, starting from the first second. However, these lights are finicky, and in the next $M$ seconds they will toggle their state on their own! Specifically, at the end of $i$-th second, the $b_i$-th light will flip its state: turn on if it was off, or turn off if it was on. Wesley wants to take the lights down as soon as possible, so he would like to know what is the earliest time possible for all the lights to be off, assuming he uses switches in an ideal manner. In particular, output the least $i$ such that all lights can be turned off by the end of the $i$-th second by some sequence of switch usages. Note that if all lights are initially off, then the least such $i$ is 0.</p>



## 입력


<p>The first line contains two integers $N$ and $M$, the number of lights and the number of unsolicited changes the lights will make ($1 \le N, M \le 2 \cdot 10^5$).</p>

<p>The second line will contain $N$ integers $a_1, a_2, \ldots, a_N$ ($0 \le a_i \le 1$), the initial state of the lights. Here, $a_i = 1$ indicates that the $i$-th light is initially on, and $a_i = 0$ tells it is off.</p>

<p>The third and final line will contain $M$ integers $b_1, b_2, \ldots b_M$, which denotes that the $b_i$-th light flips its state at the end of $i$-th second ($1 \le b_i \le N$).</p>



## 출력


<p>Output a single integer, the earliest time (in seconds) it will take for Wesley to turn all the lights off. Note that if all the lights can be turned off before $M$ seconds have passed, Wesley will ignore any future toggles and take them down immediately.</p>



## 소스코드

[소스코드 보기](Returning%20Lights%20To%20Box.py)