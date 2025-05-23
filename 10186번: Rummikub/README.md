# 10186번: Rummikub - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10186)


<p>In the game of Rummikub® you get tiles numbered from 1-13 of four different colors (red, blue, orange, and black). The purpose of the game is to make groups or runs from your 14 tiles. Groups are 3 or 4 of a kind of different color tile, and runs are three or more consecutive tiles of the same color. The point value of a group or run is the sum of point values of the tiles. The object is to play all of your tiles. This is like the card game gin or gin rummy. What a great program to write!</p>

<p>The input will have a color character (A,B, C and D) followed by a 1-2 digit number (1-13). So, a group would look like A5, B5, C5; a run would look like A5, A6, A7.</p>

<p>For this program, consider only the following objectives:</p>

<ul>
<li>determine whether or not your hand can make groups or runs</li>
<li>determine the maximum point value of each combination</li>
</ul>

<p>For example, the following 14 tiles:</p>

<p>A5 B5 C5 A6 A7 B13 A12 C1 C9 D1 D2 D3 D7 D12</p>

<p>can have the following groups: A5 B5 C5 (15 points) or the following runs: A5 A6 A7 (18 points) and D1 D2 D3 (6 points) So the maximum point value for a group or run is 18 points.</p>



## 입력


<p>The first line consists of the number of data sets. Each data set is on one line and contains 14 strings (a character followed by a 1 or 2 digit integer). Assume the tiles will be in random order.</p>



## 출력


<p>For each data set, print out either “NO GROUPS OR RUNS” or a sorted list of the group or run with the highest point score. This sorted list should have spaces and have the points as the last item on the output line.</p>



## 소스코드

[소스코드 보기](Rummikub.cpp)