# 21021번: Prize Coupon - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21021)


<p>There are N students studying at BINUS University numbered from 1 to N. Each student has their own unique identifier (ID).</p>

<p>As a result of recent achievements, BINUS University wants to distribute coupons to their students. The i<sup>th</sup> student received Ci coupons from the university. For each of the received coupon, the student must write a student’s ID on the back of the coupon. The written ID might belong to the student themselves or another student. However, the university enforces that the i<sup>th</sup> student cannot write the j<sup>th</sup> student’s ID if the difference between i and j is more than one, i.e. |i − j|&gt; 1.</p>

<p>After all the students have written a student’s ID on the back of each coupon, all coupons are then collected by the university. The university then grants a prize to each student whose ID is written on at least one coupon.</p>

<p>For example, let N = 4 and C<sub>1...4</sub> = {3, 0, 1, 0}.</p>

<ul>
<li>The first student can write the second student’s ID on two of their coupons, and write the first student’s ID on the remaining coupon.</li>
<li>The third student can write the fourth student’s ID on their coupon.</li>
<li>Therefore, the first, second, and fourth students get at least one prize.</li>
</ul>

<p>The students want to write the student’s ID such that the number of distinct students who get a prize is maximized. The students studying at BINUS University are known to be selfless, so they might not write their own ID and write other’s ID instead if it can increase the number of students who will get a prize.</p>

<p>Your task is to determine the maximum number of students who will get a prize.</p>



## 입력


<p>Input begins with a line containing an integer: N (1 ≤ N ≤ 100 000) representing the number of students. The next line contains N integers: C<sub>i</sub> (0 ≤ C<sub>i</sub> ≤ 3) representing the number of received coupons.</p>



## 출력


<p>Output in a line an integer representing the maximum number of students who will get a prize.</p>



## 소스코드

[소스코드 보기](Prize%20Coupon.py)