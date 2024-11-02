# 20244번: Mind the Gap

## 문제 설명


<p>Mika is playing the Mind game with her friends.&nbsp;</p>

<p>The game is played with cards, a single integer value is written on each card. All values written on the cards are distinct. Players keep playing cards, building a single pile of cards on the table. Initially the pile contains a single card with integer $0$ on it. Each player is given a single card with a value from $1$ to $10^9$. Then players start playing the cards in any order. When a player plays a card, they place it on the top of the pile. The goal is to play all the cards in such a way that the card values increase from the bottom to the top. If any player didn't play their card or the pile is not increasing, the players lose, otherwise they win. No communication between players is allowed after the cards are distributed.</p>

<p>Mika and her friends came up with a strategy. They agree on a single integer $d$ before the game. During the game, if a player's card value is $x$, and the top value of the pile is $y$, such that $x - y \le d$, then the player plays their card. If $x - y &gt; d$, the player doesn't play their card. If several players play their cards at the same time, these cards might be placed on the top of the pile in any order, and this order is not controlled by the players.</p>

<p>You are given the card values that are going to be distributed to the players. Your task is to find an integer $d$ for the players' strategy that guarantees them a win.</p>



## 입력 형식


<p>The first line contains an integer $n$ --- the number of players playing the Mind game ($3 \le n \le 100\,000$).</p>

<p>The second line contains $n$ integers --- the card values distributed to the players.</p>

<p>All given card values are distinct, positive and don't exceed $10^9$.</p>



## 출력 형식


<p>Print a single integer $d$ that Mika and her friends should use to guarantee a win in the game using their strategy. If no such $d$ exists, print $0$. If several values of $d$ exist, print any of them.</p>



## 예제

### 예제 입력 1

```
5
5 13 2 10 8

```

### 예제 출력 1

```
4

```
          

### 예제 입력 2

```
5
4 13 2 8 7

```

### 예제 출력 2

```
0

```
          




## 추가 테스트 케이스

추가로 테스트 하고 싶은 케이스를 적고 정리해 보세요.

### 추가 입력 1

```
<입력값>
```

### 추가 출력 1

```
<출력값>
```

### 추가 입력 2

```
<입력값>
```

### 추가 출력 2

```
<출력값>
```
  