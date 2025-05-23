# 16594번: A Study on Groups - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16594)


<p>You are given a bag of N integers, and you are to put these integers into M distinct groups. When you distribute the integers, you have to make sure that each integer belongs to exactly one group and the size of any two different groups differs by at most 1.</p>

<p>The cost of a group is equal to the lowest integer in that group, while the total cost of M groups simply equals to the summation of the cost of each group. Note that the cost of an empty group is zero.</p>

<p>Now, your task in this problem is to find a way to put N given integers (not necessarily unique) into M distinct groups such that the total cost of those groups is minimum. Also, find a way such that the total cost is maximum. Output only the total costs.</p>



## 입력


<p>Input begins with two integers: N M (1 ≤ N, M ≤ 100000) representing the number of given integers and the number of groups to be made, respectively. The next line contains N integers: A<sub>i</sub> (0 ≤ A<sub>i</sub> ≤ 1000000) representing the given integers.</p>



## 출력


<p>Output in a line two integers (separated by a single space) representing the minimum total cost and the maximum total cost, respectively.</p>



## 소스코드

[소스코드 보기](A%20Study%20on%20Groups.cpp)