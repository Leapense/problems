# 24766번: Odds of Mia - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24766)


<p>This problem relates to the game of Mia introduced earlier. We recommend that you first solve Mia to understand how the game is scored. In this problem, you are asked to compute the odds that player 1 will win given partial knowledge of both rolls.</p>



## 입력


<p>The input will contain multiple test cases. Each test case contains on a single line four symbols s<sub>0</sub> s<sub>1</sub> r<sub>0</sub> r<sub>1</sub> where s<sub>0</sub> s<sub>1</sub> represent the dice rolled by players 1 and r<sub>0</sub> r<sub>1</sub> represents the dice rolled by player 2. A <code>*</code> represents that the value is not known, otherwise a digit represents the value of the dice. The input will be terminated by a line containing 4 zeros.</p>



## 출력


<p>For each test case output the odds that player 1 will win. If the odds are 0 or 1, output <code>0</code> or <code>1</code>. Otherwise, output the odds in the form <code>a/b</code> where <code>a</code> and <code>b</code> represent the nominator and denominator of a reduced fraction (i.e., in lowest terms).</p>



## 소스코드

[소스코드 보기](Odds%20of%20Mia.py)