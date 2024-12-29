# 13360번: Game Rank - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13360)


<p>The gaming company Sandstorm is developing an online&nbsp;two player game. You have been asked to implement&nbsp;the ranking system. All players have a rank determining&nbsp;their playing strength which gets updated after every game&nbsp;played. There are 25 regular ranks, and an extra rank,&nbsp;“Legend”, above that. The ranks are numbered in decreasing&nbsp;order, 25 being the lowest rank, 1 the second highest&nbsp;rank, and Legend the highest rank.</p>

<p>Each rank has a certain number of “stars” that one&nbsp;needs to gain before advancing to the next rank. If a player&nbsp;wins a game, she gains a star. If before the game the&nbsp;player was on rank 6-25, and this was the third or more&nbsp;consecutive win, she gains an additional bonus star for that&nbsp;win. When she has all the stars for her rank (see list below)&nbsp;and gains another star, she will instead gain one rank and have one star on the new rank.</p>

<p>For instance, if before a winning game the player had all the stars on her current rank, she&nbsp;will after the game have gained one rank and have 1 or 2 stars (depending on whether she got a&nbsp;bonus star) on the new rank. If on the other hand she had all stars except one on a rank, and won&nbsp;a game that also gave her a bonus star, she would gain one rank and have 1 star on the new rank.</p>

<p>If a player on rank 1-20 loses a game, she loses a star. If a player has zero stars on a rank&nbsp;and loses a star, she will lose a rank and have all stars minus one on the rank below. However,&nbsp;one can never drop below rank 20 (losing a game at rank 20 with no stars will have no effect).</p>

<p>If a player reaches the Legend rank, she will stay legend no matter how many losses she&nbsp;incurs afterwards.</p>

<p>The number of stars on each rank are as follows:</p>

<ul>
<li>Rank 25-21: 2 stars</li>
<li>Rank 20-16: 3 stars</li>
<li>Rank 15-11: 4 stars</li>
<li>Rank 10-1: 5 stars</li>
</ul>

<p>A player starts at rank 25 with no stars. Given the match history of a player, what is her rank&nbsp;at the end of the sequence of matches?</p>



## 입력


<p>The input consists of a single line describing the sequence of matches. Each character corresponds&nbsp;to one game; ‘W’ represents a win and ‘L’ a loss. The length of the line is between 1 and&nbsp;10 000 characters (inclusive).</p>



## 출력


<p>Output a single line containing a rank after having played the given sequence of games; either&nbsp;an integer between 1 and 25 or “Legend”.</p>



## 소스코드

[소스코드 보기](Game%20Rank.py)