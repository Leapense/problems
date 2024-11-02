# 26876번: New Time - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26876)


<p>Nikolay has a digital clock that displays time in 24-hour format, showing two integers: hours (from $00$ to $23$) and minutes (from $00$ to $59$). For example, the clock can show <code>00:00</code>, <code>18:42</code>, or <code>23:59</code>.</p>

<p>The clock has two buttons that can be used for manual adjustment:</p>

<ul>
<li>Button A sets the clock forward by $1$ minute. For example, <code>05:33</code> becomes <code>05:34</code>, <code>16:59</code> becomes <code>17:00</code>, and <code>23:59</code> becomes <code>00:00</code>.</li>
<li>Button B sets the clock forward by $1$ hour. For example, <code>01:42</code> becomes <code>02:42</code>, and <code>23:14</code> becomes <code>00:14</code>.</li>
</ul>

<p>Nikolay has noticed that the time on his clock does not look right. He wants to adjust the clock to the correct time by pressing the buttons as few times as possible.</p>

<p>Find the smallest number of button presses needed to adjust the clock.</p>



## 입력


<p>The first line contains the time shown on the clock in the <code>hh:mm</code> format ($00 \le \mathtt{hh} \le 23$; $00 \le \mathtt{mm} \le 59$).</p>

<p>The second line contains the correct time in the same format.</p>



## 출력


<p>Print a single integer --- the smallest number of button presses Nikolay needs to adjust the time on his clock.</p>



## 소스코드

[소스코드 보기](New%20Time.cpp)