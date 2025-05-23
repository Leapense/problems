# 12721번: Mousetrap (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12721)


<p>Mousetrap is a simple card game for one player. It is played with a shuffled deck of cards numbered 1 through&nbsp;<strong>K</strong>, face down. You play by revealing the top card of the deck and then putting it on the bottom of the deck, keeping count of how many cards you have revealed. If you reveal a card whose number matches the current count, remove it from the deck and reset the count. If the count ever reaches&nbsp;<strong>K</strong>+1, you have lost. If the deck runs out of cards, you win.</p>

<p>Suppose you have a deck of 5 cards, in the order 2, 5, 3, 1, 4. You will reveal the 2 on count 1, the 5 on count 2, then the 3 on count 3. Since the value matches the count, you remove the 3 from the deck, and reset the count. You now have 4 cards left in the order 1, 4, 2, 5. You then reveal the 1 on count 1, and remove it as well (you're doing great so far!). Continuing in this way you will remove the 2, then the 4, and then finally the 5 for victory.</p>

<p>You would like to set up a deck of cards in such a way that you will win the game and remove the cards in increasing order. We'll call a deck organized in this way "perfect." For example, with 4 cards you can organize the deck as 1, 4, 2, 3, and you will win by removing the cards in the order 1, 2, 3, 4.</p>



## 입력


<p>The first line of input gives the number of cases,&nbsp;<strong>T</strong>. Each test case starts with a line containing&nbsp;<strong>K</strong>, the number of cards in a deck. The next line starts with an integer&nbsp;<strong>n</strong>, which is followed by&nbsp;<strong>n</strong>&nbsp;integers (<strong>d</strong><sub>1</sub>,<strong>d</strong><sub>2</sub>, ...), indices into the deck.</p>

<p>Limits</p>

<ul>
<li><strong>T</strong>&nbsp;= 100, 1 ≤&nbsp;<strong>K</strong>&nbsp;≤ 5000, 1 ≤&nbsp;<strong>n</strong>&nbsp;≤ 100, 1 ≤&nbsp;<strong>d</strong><sub>i</sub>&nbsp;≤&nbsp;<strong>K</strong>.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #<strong>x</strong>: " followed by&nbsp;<strong>n</strong>&nbsp;integers (<strong>k</strong><sub>1</sub>,<strong>k</strong><sub>2</sub>, ...), where&nbsp;<strong>k</strong><sub>i</sub>&nbsp;is the value of the card at index&nbsp;<strong>d</strong><sub>i</sub>&nbsp;of a perfect deck of size&nbsp;<strong>K</strong>. The numbers in the output should be separated by spaces, and there must be at least one space following the colon in each "Case #<strong>x</strong>:" line.</p>



## 소스코드

[소스코드 보기](Mousetrap%20(Small).cpp)