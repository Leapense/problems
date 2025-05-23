# 31377번: Child's Game with Robot - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31377)


<p><em>This is an interactive problem.</em></p>

<p>Little Misha plays a child's game with a robot. In this game, the robot stands on a field which is divided into $3 \times 3$ squares and surrounded by borders. The game begins at the center squares and consists in making ten actions. Each action is either declamation of a phrase or an attempt to move into one of the neighboring squares. Declamation is used to wait, or simply for amusement.</p>

<p>One of the squares is special, but Misha does not know in advance which one. The robot reports when it moves into the special square. The goal of the game is to move into the special square precisely during the tenth action.</p>

<p>To communicate with the robot, Misha uses text input and output. The following commands are recognized:</p>

<ul>
<li><code>echo </code><em>phrase</em>  --- declamation of <em>phrase</em>,</li>
<li><code>move north</code>  --- moving one square to the north,</li>
<li><code>move east</code>  --- moving one square to the east,</li>
<li><code>move south</code>  --- moving one square to the south,</li>
<li><code>move west</code>  --- moving one square to the west.</li>
</ul>

<p>For each declamation command, the robot loudly reads the given phrase, and also prints it back in text. During a declamation, the robot does not move. The robot is guaranteed to correctly handle phrases which consist of characters with ASCII codes from $32$ to $126$ inclusive and are at most $256$ characters long.</p>

<p>For each movement command, the robot prints back one of the four words:</p>

<ul>
<li><code>bump</code> if instead of moving, the robot hit a barrier, in which case, it remains on the same square,</li>
<li><code>moved</code> if the robot successfully moved into a common square,</li>
<li><code>found</code> if the robot moved into the special square during one of the first nine actions,</li>
<li><code>win</code> if the robot moved into the special square during the tenth action.</li>
</ul>

<p>Help Misha to play this game in such a way that, during the tenth action, the robot prints the desired word <code>win</code>.</p>



## 입력





## 출력





## 소스코드

[소스코드 보기](Child's%20Game%20with%20Robot.cpp)