# 27703번: Divide the rectangle (Easy) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27703)

<p>Given is a rectangle consisting of r × c unit squares. One of these squares, in row r<sub>r</sub> and column c<sub>r</sub>, is colored red. A different square, in row r<sub>b</sub> and column c<sub>b</sub>, is colored blue.</p>

<p>Color each of the remaining squares red or blue in such a way that the red part and the blue part have the same shape. (That is, the set of blue squares can be obtained from the set of red squares by using shifts, rotations and reflections.)</p>

<p>A set of squares S is connected if it is possible to travel between any two of them without leaving S, using horizontal and vertical steps only.</p>

## 입력

<p>The first line of the input file contains an integer t specifying the number of test cases. Each test case is preceded by a blank line.</p>

<p>Each test case consists of three lines. The first line contains the dimensions r and c. The second line contains the coordinates r<sub>r</sub> and c<sub>r</sub>. The third line contains the coordinates r<sub>b</sub> and c<sub>b</sub>. You may assume that 1 ≤ r<sub>r</sub>,r<sub>b</sub> ≤ r ≤ 100, 1 ≤ c<sub>r</sub>,c<sub>b</sub> ≤ c ≤ 100, and (r<sub>r</sub>,c<sub>r</sub>) ≠ (r<sub>b</sub>,c<sub>b</sub>).</p>

## 출력

<p>For each test case, output r lines containing c characters each, each of the characters being R (red) or B (blue). If there are multiple solutions, pick any of them. If there is no solution, output one line with the string “IMPOSSIBLE”. You may output empty lines between test cases.</p>

## 소스코드

[소스코드 보기](Divide%20the%20rectangle%20(Easy).py)