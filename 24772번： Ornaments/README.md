# 24772번: Ornaments - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24772)


<p><img alt="" src="https://upload.acmicpc.net/cdfa3f2e-6950-4321-b965-c49526cf4fe2/-/preview/" style="width: 159px; height: 362px; float: right;">A factory is making ornaments for the upcoming holidays. Ornaments consist of a 2D glass sphere (i.e., a circle) that is designed to hang off a hook or nail using a string that tightly wraps around the ornament, as shown in the figure to the right.</p>

<p>Your task is to write a program that calculates the length of the string, given the radius r of the circle, the distance h from the knot to the center of the circle, and some multiplier to account for the excess needed to tie the knot.</p>



## 입력


<p>The input will contain multiple test cases. Each test case contains on a single line three integer numbers r (1 ≤ r ≤ 1000), h (r ≤ h ≤ 10000), and s (0 ≤ s ≤ 100). s denotes the necessary excess string in %. The percentage is relative to what would be needed without accounting for the knot, so if s = 25, you should increment the necessary length by 1/4.</p>

<p>The input will be terminated by a line containing 3 zeros.</p>



## 출력


<p>For each test case, output the length of the needed string, rounded to two decimals.</p>



## 소스코드

[소스코드 보기](Ornaments.py)