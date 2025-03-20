# 18712번: Ice-cream Knapsack - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18712)


<p>There is a wonderful ice-cream shop that contains N ice-creams, such that each ice-cream is represented by two numbers C<sub>i</sub> and H<sub>i</sub> denoting the number of calories and the happiness value, respectively.</p>

<p>You want to buy exactly K ice-creams such that the calories of the densest ice-cream (the one with most calories) are as minimal as possible. If there is more than one way to do that, you want to maximize the total happiness of the ice-creams you will buy, that is the sum of the happiness values of the chosen ice-creams.</p>



## 입력


<p>The first line of the input contains a single integer T specifying the number of test cases.</p>

<p>Each test case begins with a line containing two integers N and K (1 ≤ K ≤ N ≤ 10<sup>5</sup>), in which N is the number of ice-creams in the shop, and K is the number of ice-creams you want to buy.</p>

<p>Then a line follows containing N integers C<sub>1</sub>, · · · , C<sub>N</sub> (0 ≤ C<sub>i</sub> ≤ 10<sup>9</sup>), in which C<sub>i</sub> is the number of calories in the i<sup>th</sup> ice-cream. Then a line follows containing N integers H<sub>1</sub>, · · · , H<sub>N</sub> (0 ≤ H<sub>i</sub> ≤ 10<sup>9</sup>), in which H<sub>i</sub> is the happiness value of the i<sup>th</sup> ice-cream.</p>



## 출력


<p>For each test case, print a single line containing two space-separated integers representing the calories of the densest ice-cream you will buy and the total happiness of the ice-creams you will buy, respectively.</p>

<p>Remember that your goal is to buy K ice-creams such that the calories of the densest ice-cream (the one with most calories) are as minimal as possible. If there is more than one way to do that, you want to maximize the total happiness of the ice-creams you will buy.</p>



## 소스코드

[소스코드 보기](Ice-cream%20Knapsack.cpp)