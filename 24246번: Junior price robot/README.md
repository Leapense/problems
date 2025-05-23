# 24246번: Junior price robot - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24246)


<p>The idea behind your latest business adventure, BarGain Overview (BGO), is to collect the history of prices for a certain item that is available for sale on the web. The <em>BarGain score</em> of a particular day is defined as the number of days since the price was lower or equal to today's price. The worst BarGain score is thus $1$, and if the price is strictly better than all previous prices ever recorded, then it is <code>infinity</code>. You want to report the BarGain score to your customers to help them identify a good buy.</p>



## 입력


<p>The first line of input contains a single integer $2 \leq n \leq 400\,000$, the number of days for which you have collected price data for the item. On the second line of input follows $n$ space-separated integers $p_1, p_2, \ldots, p_{n}$, where $0 \leq p_i \leq 2 \cdot 10^6$ is the price of the item $i-1$ days ago. Today's price is $p_1$.</p>



## 출력


<p>A line containing today's BarGain score.</p>



## 소스코드

[소스코드 보기](Junior%20price%20robot.py)