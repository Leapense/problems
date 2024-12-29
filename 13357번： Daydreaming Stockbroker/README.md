# 13357번: Daydreaming Stockbroker - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13357)


<p>Gina Reed, the famous stockbroker, is having a slow&nbsp;day at work, and between rounds of solitaire she is daydreaming.&nbsp;Foretelling the future is hard, but imagine if&nbsp;you could just go back in time and use your knowledge&nbsp;of stock price history in order to maximize your profits!</p>

<p>Now Gina starts to wonder: if she were to go back in&nbsp;time a few days and bring a measly \$100 with her, how&nbsp;much money could she make by just buying and selling&nbsp;stock in Rollercoaster Inc. (the most volatile stock in&nbsp;existence) at the right times? Would she earn enough&nbsp;to retire comfortably in a mansion on Tenerife?</p>

<p>Note that Gina can not buy fractional shares, she must buy whole shares in Rollercoaster&nbsp;Inc. The total number of shares in Rollercoaster Inc. is 100 000, so Gina can not own more than&nbsp;100 000 shares at any time. In Gina’s daydream, the world is nice and simple: there are no fees&nbsp;for buying and selling stocks, stock prices change only once per day, and her trading does not&nbsp;influence the valuation of the stock.</p>



## 입력


<p>The first line of input contains an integer d (1 ≤ d ≤ 365), the number of days that Gina goes&nbsp;back in time in her daydream. Then follow d lines, the i’th of which contains an integer p<sub>i&nbsp;</sub>(1 ≤ p<sub>i</sub> ≤ 500) giving the price at which Gina can buy or sell stock in Rollercoaster Inc. on day&nbsp;i. Days are ordered from oldest to newest.</p>



## 출력


<p>Output the maximum possible amount of money Gina can have on the last day. Note that the&nbsp;answer may exceed 2<sup>32</sup>.</p>



## 소스코드

[소스코드 보기](Daydreaming%20Stockbroker.py)