# 7844번: Sudoku Checker - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7844)


<p>The puzzle game of <i>Sudoku</i> is played on a board of $N^2 \times N^2$ cells. The cells are grouped in $N \times N$ squares of $N \times N$ cells each. Each cell is either empty or contains a number between $1$ and $N^2$.</p>

<p>The sudoku position is <i>correct</i> when numbers in each row, each column and each square are different. The goal of the game is, starting from some correct position, fill all empty cells so that the final position is still correct.</p>

<p>This game is fairly popular in the Internet, and there are many sites which allow visitors to solve puzzles online. Such sites always have a subroutine to determine a correctness of a given position.</p>

<p>You are to write such a routine.</p>



## 입력


<p>Input file contains integer $N$, followed by $N^4$ integers -- sudoku position. Empty cells are denoted by zeroes.&nbsp;</p>



## 출력


<p>Output file must contain a single string 'CORRECT' or 'INCORRECT'.</p>



## 소스코드

[소스코드 보기](Sudoku%20Checker.cpp)