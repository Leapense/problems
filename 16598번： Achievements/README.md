# 16598번: Achievements - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16598)


<p>Did you know that Greg practices his Swedish skills every day? Well, almost every day.</p>

<p>The app that Greg uses to learn languages gives out achievement badges to keep you engaged with the app. One of the achievements is for the longest streak, i.e., the highest number of consecutive days that Greg practices Swedish. Remember that Greg does not practice every day, so there are gaps. Fortunately, the app allows him to pay for the days where he did not practice and still obtain the achievement.</p>

<p>Given the days when Greg actually practiced his Swedish and the number of days he is willing to pay for, what is the longest streak he can reach?</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with two integers n and p (1 ≤ n, p ≤ 2 · 10<sup>5</sup>), where n is the number of days Greg practiced with the app and p is the number of days that he is willing to pay for.</li>
<li>One line with n distinct integers d<sub>1</sub>, . . . , d<sub>n</sub> (0 ≤ d<sub>1</sub> &lt; d<sub>2</sub> &lt; . . . &lt; d<sub>n</sub> ≤ 10<sup>6</sup>), the days when Greg actually practiced.</li>
</ul>



## 출력


<p>Output the length of the longest streak that Greg can reach when using the paid days in an optimal way.</p>



## 소스코드

[소스코드 보기](Achievements.cpp)