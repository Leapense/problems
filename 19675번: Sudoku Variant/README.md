# 19675번: Sudoku Variant - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19675)


<p>Sudoku is a famous logic puzzle game that is played on a 9x9 grid. In it, the player is required to fill in the grid so that every row, column and 3x3 box contains the digits 1 through 9. In this problem, you will be working on a variant of this puzzle which is played on a 3x3 grid.</p>

<p>Similar to Sudoku, the 3x3 grid you are given is already partially filled with the digits 1 through 9. Your job is to fill in the remaining empty grid positions with the digits 1 through 9 such that the numbers that appear in every row and every column are distinct, i.e. a number cannot be repeated along a row or column.</p>

<p>In the given grid there are at least 1 empty grid position and at most 3 empty grid positions, you may assume that the partially filled grid is consistent with the rules, i.e. no number is duplicated on any row or column. You are required to determine the number of ways the empty positions can be filled.</p>



## 입력


<p>The input consists of 3 lines of 3 digits each, the digits are separated by a single space. Each line contains the configuration of one row of the 3x3 grid. The first line represents the first row of the grid; the second line represents the second row and so on. The digit 1 through 9 in the input indicates that the particular grid position is already filled with the digit while the digit 0 indicates that the particular position is empty</p>



## 출력


<p>Output the number of ways in which the given puzzle can be solved.</p>



## 소스코드

[소스코드 보기](Sudoku%20Variant.cpp)