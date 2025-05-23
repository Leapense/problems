# 26462번: 1-Player Concentration - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26462)


<p>You got $HW$ cards, where $HW$ is even. Each card has a number $1$ through $HW/2$ on the face, and exactly two cards have the same number. You considered what types of card games you could play with the cards, and decided to play 1-player concentration.</p>

<p>In the 1-player concentration, you first align $HW$ cards face down on the $H \times W$ rectangle field. Your goal is to remove all the cards from the field by repeating turns. For each turn, you must flip exactly two cards. If the two flipped cards have the same number on the face, you remove the two cards from the field. If not, you flip the two cards again to make them face down. But because you have perfect memory, you can remember which card has which number and where it's placed if you flipped the card once. So for each turn, you will act as follows.</p>

<ol>
<li>If it's the second or later turn and you already know where two cards having the same number are placed according to previous turns, flip the two cards and remove them from the field.</li>
<li>If not, flip a card you haven't flipped yet and with the highest precedence (We define the precedence of cards later). If you have seen the number on the card on another already flipped card, flip the other card and remove the two cards from the field.</li>
<li>If not, flip another card you haven't flipped yet and with the highest precedence. If the first and the second cards you flipped in this turn (luckily) have the same number, remove the two cards from the field.</li>
<li>If not, make the two flipped cards face down to prepare for the next turn.</li>
</ol>

<p>Let's number the rows $1$ through $H$ from the top. The card at the topmost row among the remaining cards has the highest precedence. If there are multiple cards at the topmost row, if the row is initially an odd-numbered row, the leftmost card has the highest precedence. If the row is initially an even-numbered row, the rightmost card has the highest precedence.</p>

<p>After you played the game, you noticed you forgot to count how many turns you took to remove all the cards from the field. Fortunately, you remember the initial placement of the cards. So you decided to write a program to compute the turns you take to remove all the cards for a given initial placement.</p>



## 입력


<p>The first line contains two integers $H$ ($1 ≤ H ≤ 100$) and $W$ ($1 ≤ W ≤ 100$). You can assume $H \times W$ is even. Each of the following $H$ lines has exactly $W$ integers. The $j$-th integer of the $i$-th row represents the number on the face of a card at the $i$-th from the top and the $j$-th from the left. You can assume all the integers in the $H$ lines are no less than $1$, no more than $HW/2$, and the same integer appears exactly twice.</p>



## 출력


<p>Output in a line a single integer, which is the number of turns you take to remove all the cards.</p>



## 소스코드

[소스코드 보기](1-Player%20Concentration.cpp)