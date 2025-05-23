# 7589번: Balanced Change - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7589)


<p>When giving change to a customer in a shop, clerks are careful to hand over the minimum number of coins – so unless they have run out of coins of the appropriate denomination they will, for example, always give a customer needing \$2 in change, one \$2 coin rather than 2 \$1 coins or 4 50c coins. It might be that this is not always the best strategy however, when there is an imbalance in the stock of coins. If you have an excess of \$1 coins in the cash drawer, it might be better to give 2 \$1 coins to a customer, if only to prevent the \$1 coin bucket from overflowing. Your task is to devise and test an algorithm to decide what coins to give in change, which tries to balance the stock of coins of each denomination.&nbsp;</p>

<p>More precisely: you have a cash draw with buckets for \$2, \$1, 50c, 20c and 10c coins. We define imbalance as follows: Let min be the minimum number of coins in any bucket. Then the imbalance is the sum of the squares of the number of coins above the minimum in each bucket. If we have 2, 3, 4, 3, 5 of \$2, \$1, 50c, 20c and 10c coins respectively: the minimum is 2 and the imbalance is (2-2)<sup>2</sup> +(3-2)<sup>2</sup> +(4-2)<sup>2</sup> +(3-2)<sup>2</sup> +(5-2)<sup>2</sup> = 0 + 1 + 4 + 1 + 9 = 15. Your task is to write a program to give change in such a way as to minimize the imbalance of the cash remaining in the cash draw. If more than one way of giving cash gives the same imbalance you should use the one which gives the greater number of \$2 coins. If the number of \$2 coins is the same, then prefer the one with the largest number of \$1 coins, then 50c, etc.&nbsp;</p>



## 입력


<p>The input file contains several change giving problems. Each problem is described on one line of input by 5 integers and a dollar amount. The first 5 are the numbers of \$2, \$1, 50c, 20c, and 10c coins in the cash drawer. The dollar amount takes the form ‘\$n.m’ where n is always present, but may be zero and m is always two digits. It is the amount of change to be given. Input ends with a line holding 5 zeroes and ‘\$0.00’. The amount of change to be given is always greater than zero and never more than \$5.&nbsp;</p>



## 출력


<p>For each problem output a line with ‘Problem #n:’, followed by the number of \$2, \$1, 50c, 20c and 10c coins respectively. This should be formatted as illustrated below with correct use of commas, and the word ‘and’. If it is not possible to provide exact change, output ‘not possible’.&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)