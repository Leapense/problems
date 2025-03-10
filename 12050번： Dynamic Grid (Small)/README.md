# 12050번: Dynamic Grid (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12050)


<p>We have a grid with&nbsp;<strong>R</strong>&nbsp;rows and&nbsp;<strong>C</strong>&nbsp;columns in which every entry is either 0 or 1. We are going to perform&nbsp;<strong>N</strong>&nbsp;operations on the grid, each of which is one of the following:</p>

<ul>
<li>Operation M: Change a number in one cell of the grid to 0 or 1</li>
<li>Operation Q: Determine the number of different&nbsp;<em>connected regions</em>&nbsp;of 1s. A connected region of 1s is a subset of cells that are all 1, in which any cell in the region can be reached from any other cell in the region by traveling between cells along edges (<strong>not</strong>&nbsp;corners).</li>
</ul>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;T.&nbsp;T&nbsp;test cases follow. Each test case starts with one line with two integers,&nbsp;R&nbsp;and&nbsp;C, which represent the number of rows and columns in the grid. Then, there are&nbsp;R&nbsp;lines of&nbsp;C&nbsp;characters each, in which every character is either&nbsp;0&nbsp;or&nbsp;1. These lines represent the initial state of the grid.</p>

<p>The next line has one integer,&nbsp;N, the number of operations to perform on the grid.&nbsp;N&nbsp;more lines follow; each has one operation. All operation Ms will be of the form&nbsp;M x y z, meaning that the cell at row x and column y should be changed to the value z. All operation Qs will be of the form&nbsp;Q.</p>



## 출력


<p>For each test case, output one line containing "Case #x:", where x is the test case number (starting from 1). Then, for every operation Q in the test case, in order, output one line containing the number of connected regions of 1s.</p>



## 소스코드

[소스코드 보기](Dynamic%20Grid%20(Small).py)