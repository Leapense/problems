# 21344번: Hot Springs - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21344)


<p>Iceland is famous for its geothermal activity, which supplies the country with much of its electricity and heating. It is also a source of pleasure, in the form of hot springs.</p>

<p>Kalle is visiting one of Iceland's famous hot springs. It contains $n$ pools of water, where the $i$th one has temperature $t_i$. Although staying in one of the warmer pools for a long time sure is relaxing, Kalle is on a very tight schedule and just wants a quick dip in each of the pools. As you may know, the nicest thing about hot baths is the contrast between hot and cold. Therefore, to get the most out of his stay, Kalle wants to find an ordering of the pools so that the difference in temperature between subsequent pools is increasing.</p>

<p>Given a sequence of pool temperatures $t_1, t_2, \dots, t_n$, rearrange them into a new sequence $t'_1, t'_2, \dots, t'_n$ such that for all $2 \leq i \leq n-1$ it holds that \[ |t'_{i-1} - t'_i| \leq |t'_i - t'_{i+1}|. \]</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with an integer $n$ ($2 \le n \leq &nbsp;10^5$), the number of pools.</li>
<li>One line with $n$ integers $t_1, \ldots, t_n$ ($-10^5 \leq t_i \leq 10^5$ for each $i$), the temperatures in each of the $n$ pools.</li>
</ul>



## 출력


<p>Output a rearrangement of the sequence satisfying the given requirement. If no solution exists, output "<code>impossible</code>". If there are multiple valid solutions, you may output any one of them.</p>



## 소스코드

[소스코드 보기](Hot%20Springs.cpp)