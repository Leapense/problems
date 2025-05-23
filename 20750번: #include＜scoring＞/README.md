# 20750번: #include＜scoring＞ - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20750)


<p>As you may know, LTH Challenge is part of a series of seven competitions called the <em>Swedish Coding Cup</em>. Each contest in the series gives the contestants a number of points depending on how well they place in the contest.</p>

<p>After each contest, scores are assigned according to the following table:</p>

<table class="table table-bordered td-center th-center table-center-20">
<thead>
<tr>
<th><strong>Rank</strong></th>
<th><strong>Score</strong></th>
<th><strong>Rank</strong></th>
<th><strong>Score</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td>$1$</td>
<td>$100$</td>
<td>$16$</td>
<td>$15$</td>
</tr>
<tr>
<td>$2$</td>
<td>$75$</td>
<td>$17$</td>
<td>$14$</td>
</tr>
<tr>
<td>$3$</td>
<td>$60$</td>
<td>$18$</td>
<td>$13$</td>
</tr>
<tr>
<td>$4$</td>
<td>$50$</td>
<td>$19$</td>
<td>$12$</td>
</tr>
<tr>
<td>$5$</td>
<td>$45$</td>
<td>$20$</td>
<td>$11$</td>
</tr>
<tr>
<td>$6$</td>
<td>$40$</td>
<td>$21$</td>
<td>$10$</td>
</tr>
<tr>
<td>$7$</td>
<td>$36$</td>
<td>$22$</td>
<td>$9$</td>
</tr>
<tr>
<td>$8$</td>
<td>$32$</td>
<td>$23$</td>
<td>$8$</td>
</tr>
<tr>
<td>$9$</td>
<td>$29$</td>
<td>$24$</td>
<td>$7$</td>
</tr>
<tr>
<td>$10$</td>
<td>$26$</td>
<td>$25$</td>
<td>$6$</td>
</tr>
<tr>
<td>$11$</td>
<td>$24$</td>
<td>$26$</td>
<td>$5$</td>
</tr>
<tr>
<td>$12$</td>
<td>$22$</td>
<td>$27$</td>
<td>$4$</td>
</tr>
<tr>
<td>$13$</td>
<td>$20$</td>
<td>$28$</td>
<td>$3$</td>
</tr>
<tr>
<td>$14$</td>
<td>$18$</td>
<td>$29$</td>
<td>$2$</td>
</tr>
<tr>
<td>$15$</td>
<td>$16$</td>
<td>$30$</td>
<td>$1$</td>
</tr>
</tbody>
</table>

<p>If a contestant get a worse rank than $30$, they get $0$ points.</p>

<p>If two or more contestants get the same rank in the contest, they are instead assigned the average score of all the corresponding ranks. This score is always rounded up to the closest integer. For example, if three contestants share the second place they all recieve $\lceil \frac{75 + 60 + 50}{3} \rceil = 62$ points.</p>

<p>Contestants may participate in every contest either on-site or online. If they compete on-site, they get one extra point, no matter their original score. If a contestant does not participate in a contest, they are assigned a score of $0$.</p>

<p>At LTH Challenge, the rank of each contestant is computed using what is called <em>ACM scoring</em>. Each contestant is ranked first on the number of problems they solve (in descending order), secondly on their time penalty (in ascending order) and finally the time at which they submitted their last accepted solution in minutes (in ascending order). If all these three properties are equal, the contestants are tied.</p>

<p>As you may understand, it is really tedious to compute the scores of all the contestants after such a contest. The jury does not really want to program this themselves; they prefer to just use some existing library instead. However, it turns out that since this is the first time the Swedish Coding Cup is held, nobody had written such a library!</p>

<p>Fortunately, they have you.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>one line with the integer $n$ ($1 \le n \le 1\,000$), the number of contestants.</li>
<li>$n$ lines with the integers $s$, $p$, $f$ and $o$, ($0 \le s \le 9$, $0 \le p \le 10^9$, $0 \le f \le 300$, $0 \le o \le 1$) -- the number of problems solved by a contestant, the time penalty of the contestant, the time at which they submitted their last accepted solution and the number of extra points the contestant should get due to competing on-site.</li>
</ul>



## 출력


<p>Output $n$ lines containing the scores of all the contestants in the order they were listed in the input.</p>



## 소스코드

[소스코드 보기](#include＜scoring＞.cpp)