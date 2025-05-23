# 14789번: Oversized Pancake Flipper (Large) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14789)


<p>Last year, the Infinite House of Pancakes introduced a new kind of pancake. It has a happy face made of chocolate chips on one side (the "happy side"), and nothing on the other side (the "blank side").</p>

<p>You are the head cook on duty. The pancakes are cooked in a single row over a hot surface. As part of its infinite efforts to maximize efficiency, the House has recently given you an oversized pancake flipper that flips exactly&nbsp;<strong>K</strong>&nbsp;consecutive pancakes. That is, in that range of&nbsp;<strong>K</strong>&nbsp;pancakes, it changes every happy-side pancake to a blank-side pancake, and vice versa; it does&nbsp;<em>not</em>&nbsp;change the left-to-right order of those pancakes.</p>

<p>You cannot flip fewer than&nbsp;<strong>K</strong>&nbsp;pancakes at a time with the flipper, even at the ends of the row (since there are raised borders on both sides of the cooking surface). For example, you can flip the first&nbsp;<strong>K</strong>&nbsp;pancakes, but not the first&nbsp;<strong>K</strong>&nbsp;- 1 pancakes.</p>

<p>Your apprentice cook, who is still learning the job, just used the old-fashioned single-pancake flipper to flip some individual pancakes and then ran to the restroom with it, right before the time when customers come to visit the kitchen. You only have the oversized pancake flipper left, and you need to use it quickly to leave all the cooking pancakes happy side up, so that the customers leave feeling happy with their visit.</p>

<p>Given the current state of the pancakes, calculate the minimum number of uses of the oversized pancake flipper needed to leave all pancakes happy side up, or state that there is no way to do it.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each consists of one line with a string&nbsp;<strong>S</strong>&nbsp;and an integer&nbsp;<strong>K</strong>.&nbsp;<strong>S</strong>&nbsp;represents the row of pancakes: each of its characters is either&nbsp;<code>+</code>&nbsp;(which represents a pancake that is initially happy side up) or&nbsp;<code>-</code>&nbsp;(which represents a pancake that is initially blank side up).</p>

<p>Limits</p>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>Every character in&nbsp;<strong>S</strong>&nbsp;is either&nbsp;<code>+</code>&nbsp;or&nbsp;<code>-</code>.</li>
<li>2 ≤&nbsp;<strong>K</strong>&nbsp;≤ length of&nbsp;<strong>S</strong>.</li>
<li>2 ≤ length of&nbsp;<strong>S</strong>&nbsp;≤ 1000.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is either&nbsp;<code>IMPOSSIBLE</code>&nbsp;if there is no way to get all the pancakes happy side up, or an integer representing the the minimum number of times you will need to use the oversized pancake flipper to do it.</p>



## 소스코드

[소스코드 보기](Main.java)