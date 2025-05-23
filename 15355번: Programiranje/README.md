# 15355번: Programiranje - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15355)


<p>Little Leticija is preparing for a programming exam. Even though she has solved a lot of tasks, there’s one still left unsolved, so she is asking you for help. You are given the word S and Q queries. In each query, you are given positive integers A, B, C and D. Let’s say that word X consists of letters between positions A and B in word S, and word Y from letters between positions C and D in word S. For each query, you must answer if it is possible to somehow rearrange the letters in word Y and obtain word X.</p>



## 입력


<p>The first line of input contains the word S (1 ≤ |S| ≤ 50 000). |S| denotes the number of characters in word S, which consists of lowercase letters of the English alphabet. The second line of input contains the positive integer Q (1 ≤ Q ≤ 50 000).</p>

<p>Each of the following Q lines contains four integers A, B, C i D (1 ≤ A ≤ B ≤ |S| and 1 ≤ C ≤ D ≤ |S|) from the task.</p>



## 출력


<p>For each query, output “DA” (Croatian for yes) if it is possible, and “NE” (Croatian for no) if it is not.</p>



## 소스코드

[소스코드 보기](Programiranje.cpp)