# 25996번: Equalising Audio - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25996)


<p>As a radio engineer at the Balanced Audio Podcast \copyright{} your job is to deliver an equal listening experience at all times. You did a poll among the listeners and they are especially concerned about fluctuations in loudness. To resolve this you bought a transformer to equalise the audio, but alas, its software got corrupted during transport.</p>

<p>Your job is to rewrite the equalising software. As input the transformer gets $n$ amplitudes $a_1, \ldots, a_n$, with an average perceived loudness of $\frac{1}{n}\sum_{i=1}^n a_i^2$. The output should contain the same amplitudes, but renormalised by some constant positive factor, such that the average perceived loudness is $x$. There is one exception: total silence should always be preserved.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with a two integers $n$ and $x$ ($1\leq n\leq 10^5$, $0 \leq x \leq 10^6)$, the number of amplitudes and the average perceived loudness to achieve.</li>
<li>One line with $n$ integers $a_1, \ldots, a_n$ ($\left| a_i \right| \leq 10^6$), the amplitudes.</li>
</ul>



## 출력


<p>Output one line containing $n$ numbers, the renormalised amplitudes with an average perceived loudness of $x$.</p>

<p>Your answers should have an absolute or relative error of at most $10^{-6}$.</p>



## 소스코드

[소스코드 보기](Equalising%20Audio.cpp)