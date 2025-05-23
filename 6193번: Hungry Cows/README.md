# 6193번: Hungry Cows - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6193)


<p>Each of Farmer John's N (1 &lt;= N &lt;= 5,000) cows has a unique positive integer brand that fits nicely into 32 signed bits. He wishes the cows would line up in numerical order for feeding, but they never cooperate. To encourage good behavior, he allows a cow to eat only if it is the first cow to be chosen to eat or if its number is greater than the cow that ate before it.</p>

<p>Given a listing of the ordering of cow brands for the cows standing in line, what is the largest number of cows that can be fed using FJ rules?</p>

<p>Consider this line of 11 cows:</p>

<pre>2 5 18 3 4 7 10 9 11 8 15</pre>

<p>One could feed cows in the order 2, 3, 4, 7, 10 11, and 15 for a total of seven fed, the largest number possible.</p>

<p>One could not feed cows in the order 2, 5, 3, 10 15 since cow 3's brand is not greater than its predecessor, 5.</p>



## 입력


<ul>
<li>Line 1: A single integer, N&nbsp;</li>
<li>Lines 2..?: Each line except potentially the last contains 20 space-separated integers that are successively the brands of the cows in line. The last line might have fewer than 20 integers if N is not an exact multiple of 20.</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: The length of the largest chain of cows where each brand is greater than its predecessor.</li>
</ul>



## 소스코드

[소스코드 보기](Hungry%20Cows.py)