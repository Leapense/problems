# 4863번: Suit Distribution - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4863)


<p>Bridge is a 4-player (two teams of two) card game with many complicated conventions that even experienced players have difficulty keeping track of. Fortunately, we are not interested in these conventions for this problem. In fact, it is not even important if you understand how to play the game.</p>

<p>What is important to know is that the way the cards are distributed among your two opponents often determine whether you will be successful in your game. For example, suppose you and your partner hold 8 spades. The remaining 5 spades are held by your opponents (since there are 13 cards in each suit) and can be distributed in the following ways: 0-5, 1-4, 2-3. Notice that a 0-5 "split" can be realized in two ways---opponent 1 has no spade and opponent 2 has 5 spades, or vice versa.</p>

<p>Good bridge players know that the best line of play often depends on the distribution. Sometimes good players can "read their opponents' cards" and determine the distribution, but sometimes even good players have to guess. In those cases, knowing the probability of the different distributions would be useful in making an educated guess.</p>

<p>You can assume that the 52 cards in a deck are dealt out randomly to 4 players, so that every player has 13 cards, and that you know which 26 cards your team holds.</p>



## 입력


<p>The input consists of a number of cases. Each case consists of two integers&nbsp;<em>a, b</em>&nbsp;(0 &lt;=&nbsp;<em>a, b</em>&nbsp;&lt;= 13,&nbsp;<em>a</em>&nbsp;+&nbsp;<em>b</em>&nbsp;&lt;= 13). The input is terminated by&nbsp;<em>a = b = -1</em>.</p>



## 출력


<p>For each case, print the probability of a split of&nbsp;<em>a+b</em>&nbsp;cards so that one opponent has&nbsp;<em>a</em>&nbsp;cards and the other has&nbsp;<em>b</em>&nbsp;cards in the format as shown in the sample output. You may assume that the remaining cards in the suit are held by you and your partner. Output the probabilities to 8 decimal places.</p>



## 소스코드

[소스코드 보기](Suit%20Distribution.cpp)