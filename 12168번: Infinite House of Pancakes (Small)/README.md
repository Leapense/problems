# 12168번: Infinite House of Pancakes (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12168)


<p>At the Infinite House of Pancakes, there are only finitely many pancakes, but there are infinitely many diners who would be willing to eat them! When the restaurant opens for breakfast, among the infinitely many diners, exactly&nbsp;&nbsp;<strong>D</strong>&nbsp;have non-empty plates; the&nbsp;<strong>i</strong>th of these has&nbsp;<strong>P<sub>i</sub></strong>&nbsp;pancakes on his or her plate. Everyone else has an empty plate.<br>
<br>
Normally, every minute, every diner with a non-empty plate will eat one pancake from his or her plate. However, some minutes may be&nbsp;<em>special</em>. In a special minute, the head server asks for the diners' attention, chooses a diner with a non-empty plate, and carefully lifts some number of pancakes off of that diner's plate and moves those pancakes onto one other diner's (empty or non-empty) plate. No diners eat during a special minute, because it would be rude.<br>
<br>
You are the head server on duty this morning, and it is your job to decide which minutes, if any, will be special, and which pancakes will move where. That is, every minute, you can decide to either do nothing and let the diners eat, or declare a special minute and interrupt the diners to make a single movement of one or more pancakes, as described above.<br>
<br>
Breakfast ends when there are no more pancakes left to eat. How quickly can you make that happen?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each consists of one line with&nbsp;<strong>D</strong>, the number of diners with non-empty plates, followed by another line with&nbsp;<strong>D</strong>&nbsp;space-separated integers representing the numbers of pancakes on those diners' plates.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>D</strong>&nbsp;≤ 6.</li>
<li>1 ≤&nbsp;<strong>P<sub>i</sub></strong>&nbsp;≤ 9.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the smallest number of minutes needed to finish the breakfast.</p>



## 소스코드

[소스코드 보기](Infinite%20House%20of%20Pancakes%20(Small).cpp)