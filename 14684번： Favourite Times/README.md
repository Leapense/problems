# 14684번: Favourite Times - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14684)


<p>Wendy has an LED clock radio, which is a 12-hour clock, displaying times from 12:00 to 11:59. The hours do not have leading zeros but minutes may have leading zeros, such as 2:07 or 11:03.</p>

<p>When looking at her LED clock radio, Wendy likes to spot arithmetic sequences in the digits. For example, the times 12:34 and 2:46 are some of her favourite times, since the digits form an arithmetic sequence.</p>

<p>A sequence of digits is an arithmetic sequence if each digit after the first digit is obtained by adding a constant common difference. For example, 1,2,3,4 is an arithmetic sequence with a common difference of 1, and 2,4,6 is an arithmetic sequence with a common difference of 2.</p>

<p>Suppose that we start looking at the clock at noon (that is, when it reads 12:00) and watch the clock for some number of minutes. How many instances are there such that the time displayed on the clock has the property that the digits form an arithmetic sequence?</p>



## 입력


<p>The input contains one integer D (0 ≤ D ≤ 1 000 000 000), which represents the duration that the clock is observed.</p>

<p>For 4 of the 15 available marks, D ≤ 10 000.</p>



## 출력


<p>Output the number of times that the clock displays a time where the digits form an arithmetic sequence starting from noon (12:00) and ending after D minutes have passed, possibly including the ending time.</p>



## 소스코드

[소스코드 보기](Main.java)