# 16103번: Drawn and Quartered - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16103)


<p>You are playing a game which involves drawing and redrawing a string on a blackboard. You start with a string S of length N and perform a switcheroo on the string exactly K times. A switcheroo involves breaking S into quarters, and then moving the middle two quarters to the end of S without changing their relative order to each other. For example, say you start with aabbccdd. After a single switcheroo, the string would become aaddbbcc. After another switcheroo, you would have aaccddbb, and so on.</p>

<p>Given some starting string S and the number of times you should perform a switcheroo, what is the final state of the string?</p>



## 입력


<p>The input starts with a line containing two integers N (4 ≤ N ≤ 100 000), which is the length of the string, and K (1 ≤ K ≤ 10<sup>18</sup>), which is the number of times you should perform a switcheroo to S. It is guaranteed that N is a multiple of 4.</p>

<p>The second line contains S. The string S contains only lowercase letters and consists of exactly N characters.</p>



## 출력


<p>Display the string after performing K switcheroos.</p>



## 소스코드

[소스코드 보기](Drawn%20and%20Quartered.py)