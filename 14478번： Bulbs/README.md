# 14478번: Bulbs - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14478)


<p>Greg has an m × n grid of Sweet Lightbulbs of Pure Coolness he would like to turn on. Initially, some of the bulbs are on and some are off. Greg can toggle some bulbs by shooting his laser at them. When he shoots his laser at a bulb, it toggles that bulb between on and off. But, it also toggles every bulb directly below it, and every bulb directly to the left of it. What is the smallest number of times that Greg needs to shoot his laser to turn all the bulbs on?</p>



## 입력


<p>The first line of input contains a single integer T (1 ≤ T ≤ 10), the number of test cases. Each test case starts with a line containing two space-separated integers m and n (1 ≤ m, n ≤ 400). The next m lines each consist of a string of length n of 1s and 0s. A 1 indicates a bulb which is on, and a 0 represents a bulb which is off.</p>



## 출력


<p>For each test case, output a single line containing the minimum number of times Greg has to shoot his laser to turn on all the bulbs.</p>



## 소스코드

[소스코드 보기](Bulbs.py)