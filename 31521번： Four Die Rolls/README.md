# 31521번: Four Die Rolls - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31521)


<p>Ashley and Brandon are playing a game where they roll a six-sided dice four times. Each integer from $1$ to $6$ is on one face of the dice and all values are equally likely to appear. Each time they roll the dice, they write down the value that shows on the top face of the dice, eventually forming a four-digit integer.</p>

<p>Ashley wins if all four digits in the integers are different. Otherwise, Brandon wins.</p>

<p>The dice has been rolled from $1$ to $3$ times so far. Compute the number of different ways to roll the remaining times such that Ashley wins, and the number of different ways to roll the remaining dice such that Brandon wins. Two ways are different if the integers formed are different - for example, rolling a $1$, then a $2$, then a $3$, then a $4$ forms the integer $1234$, and is different from rolling a $1$, then a $2$, then a $4$, then a $3$, which would form the integer $1243$.</p>



## 입력


<p>The first line contains $n$ ($1 \le n \le 3$), which is the number of times the dice have been rolled so far.</p>

<p>The next line contains $n$ integers ranging from $1$ to $6$, which are the first $n$ rolls of the dice in order.</p>



## 출력


<p>Output two space-separated integers on one line, which are the number of ways to roll the remaining times such that Ashley wins, and the number of ways to roll the remaining dice such that Brandon wins.</p>



## 소스코드

[소스코드 보기](Four%20Die%20Rolls.cpp)