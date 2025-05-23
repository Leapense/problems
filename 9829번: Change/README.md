# 9829번: Change - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9829)


<p>Jack Sagert is a man on a mission. He carries a pocket full of change consisting of 5, 10, 20 and 50 cent coins, and whenever he has to pay any amount, he will choose his change so that he uses the minimum number of coins possible. This is because he feels that it is his life’s destiny to carry a lot of change everywhere and would like to spend as few of them as possible.</p>

<p>It is not known how he came to be like this. Legend has it that his mother’s gynaecologist dropped him on his head when he was born.</p>

<p>In any case, your task is to write a program such that, given the number of 5, 10, 20 and 50 cent coins in his pocket, you work out the number of coins of each denomination and the total number of coins used, such that the total number is the minimum that he can use.</p>

<p>Note that Jack won’t be able to pay any arbitrary amount of money. For example, if something costs \$2.35 and he does not have enough change, he won’t be able to pay this amount.</p>



## 입력


<p>The input (from standard input) consists of a single line of numbers, where the first four are the number of 5, 10, 20 and 50 cent coins respectively, and the fifth number is an integer representing the amount that Jack has to pay, in cents. (The number of each type of coins is smaller than 1, 000, 000 while the amount is smaller than 100, 000, 000 cents.)</p>



## 출력


<p>Your program should output (to standard output) the number of each type of coin that Jack should spend, as well as the total number of coins. Again this total should be a minimum so that Jack can retain as many coins as possible.</p>



## 소스코드

[소스코드 보기](Change.cpp)