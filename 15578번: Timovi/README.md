# 15578번: Timovi - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15578)


<p>We need to arrange M kids in N teams. We begin by placing K kids in each team, starting from the first to the N<sup>th</sup> team. When we finish with the N<sup>th</sup> team, we switch directions and continue, placing K kids in each team, from the (N-1)<sup>th</sup> to the first team, respectively. When we finish with the first team, we switch directions again and continue the process from the second to the N<sup>th</sup> team, respectively, and so on until there are no kids left to distribute. For example, if we have three teams, we will place K kids in teams in the following order: first team, second team, third team, second team, first team, second team, etc.</p>

<p>If, at any points, there are less than K kids left to place in the current team, we place all the remaining kids in that team and end the process.</p>

<p>Output the number of kids in each team when the process ends.</p>



## 입력


<p>The first line of input contains the integers N (2 ≤ N ≤ 200 000), K and M (1 ≤ K ≤ M ≤ 2 000 000 000) from the task.</p>



## 출력


<p>In a single line, output the number of kids in each of the N teams, respectively from the first to the N<sup>th</sup> team.</p>



## 소스코드

[소스코드 보기](Timovi.cpp)