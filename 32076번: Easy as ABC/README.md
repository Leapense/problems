# 32076번: Easy as ABC - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32076)


<p>You are playing a word puzzle. The puzzle starts with a $3$ by $3$ grid, where each cell contains either the letter <code>A</code>, <code>B</code>, or <code>C</code>.</p>

<p>The goal of this puzzle is to find the lexicographically smallest possible word of length $3$. The word can be formed by choosing three different cells where the cell containing the first letter is adjacent to the cell containing the second letter, and the cell containing the second letter is adjacent to the cell containing the third letter.</p>

<p>Two cells are adjacent to each other if they share a border or a corner, as shown in the following illustration. Formally, if $(r, c)$ denotes the cell in the $r$<sup>th</sup> row and $c$<sup>th</sup> column, then cell $(r, c)$ is adjacent to cell $(r, c + 1)$, $(r - 1, c + 1)$, $(r - 1, c)$, $(r - 1, c - 1)$, $(r, c - 1)$, $(r + 1, c - 1)$, $(r + 1, c)$, and $(r + 1, c + 1)$.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8c527d51-4c91-4782-8520-8dcba14bdfd7/-/preview/" style="width: 122px; height: 122px;"></p>

<p>Determine the lexicographically smallest possible word of length $3$ that you can find within the grid.</p>

<p>A string $s$ of length $n$ is lexicographically smaller than string $t$ of the same length if there exists an integer $1 ≤ i ≤ n$ such that $s_j = t_j$ for all $1 ≤ j &lt; i$, and $s_i &lt; t_i$ in alphabetical order. The following illustration shows some examples on some grids and their the lexicographically smallest possible word of length $3$ that you can find within the grids.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/19860b6d-9982-4172-ad19-e662c191d542/-/preview/" style="width: 691px; height: 122px;"></p>



## 입력


<p>Input consists of three lines, each containing three letters, representing the puzzle grid. Each letter in the grid can only be either <code>A</code>, <code>B</code>, or <code>C</code>.</p>



## 출력


<p>Output the lexicographically smallest possible word of length $3$ that you can find within the grid.</p>



## 소스코드

[소스코드 보기](Easy%20as%20ABC.cpp)