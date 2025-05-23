# 23917번: ATM Queue - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23917)


<p>There are&nbsp;<b>N</b>&nbsp;people numbered from 1 to&nbsp;<b>N</b>, standing in a queue to withdraw money from an ATM. The queue is formed in ascending order of their number. The person numbered&nbsp;<b>i</b>&nbsp;wants to withdraw amount&nbsp;<b>A<sub>i</sub></b>. The maximum amount a person can withdraw at a time is&nbsp;<b>X</b>. If they need more money than&nbsp;<b>X</b>, they need to go stand at the end of the queue and wait for their turn in line. A person leaves the queue once they have withdrawn the required amount.</p>

<p>You need to find the order in which all the people leave the queue.</p>



## 입력


<p>The first line of the input gives the number of test cases&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow.</p>

<p>The first line of each test case gives two space separated integers: the number of people standing in the queue,&nbsp;<b>N</b>&nbsp;and the maximum amount&nbsp;<b>X</b>&nbsp;that can be withdrawn in one turn.</p>

<p>The next line contains&nbsp;<b>N</b>&nbsp;space separated integers&nbsp;<b>A<sub>i</sub></b>.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the space separated list of integers that denote the order in which the people leave the queue.</p>



## 소스코드

[소스코드 보기](ATM%20Queue.py)