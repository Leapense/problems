# 14012번: Large PhD Restaurant - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14012)


<p><strong>"There is probably a place where all waiters have a PhD in, I don't know, some stuff."</strong>&nbsp;- Dudu, 2014</p>

<p><strong>Note:</strong>&nbsp;This problem is identical to Small PhD Restaurant, but with larger bounds.</p>

<p>Dudu is hungry. He sat down in a nice Thai restaurant. To his amazement, he realized that he is in the&nbsp;<em>PhD restaurant</em>, a wonderful place where every staff member has a PhD in&nbsp;<em>some stuff</em>.</p>

<p>Even more, each staff member has arranged a challenge related to his or her field of study for Dudu to attempt while he waits for his food. The challenge arranged by staff member i costs A<sub>i</sub>&nbsp;to attempt and will award Dudu B<sub>i</sub>when he completes it successfully.</p>

<p>Each challenge can be completed at most once and they can be attempted in any order. Dudu is very smart and can complete any challenge, but he must have enough money to pay A<sub>i</sub>&nbsp;before he attempts challenge i. If Dudu starts with M money, determine the maximum amount he can obtain.</p>



## 입력


<p>Input begins with a line containing two integers N and M, the number of challenges and the amount of money Dudu begins with, respectively.</p>

<p>The following line contains N numbers A<sub>1</sub>,A<sub>2</sub>, ..., A<sub>N</sub>, indicating the costs to attempt each challenge.</p>

<p>Finally, the last line contains the N numbers B<sub>1</sub>, B<sub>2</sub>, ..., B<sub>N</sub>&nbsp;indicating the payoff from each challenge.</p>

<ul>
<li>1 ≤ N ≤ 10<sup>5</sup></li>
<li>0 ≤ M, A<sub>i</sub>, B<sub>i</sub>&nbsp;≤ 10<sup>6</sup></li>
</ul>



## 출력


<p>Output a single integer indicating the maximum amount of money Dudu can obtain.</p>



## 소스코드

[소스코드 보기](Large%20PhD%20Restaurant.cpp)