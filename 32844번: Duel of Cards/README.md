# 32844번: Duel of Cards - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32844)


<p>Alice and Bob are playing a card game. There are $2n$ cards uniquely numbered from $1$ to $2n$. The cards are shuffled and dealt to the two players so that each player gets $n$ cards. Each player then arranges the cards they get into a deck in any order that they choose, facing down.</p>

<p>The game has $n$ turns. In each turn, both players reveal the card that is on the top of their deck and compare the numbers on the two cards. The player with the larger card wins and scores one point. This is repeated until all cards in the decks are compared.</p>

<p>After getting her $n$ cards, Alice wonders what is the minimum and maximum number of points she may possibly score in the game.</p>



## 입력


<p>The first line of input contains a single integer $n$ ($1 ≤ n ≤ 1\, 000$), the number of cards that Alice gets.</p>

<p>The next $n$ lines each have a single integer between $1$ and $2n$ (both inclusive) giving a card that is dealt to Alice. It is guaranteed that all those cards are unique.</p>



## 출력


<p>Output two integers, the minimum and maximum number of points Alice may score.</p>



## 소스코드

[소스코드 보기](Duel%20of%20Cards.cpp)