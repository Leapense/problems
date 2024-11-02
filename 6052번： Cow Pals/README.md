# 6052번: Cow Pals - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6052)


<p>Bessie and all the other cows have an RFID serial number tag in their ear so FJ can mechanically tally them. Many cows have a 'cowpal' whose serial number is equal to the sum of the divisors (that are not the number itself) of their own serial number. Some cows don't have a cowpal because no cow's serial number matches their divisor sum.</p>

<p>Some cows have a superpal. Cows are superpals when their serial numbers make each of them a pal of the other. Cows that are superpals of themselves are shunned; do not consider them!</p>

<p>Given a serial number S (6 &lt;= S &lt;= 18,000), find the first cow with serial number at least S who has a super pal.</p>

<p>By way of example, consider serial number 220 whose divisors are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, and 110. Their sum is 284. Similarly, the divisors of 284 are 1, 2, 4, 71, and 142. Their sum is 220.</p>



## 입력


<ul>
<li>Line 1: A single integer: S</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single line with two space-separated integers that are the serial number of the first superpal whose serial number is no smaller than S and the serial number of her pal.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Cow%20Pals.py)