# 19358번: Waiter's Problem - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19358)


<p>Cafe Satori hires only experienced waiters, and there is a reason for that. Everyday during lunchtime, at 12:00 noon, a horde of hungry customers enters the cafe and waits to be served. Therefore, the only waiter on duty has his hands full. Fortunately, his heroic work will be rewarded with generous tips.</p>

<p>Each customer is willing to leave a specific amount of tip, provided he is served immediately. For each minute of waiting the tip decreases by one, until it reaches zero.</p>

<p>It takes one minute for the waiter to serve a customer. Solve the waiter's problem and calculate how much money he can get, provided he serves customers in an optimal order.</p>



## 입력


<p>The first line of input contains the number of test cases $z$ ($1 \leq z \leq 10^9$). The descriptions of the test cases follow.</p>

<p>The first line of each test case contains the number of customers $n$ ($1 \le n \le 100\,000$). The second line contains $n$ non-negative integers not exceeding $10^9$: these are the amounts of tips the customers are willing to give initially.</p>

<p>The total number of customers in all test cases does not exceed $1\,000\,000$.</p>



## 출력


<p>For each test case, output the maximum total amount of tips the waiter can get.</p>



## 소스코드

[소스코드 보기](Waiter's%20Problem.cpp)