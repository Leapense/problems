# 32875번: Paradoks - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32875)


<p>One full moon evening, when the clock struck midnight, five friends found themselves ready to play a game as mysterious as that night.</p>

<p>They sat in a <strong>circle</strong>, in clockwise order: Igor, Lea, Marino, Sonja, and Viktor. The game consists of $N$ rounds. The first round is started by Sonja, and each subsequent round is started by the winner of the previous round.</p>

<p>Each player holds $N$ cards in their hand. All cards are colorless and have a natural number between $1$ and $9$ on them. When a player plays a card, they choose the color for that card. They may choose one of four colors (red, blue, yellow, green) provided that such a card (combination of that number and color) has not already been played in the game. In the rest of the text, the term "playing a blue card," for example, refers to the procedure of playing the card and declaring it to be blue.</p>

<p>In each round, the players, in clockwise order, play one card each until the turn reaches the player who started the round, i.e., until each player has played one card. The first card played in a round determines the so-called <em>round color</em>, and all subsequent players are required to play cards of that color. If any player fails to play a card of the current round color, it is assumed that the player has no such color card in their hand – and they are prohibited from playing that color card <strong>for the rest of the game</strong>.</p>

<p>The winner of each round is:</p>

<ul>
<li>The person who played the red card with the highest number.</li>
<li>If no red cards were played, the person who played the highest number of the round color.</li>
</ul>

<p>Sometimes, players make a move that they should not have: either they play a card that has already been played or play a card of a color they previously declared they no longer have. This play is called a <em>paradox</em> (in Croatian: "paradoks"). When a paradox occurs, the play is completely ignored in calculating the round’s winner and the rest of the game. For example, if a card is played for the first time as a paradox, for the rest of the game, it is treated as though it has not yet been played. It is guaranteed that the first player in a round will never play a paradox in that round.</p>

<p>Our heroes haven’t seen each other for a long time and haven’t been paying close attention to the game, so they ask for your help. Write a program that, for the sequentially listed played cards by round, prints how many paradoxes occurred and lists them in the order they happened. For each paradox, print the round in which it occurred and the player who caused it.</p>



## 입력


<p>The first line of input contains a natural number $N$ ($1 ≤ N ≤ 10$), the number of rounds.</p>

<p>In the next $N$ lines of input, there are $5$ words, each $2$ characters long, representing the cards played in that round, in the order they were played. (Caution: the first player in each round is not necessarily the same.)</p>

<p>The first character of each word represents the color of the card the player played and will be one of the following letters: ’<code>C</code>’ –red, ’<code>P</code>’ – blue, ’<code>Y</code>’ – yellow, ’<code>Z</code>’ – green. The second character of each word will be a natural number between $1$ and $9$ (inclusive), representing the number on the card.</p>

<p>For example, the word ’<code>Y5</code>’ would represent a yellow card with the number 5.</p>



## 출력


<p>Print a single number $a$, the number of paradoxes that occurred.</p>

<p>In next $a$ lines, for each of the $a$ paradoxes, print the round number and the name of the player who caused it, in uppercase letters.</p>

<p>Paradoxes should be printed in the order they occurred.</p>



## 소스코드

[소스코드 보기](Paradoks.cpp)