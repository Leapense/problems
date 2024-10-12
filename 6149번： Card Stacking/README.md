# 6149번: Card Stacking - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6149)


<p>Bessie is playing a card game with her N-1 (2 &lt;= N &lt;= 100) cow friends using a deck with K (N &lt;= K &lt;= 100,000; K is a multiple of N) cards. &nbsp;The deck contains M = K/N "good" cards and K-M "bad" cards. Bessie is the dealer and, naturally, wants to deal herself all of the "good" cards. She loves winning.</p>

<p>Her friends suspect that she will cheat, though, so they devise a dealing system in an attempt to prevent Bessie from cheating. They tell her to deal as follows:</p>

<ol>
<li>Start by dealing the card on the top of the deck to the cow to her right</li>
<li>Every time she deals a card, she must place the next P (1 &lt;= P &lt;= 10) cards on the bottom of the deck; and</li>
<li>Continue dealing in this manner to each player sequentially in a counterclockwise manner</li>
</ol>

<p>Bessie, desperate to win, asks you to help her figure out where she should put the "good" cards so that she gets all of them. Notationally, the top card is card #1, next card is #2, and so on.</p>



## 입력


<ul>
<li>Line 1: Three space-separated integers: N, K, and P</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Lines 1..M: Positions from top in ascending order in which Bessie should place "good" cards, such that when dealt, Bessie will obtain all good cards.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Card%20Stacking.cpp)