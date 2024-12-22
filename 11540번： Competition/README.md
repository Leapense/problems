# 11540번: Competition - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11540)


<p>Bob and Alice are participating in a programming contest as a team.</p>

<p>The contest has N problems which must be solved in order. Naturally there are some problems that they cannot solve, in that case they can skip it. There may be also problems that only Bob or Alice alone can solve.</p>

<p>They want to solve all the problems possible switching as few times as possible who is at the computer programming the solution.</p>

<p>Given the number of problems and the problems that Bob and Alice can solve, calculate the minimum number of switches between the usage of the computer. Anyone can start using it.</p>



## 입력


<p>The first line contains three integers N (1 ≤ N ≤ 10<sup>9</sup>), A (1 ≤ A ≤ min(N, 5 ∗ 10<sup>4</sup>)) and B (1 ≤ B ≤ min(N, 5 ∗ 10<sup>4</sup>)). The next line contains A unique integers denoting the problems Alice can solve. The following line contains B unique integers denoting the problems Bob can solve. The first problem is denoted by the number 1, the second by number 2, the N-th by N, and so on.</p>



## 출력


<p>Print the minimum number of switches between the usage of the computer.</p>



## 소스코드

[소스코드 보기](Competition.py)