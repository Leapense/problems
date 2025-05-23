# 21170번: Digital Speedometer - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21170)


<p>A digital speedometer shows a vehicle's speed as integer miles per hour. &nbsp;There are occasions when the sensed speed varies between two integer values, such as during cruise control. &nbsp;Using a single threshold to round between adjacent integers often makes the display toggle rapidly between the two integers, which is distracting to the driver.</p>

<p>Your team must implement a smoothing technique for the display using separate rising and falling thresholds ($t_r$ and $t_f$, $t_f &lt; t_r$, respectively). See Figure 1 for a graphical depiction of the Sample Input for use with the following rules.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/073f7ec7-e242-4403-a83e-b489edc6efb7/-/preview/" style="width: 550px; height: 315px;"></p>

<p style="text-align: center;">Figure 1: Sensor reading from the Sample Input, with $t_f=0.25$ and $t_r=0.75$.</p>

<p>Each sensed speed, $s$, falls between two adjacent integers $i$ and $j$, $i \le s &lt; j$, where $j = i + 1$. &nbsp;When displaying the sensed speed $s$ as an integer:</p>

<ul>
<li>When $s$ falls between $i$ and $i+t_f$, $s$ is displayed as $i$.</li>
<li>When $s$ falls between $i+t_r$ and $j$, $s$ is displayed as $j$.</li>
<li>When $s$ falls between $i+t_f$ and $i+t_r$, $s$ is displayed as $i$ if the most recent preceding value for $s$ outside of range $[i+t_f, i+t_r]$ is less than $i+t_r$, and $s$ is displayed as $j$ if the most recent preceding value for $s$ outside of range $[i+t_f, i+t_r]$ is greater than $i+t_r$.</li>
<li>Any sensed speed, $0 &lt; s &lt; 1$, must display as $1$ because any non-zero speed, no matter how small, must display as non-zero to indicate that the vehicle is in motion.</li>
</ul>



## 입력


<p>The first line of input contains $t_f$, the falling threshold. The second line of input contains $t_r$, the rising threshold. The speed sensor reports $s$ in increments of $0.1$ mph. &nbsp;The thresholds are always set halfway between speed increments. All remaining lines until end-of-file are successive decimal speeds, $s$, in miles per hour, one speed per line. The third line of input, which is the first measured speed, will always be $0$. There are at most $1000$ observed speeds $s$ in input. $$0 &lt; t_f,t_r &lt; 1; \ \ \ \ t_f &lt; t_r; \ \ \ \ 0 \le s \le 120$$</p>



## 출력


<p>Output is the list of speeds, one speed per line, smoothed to integer values appropriate to $t_f$ and $t_r$.</p>



## 소스코드

[소스코드 보기](Digital%20Speedometer.py)