# 14326번: Jane's Flower Shop (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14326)


<p>Jane plans to open a flower shop in the local flower market. The initial cost includes the booth license, furnishings and decorations, a truck to transport flowers from the greenhouse to the shop, and so on. Jane will have to recoup these costs by earning income. She has estimated how much net income she will earn in each of the following&nbsp;Mmonths.</p>

<p>Jane wants to predict how successful her flower shop will be by calculating the&nbsp;IRR (Internal Rate of Return)&nbsp;for the&nbsp;M-month period. Given a series of (time, cash flow) pairs (i, C<sub>i</sub>), the IRR is the compound interest rate that would make total cash exactly 0 at the end of the last month. The higher the IRR is, the more successful the business is. If the IRR is lower than the inflation rate, it would be wise not to start the business in the first place.</p>

<p>For example, suppose the initial cost is \$10,000 and the shop runs for 3 months, with net incomes of \$3,000, \$4,000, and \$5,000, respectively. Then the IRR&nbsp;r&nbsp;is given by:</p>

<p><img src="https://onlinejudgeimages.s3.amazonaws.com/problem/14326/%EB%8B%A4%EC%9A%B4%EB%A1%9C%EB%93%9C%20(7).png" style="height:27px; width:404px"></p>

<p>In this case, there is only one rate (~=8.8963%) that satisfies the equation.</p>

<p>Help Jane to calculate the IRR for her business. It is guaranteed that -1 &lt;&nbsp;r&nbsp;&lt; 1, and there is exactly one solution in each test case.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;T.&nbsp;T&nbsp;test cases follow. Each test case starts with a positive integer&nbsp;M: the number of months that the flower shop will be open. The next line contains&nbsp;M&nbsp;+ 1 non-negative integers&nbsp;C<sub>i</sub>&nbsp;(0 ≤ i ≤&nbsp;M). Note that&nbsp;C<sub>0</sub>represents the initial cost, all the remaining&nbsp;C<sub>i</sub>s are profits, the shop will always either make a positive net profit or zero net profit in each month, and will never have negative profits.</p>

<p>Limits</p>

<ul>
<li>1 ≤&nbsp;T&nbsp;≤ 100.</li>
<li>C<sub>0</sub>&nbsp;&gt; 0.</li>
<li>0 ≤&nbsp;C<sub>i</sub>&nbsp;≤ 1,000,000,000.</li>
<li>1 ≤&nbsp;M&nbsp;≤ 2.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is a floating-point number: the IRR of Jane's business.&nbsp;<code>y</code>will be considered correct if it is within an absolute&nbsp; or relative error of 10<sup>-9</sup>&nbsp;of the correct answer.</p>



## 소스코드

[소스코드 보기](Jane's%20Flower%20Shop%20(Small).cpp)