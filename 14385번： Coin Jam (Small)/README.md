# 14385번: Coin Jam (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14385)


<p>A jamcoin is a string of N ≥ 2 digits with the following properties:</p>

<ul>
<li>Every digit is either <code>0</code> or <code>1</code>.</li>
<li>The first digit is <code>1</code> and the last digit is <code>1</code>.</li>
<li>If you interpret the string in any base between 2 and 10, inclusive, the resulting number is not prime.</li>
</ul>

<p>Not every string of <code>0</code>s and <code>1</code>s is a jamcoin. For example, <code>101</code> is not a jamcoin; its interpretation in base 2 is 5, which is prime. But the string <code>1001</code> is a jamcoin: in bases 2 through 10, its interpretation is 9, 28, 65, 126, 217, 344, 513, 730, and 1001, respectively, and none of those is prime.</p>

<p>We hear that there may be communities that use jamcoins as a form of currency. When sending someone a jamcoin, it is polite to prove that the jamcoin is legitimate by including a nontrivial divisor of that jamcoin's interpretation in each base from 2 to 10. (A nontrivial divisor for a positive integer K is some positive integer other than 1 or K that evenly divides K.) For convenience, these divisors must be expressed in base 10.</p>

<p>For example, for the jamcoin <code>1001</code> mentioned above, a possible set of nontrivial divisors for the base 2 through 10 interpretations of the jamcoin would be: 3, 7, 5, 6, 31, 8, 27, 5, and 77, respectively.</p>

<p>Can you produce J different jamcoins of length N, along with proof that they are legitimate?</p>



## 입력


<p>The first line of the input gives the number of test cases, T. T test cases follow; each consists of one line with two integers N and J.</p>

<p>Limits</p>

<ul>
<li>T = 1. (There will be only one test case.)</li>
<li>It is guaranteed that at least J distinct jamcoins of length N exist.</li>
<li>N = 16.</li>
<li>J = 50.</li>
</ul>

<p>Note that, unusually for a Code Jam problem, you already know the exact contents of each input file. For example, the Small dataset's input file will always be exactly these two lines:</p>

<p><code>1 16 50</code></p>

<p>So, you can consider doing some computation before actually downloading an input file and starting the clock.</p>



## 출력


<p>For each test case, output J+1 lines. The first line must consist of only <code>Case #x:</code>, where <code>x</code> is the test case number (starting from 1). Each of the last J lines must consist of a jamcoin of length N followed by nine integers. The i-th of those nine integers (counting starting from 1) must be a nontrivial divisor of the jamcoin when the jamcoin is interpreted in base i+1.</p>

<p>All of these jamcoins must be different. You cannot submit the same jamcoin in two different lines, even if you use a different set of divisors each time.</p>



## 소스코드

[소스코드 보기](Coin%20Jam%20(Small).cpp)