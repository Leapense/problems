# 16865번: The Ups and Downs of Investing - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16865)


<p>Liam is heavily invested in the stock market, and has various theories that he uses to predict when the market will rise and when it will fall. Lately, things haven’t been going too well – the only thing rising is his frustration and the only thing falling is his portfolio. He has decided that he needs more data to test his theories with. One characteristic of the market he is particularly interested in is the peaks and valleys of the price of particular stocks. Liam’s definition of a peak is an increasing sequence of at least n consecutive stock prices ending on a peak day, and then a decreasing sequence of at least n consecutive stock prices starting on the peak day (where n depends on the particular stock). A valley is analogous: a decreasing sequence of at least m consecutive stock prices ending on a valley day, and then an increasing sequence of at least m consecutive stock prices starting on the valley day (where again m depends on the particular stock and may differ from n). For example, consider the two weeks of stock prices shown below:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a777895b-80c5-4a59-9464-da007387bec8/-/preview/" style="width: 566px; height: 245px;"></p>

<p>If n = 2 and m = 3 then there are three peaks in this data (with highest points on days 3, 7 and 12) and one valley (with lowest point on day 9). Notice that there is no valley around day 6, since there is not an increasing sequence of length 3 starting at day 6.</p>

<p>Given a set of stock prices and values for n and m, Liam would like to know how many peaks and valleys there are in the data.</p>



## 입력


<p>Input starts with a line containing three positive integers s n m, where 1 ≤ s ≤ 1 000 is the number of stock prices, and 2 ≤ n, m ≤ 100 are the parameters described above. Following this line will be one or more lines containing a total of s stock prices. All stock prices are non-negative and no two consecutive stock prices will be the same.</p>



## 출력


<p>Display the number of peaks in the data and the number of valleys in the data.</p>



## 소스코드

[소스코드 보기](The%20Ups%20and%20Downs%20of%20Investing.cpp)