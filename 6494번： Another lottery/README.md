# 6494번: Another lottery - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6494)


<p>Even in times of an economic crisis, people in Byteland still like to participate in lotteries. With a bit of luck, they might get rid of all their sorrows and become rich.</p>

<p>The most popular lottery in Byteland consists of <em>m</em> rounds. In each round, everyone can purchase as many tickets as he wishes, and among all tickets sold in this round, one ticket is chosen randomly, each one with the same probability. The owner of that ticket wins the prize money of this round. Since people in Byteland like powers of 2, the prize money for the winner of round <em>i</em> amounts to <em>2<sup>i</sup></em> Bytelandian Dollars.</p>

<p>Can you determine for each participant in the lottery the probability that he will win more money than anybody else?</p>



## 입력


<p>The input consists of several test cases. Each test case starts with a line containing two integers <em>n</em> and <em>m</em>, the number of participants in the lottery and the number of rounds in the lottery. You may assume that <em>1 ≤ n ≤ 10000</em> and <em>1 ≤ m ≤ 30</em>.</p>

<p>The following <em>n</em> lines contain the description of the tickets bought by the participant. The <em>i<sup>th</sup></em> such line contains <em>m</em> non-negative integers <em>c<sub>1</sub>, ..., c<sub>m</sub></em>, where <em>c<sub>j</sub></em> (<em>1 ≤ j ≤ m</em>) is the amount of tickets of round <em>j</em> bought by partipant <em>i</em>. The total number of tickets sold in each round is between <em>1</em> and <em>10<sup>9</sup></em>.</p>

<p>The input ends with a line containing 2 zeros.</p>



## 출력


<p>For each test case, print <em>n</em> lines of output, where line <em>i</em> contains the probability as a reduced fraction that participant <em>i</em> wins the most money. See the sample output for details.</p>



## 소스코드

[소스코드 보기](Another%20lottery.cpp)