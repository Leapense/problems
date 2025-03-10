# 12148번: Brattleship (Large) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12148)


<p>You're about to play a simplified "battleship" game with your little brother. The board for this game is a rectangular grid with&nbsp;<strong>R</strong>&nbsp;rows and&nbsp;<strong>C</strong>&nbsp;columns. At the start of the game, you will close your eyes, and you will keep them closed until the end of the game. Your little brother will take a single rectangular 1 x&nbsp;<strong>W</strong>&nbsp;ship and place it&nbsp;<strong>horizontally</strong>&nbsp;somewhere on the board. The ship must always fit entirely on the board, with each cell of the ship occupying exactly one of the grid's cells, and it can never be rotated.<br>
<br>
In each turn of the game, you name a cell on the board, and your little brother tells you whether that is a hit (one of the cells occupied by the ship) or a miss. (Your little brother doesn't say&nbsp;<em>which</em>&nbsp;part of the ship was hit -- just that the cell you named has a part of the ship in it.) You have perfect memory, and can keep track of all the information he has given you. Once you have named all of the cells occupied by the ship, the game is over (the ship is sunk), and your score is the number of turns taken. Your goal is to minimize your score.<br>
<br>
Although the ship is not supposed to be moved once it is placed, you know that your little brother, who is a brat, plans to cheat by changing the location of the ship whenever he wants, as long as the ship remains horizontal and completely on the board, and the new location is consistent with all the information he has given so far. For example, for a 1x4 board and 1x2 ship, your little brother could initially place the ship such that it overlaps the leftmost two columns. If your first guess was row 1, column 2, he could choose to secretly move the ship to the rightmost two columns, and tell you that (1, 2) was a miss. If your next guess after that was (1, 3), though, then he could not say that was also a miss and move the ship back to its original location, since that would be inconsistent with what he said about (1, 2) earlier.<br>
<br>
Not only do you know that your little brother will cheat, he knows that you know. If you both play optimally (you to minimize your score, him to maximize it), what is the lowest score that you can&nbsp;<strong>guarantee</strong>&nbsp;you will achieve, regardless of what your little brother does?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;lines follow, each with three space-separated integers&nbsp;<strong>R</strong>,&nbsp;<strong>C</strong>, and&nbsp;<strong>W</strong>: the number of rows and columns of the board, followed by the width of the ship.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>W</strong>&nbsp;≤&nbsp;<strong>C</strong>.</li>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>R</strong>&nbsp;≤ 20.</li>
<li>1 ≤&nbsp;<strong>C</strong>&nbsp;≤ 20.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum score you can guarantee.</p>



## 소스코드

[소스코드 보기](Brattleship%20(Large).cpp)