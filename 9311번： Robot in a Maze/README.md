# 9311번: Robot in a Maze - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9311)


<p>A robot is stuck in a maze with multiple exits and needs to find the shortest path out. The maze can be represented as a two dimensional grid where each space is either a wall, which the robot cannot go through, an exit, or one of the goals. The robot can only move one space at a time, and at each move it can only move either horizontally or vertically, not diagonally. It can exit the maze from any exit, but it needs to start at the specified place. What is the fewest number of moves the robot can make to exit from the maze?</p>



## 입력


<p>The input will be given first by a number that tells the number of different mazes in the input file. Following that, for each data set, there will be two integers, R and C. The first number, R, represents the number or rows in the maze, and the second number, C, representing the number of columns. The following R lines will each be a series of characters representing spaces on the grid for that row. An X will represent an obstacle, and 'O' or '0' will represent an open space that the robot can move. An S will represent the starting location of the robot. The goals in the maze will be given by the letter G. There may be more than one goal.</p>



## 출력


<p>The output should be if the robot can get out of the maze:</p>

<p>“Shortest Path: t”</p>

<p>Where t is an integer representing the length of the shortest path. If there is no way out of the maze, the output should be:</p>

<p>“No Exit”</p>

<p>Each line of output should be printed at the end of the program.</p>



## 소스코드

[소스코드 보기](Robot%20in%20a%20Maze.py)