# 11326번: Coverity Crossword - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11326)


<p>What is your crossword telling you today? Can you scan your code for patterns, in the time it takes to get a cup of coffee? You have just landed a job at Coverity, and your first challenge is to demonstrate your searching and testing abilities. Can you find and analyze code that looks like random strings? Up to ten secret messages are hidden in a crossword of size 8x8, and your task is to determine if they are all present in the code or not.</p>

<p>Secrets are hidden horizontally, from left to right, vertically, from top to bottom, and diagonally, from top-left to bottom-right.</p>



## 입력


<p>The first line of the input contains an integer&nbsp;<strong>T</strong>&nbsp;(1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100), the number of test cases. Then follow&nbsp;<strong>T</strong>&nbsp;test cases. Each case starts with an integer&nbsp;<strong>N</strong>&nbsp;on a line (1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10), the number of words we are searching for. Each of the next&nbsp;<strong>N</strong>&nbsp;lines contains a non-empty string of length at most 8 characters over the alphabet [A-Z], the words we are searching for. Then follows 8 lines, each containing a string of exactly 8 characters over the alphabet [A-Z], the<strong>i</strong>'th horizontal line in the crossword, from left to right, starting from the topmost line down to the bottommost line.</p>



## 출력


<p>For each test case print on a separate line either "Yes" or "No", the answer to the question "Is it the case that all&nbsp;<strong>N</strong>&nbsp;messages are present in the crossword?"</p>



## 소스코드

[소스코드 보기](Coverity%20Crossword.cpp)