# 16863번: Score! - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16863)


<p>Kathy is in charge of statistics for the girl’s basketball team at her high school. She meticulously records each basket made and the time it occurred. Her record book for a game might begin as follows:</p>

<pre>H 2 0:13
A 2 0:19
H 1 0:52
H 1 0:52
A 3 1:08
...</pre>

<p>This indicates that</p>

<ul>
<li>the home team (H) scored a 2-point basket 13 seconds into the game</li>
<li>the away team (A) scored a 2-point basket 6 seconds later</li>
<li>the home team made two free throws (each worth 1 point) 52 seconds into the game (recall that the clock stops when a free throw is made)</li>
<li>the away team made a three point basket 1 minute and 8 seconds into the game.</li>
</ul>

<p>The coach is very impressed with all the statistics that Kathy keeps. Using these statistics, he would like to know how long each team was in the lead during the game. For example, if both teams went into an incredible shooting slump after the 1:08 mark in the game and no more baskets were made until the end of the game (32 minutes for a high school game) then the home team would have led for 22 seconds (from 0:13 to 0:19 and from 0:52 to 1:08) and the away team would have led for 30:52 (from 1:08 to 32:00).</p>

<p>Kathy is very proud of how impressed the coach is, but she’s not looking forward to going through each game record to determine how long each team was in the lead. Can you help her?</p>



## 입력


<p>Input starts with a positive integer n indicating the number of scores in the game. Following this are n lines of the form <code>T p time</code> where <code>T</code> is either ’<code>H</code>’ or ’<code>A</code>’, <code>p</code> is the number of points scored (either 1, 2 or 3) and <code>time</code> is the time the points were scored in either the form <code>m:ss</code> (if the time is less than 10 minutes) or <code>mm:ss</code>. All times are between 0:00 and 31:59 and given in non-decreasing order.</p>



## 출력


<p>Display three things: 1) either an ’<code>H</code>’ or ’<code>A</code>’ indicating which team won the game, 2) the length of time the home team was leading, and 3) the length of time the away team was leading. Use the form <code>m:ss</code> for any time less than 10 minutes and <code>mm:ss</code> otherwise. All games will have a winner.</p>



## 소스코드

[소스코드 보기](Score!.cpp)