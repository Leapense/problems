# 30137번: Find Terrorists - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30137)


<p>The Prime Minister and his Accumulated Council of Ministers (ACM) are trying hard to find all possible terrorist locations. In his dream, the Prime Minister gets a message from God suggesting that the answer to all terrorist problems are numbers (say one such number is X) such that the number of factors of X(including 1 and X) is prime. These numbers supposedly contain the encrypted locations of terrorists. Since the ACM has no programmer, the Prime Minister needs your help in finding out such numbers.</p>

<p>Note: 1 is not considered a prime number.</p>



## 입력


<p>The first line of input will contain an integer T ≤ 20 denoting the number of test cases.</p>

<p>T lines follow, one per test case. </p>

<p>Each test case will be a line formatted as "L H" where L and H are integers and 0 ≤ H ≤ 10000 </p>



## 출력


<p>Output one line per case a space separated list of all integers(sorted ascending) lying between L and H (both inclusive) such that the number of factors of each integer is prime. In case no such integer exist output -1. </p>



## 소스코드

[소스코드 보기](Main.java)